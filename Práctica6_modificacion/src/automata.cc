// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 18/10/2025
// Archivo automata.cc: Programa encargado de leer un fichero .fa que
// define un autómata finito y configurar su comportamiento, almacenando sus
// valores en la estructura correspondiente.
// Referencias:
// https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#include "../include/automata.h"

#include <fstream>
#include <iostream>
#include <string>

#include "../include/estructura.h"
#include "../include/transicion.h"

/**
 * @brief Define un autómata a partir del contenido de un archivo .fa.
 *
 * El método lee un fichero que describe un autómata finito (alfabeto, número
 * de estados, estado inicial, estados de aceptación y sus transiciones)
 * y carga esta información en la estructura interna del programa.
 *
 * @param FicheroDeEntrada Nombre del fichero .fa que contiene la descripción
 * del autómata.
 * @param estructura Objeto Estructura donde se almacenará la información del
 * autómata.
 */
void Automata::DefinirAutomata(const std::string& FicheroDeEntrada,
                               Estructura& estructura) {
  std::ifstream FicheroLectura(FicheroDeEntrada);
  if (!FicheroLectura) {
    std::cerr << "Error, no se pudo abrir el fichero de entrada" << std::endl;
    return;
  }
  DetectarAlfabeto(FicheroLectura, estructura);
  DetectarTotalEstadosYEstadoInicial(FicheroLectura, estructura);
  DetectarEstados(FicheroLectura, estructura);
  FicheroLectura.close();
}

/**
 * @brief Detecta y carga el alfabeto del autómata desde el fichero.
 *
 * Lee la primera línea del fichero y añade los símbolos válidos al alfabeto.
 * Ignora espacios y saltos de línea. Si se encuentra el símbolo '&', se
 * muestra un mensaje de error.
 *
 * @param FicheroLectura Flujo de entrada del fichero .fa.
 * @param estructura Referencia a la estructura donde se guardará el alfabeto.
 */
void Automata::DetectarAlfabeto(std::ifstream& FicheroLectura,
                                Estructura& estructura) {
  std::string linea;
  std::getline(FicheroLectura, linea);
  for (char simbolo : linea) {
    if (simbolo == '&') {
      std::cerr << "El alfabeto no puede definirse con una cadena vacía"
                << std::endl;
      break;
    } else if (simbolo != ' ' && simbolo != '\n') {
      estructura.AddCaracterAlfabeto(simbolo);
    }
  }
}

/**
 * @brief Detecta el número total de estados y el estado inicial del autómata.
 *
 * Lee del fichero los valores correspondientes al número de estados totales
 * y al identificador del estado de arranque, almacenándolos en la estructura.
 *
 * @param FicheroLectura Flujo de entrada del fichero .fa.
 * @param estructura Referencia a la estructura donde se guardarán los datos.
 */
void Automata::DetectarTotalEstadosYEstadoInicial(std::ifstream& FicheroLectura,
                                                  Estructura& estructura) {
  unsigned numero_total_estados{0};
  unsigned identificador_estado_inicial;
  FicheroLectura >> numero_total_estados;
  estructura.SetNumeroTotalEstados(numero_total_estados);
  FicheroLectura >> identificador_estado_inicial;
  Estado estado_inicial;
  estado_inicial.SetIdentificador(identificador_estado_inicial);
  estructura.SetEstadoArranque(estado_inicial);
}

/**
 * @brief Detecta los estados, sus transiciones y si son de aceptación.
 *
 * Recorre las líneas restantes del fichero y, para cada estado, lee su
 * identificador, marca de aceptación, número de transiciones, y las
 * transiciones correspondientes (símbolo y destino).
 *
 * Todos los estados procesados se almacenan en la estructura del autómata.
 *
 * @param FicheroLectura Flujo de entrada del fichero .fa.
 * @param estructura Referencia a la estructura donde se almacenarán los
 * estados.
 */
void Automata::DetectarEstados(std::ifstream& FicheroLectura,
                               Estructura& estructura) {
  unsigned numero_total_estados = estructura.GetNumeroTotalEstados();
  for (unsigned i = 0; i < numero_total_estados; ++i) {
    unsigned numero_estado;
    bool es_final;
    unsigned numero_transiciones;
    FicheroLectura >> numero_estado >> es_final >> numero_transiciones;
    Estado estado;
    estado.SetIdentificador(numero_estado);
    estado.SetAceptacion(es_final);
    std::set<Transicion> transiciones;
    for (unsigned j = 0; j < numero_transiciones; ++j) {
      char valor_transicion;
      int destino;
      FicheroLectura >> valor_transicion >> destino;
      Transicion transicion;
      transicion.SetValorTransicion(valor_transicion);
      transicion.SetDestino(destino);
      transiciones.insert(transicion);
    }
    estado.SetTransiciones(transiciones);
    estructura.AddCadenaEstados(estado);
  }
  if (estructura.GetCadenaEstados().size() != numero_total_estados) {
    std::cerr << "Error: el número de estados leídos ("
              << estructura.GetCadenaEstados().size()
              << ") no coincide con el número declarado ("
              << numero_total_estados << ")." << std::endl;
  }
}
