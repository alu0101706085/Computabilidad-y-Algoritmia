// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 18/10/2025
// Archivo simulador.cc: Programa encargado de leer un fichero .txt con cadenas
// cualquiera y comprobar si esas cadenas son aceptadas o no por el autómata
// definido.
// Referencias:
// https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#include "../include/simulador.h"

#include <iostream>
#include <fstream>

#include "../include/estado.h"
#include "../include/estructura.h"

/**
 * @brief Ejecuta el simulador de autómatas con las cadenas del fichero indicado.
 *
 * Lee un archivo de texto línea por línea y determina si cada cadena es
 * aceptada o rechazada por el autómata definido en la estructura.
 *
 * @param FicheroDeEntrada Nombre del fichero que contiene las cadenas de entrada.
 * @param estructura Objeto que representa la estructura del autómata (alfabeto, estados, transiciones, etc.).
 */
void Simulador::RealizarSimulador(const std::string& FicheroDeEntrada,
                                  Estructura estructura) {
  std::ifstream FicheroLectura(FicheroDeEntrada);
  if (!FicheroLectura) {
    std::cerr << "Error, no se pudo abrir el fichero de entrada" << std::endl;
    return;
  }

  std::string cadena;
  while (FicheroLectura >> cadena) {
    MostrarResultado(cadena, estructura);
  }
  FicheroLectura.close();
}

/**
 * @brief Muestra por pantalla el resultado de analizar una cadena.
 *
 * Determina si la cadena es aceptada por el autómata y muestra el resultado
 * en formato: "cadena --- Accepted" o "cadena --- Rejected"
 *
 * @param cadena Cadena que se desea evaluar.
 * @param estructura Referencia a la estructura del autómata.
 */
void Simulador::MostrarResultado(const std::string& cadena,
                                 Estructura& estructura) {
  bool aceptada = AnalizarCadena(cadena, estructura);
  std::cout << cadena << " --- " << (aceptada ? "Accepted" : "Rejected")
            << std::endl;
}

/**
 * @brief Analiza una cadena para determinar si es aceptada por el autómata.
 *
 * Recorre los estados del autómata según las transiciones definidas,
 * comenzando desde el estado inicial y verificando si alguno de los estados
 * finales es alcanzado al consumir toda la cadena.
 *
 * @param cadena Cadena de entrada a evaluar.
 * @param estructura Referencia a la estructura del autómata.
 * @return true Si la cadena es aceptada.
 * @return false Si la cadena es rechazada.
 */
bool Simulador::AnalizarCadena(const std::string& cadena,
                               Estructura& estructura) {
  bool es_aceptado{false};

  // Estado inicial completo con sus transiciones
  Estado estado_inicio =
      estructura.GetEstadoEspecifico(estructura.GetEstadoArranque().GetIdentificador());
  std::set<Estado> estados_actuales = {estado_inicio};

  for (char c : cadena) {
    if (!VerificarValorTransicion(c, estructura)) {
      std::cerr << "Error, el valor de transición no pertenece al alfabeto"
                << std::endl;
      break;
    }

    estados_actuales = AvanzarEstado(estados_actuales, c, estructura);

    if (estados_actuales.empty()) {
      es_aceptado = false;
    }
  }

  // Verifica si alguno de los estados actuales es de aceptación
  for (const Estado& estado : estados_actuales) {
    if (estado.EsFinal()) {
      es_aceptado = true;
      break;
    }
  }

  return es_aceptado;
}

/**
 * @brief Avanza los estados actuales según el símbolo leído.
 *
 * Para cada estado actual, se buscan transiciones cuyo símbolo coincida
 * con el recibido. Los estados destino de dichas transiciones se añaden al
 * nuevo conjunto de estados.
 *
 * @param cadena_estados Conjunto de estados actuales.
 * @param simbolo Símbolo de entrada actual.
 * @param estructura Referencia a la estructura del autómata.
 * @return Conjunto de estados alcanzables tras consumir el símbolo.
 */
std::set<Estado> Simulador::AvanzarEstado(
    const std::set<Estado>& cadena_estados, char simbolo,
    Estructura& estructura) {
  std::set<Estado> estados_siguientes;

  for (const auto& estado : cadena_estados) {
    for (const auto& transicion : estado.GetSetTransiciones()) {
      if (transicion.GetValorTransicion() == simbolo) {
        Estado destino =
            estructura.GetEstadoEspecifico(transicion.GetDestino());
        estados_siguientes.insert(destino);
      }
    }
  }
  return estados_siguientes;
}

/**
 * @brief Comprueba si un símbolo pertenece al alfabeto del autómata.
 *
 * @param simbolo Símbolo que se desea verificar.
 * @param estructura Estructura del autómata.
 * @return true Si el símbolo pertenece al alfabeto.
 * @return false Si el símbolo no pertenece al alfabeto.
 */
bool Simulador::VerificarValorTransicion(const char simbolo,
                                         const Estructura& estructura) {
  std::set<char> alfabeto = estructura.GetAlfabeto();
  return alfabeto.find(simbolo) != alfabeto.end();
}
