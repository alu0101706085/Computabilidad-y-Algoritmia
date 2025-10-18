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
// cualquieras y comprobar si esas cadenas son aceptadas o no por el autómata
// definido.
// Referencias:
// https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#include "../include/simulador.h"

#include <iostream>

#include "../include/estado.h"
#include "../include/estructura.h"
#include "fstream"

void Simulador::RealizarSimulador(const std::string& FicheroDeEntrada,
                                  Estructura estructura) {
  std::ifstream FicheroLectura(FicheroDeEntrada);
  if (!FicheroLectura) {
    std::cerr << "Error, no se pudo abrir el fichero de salida" << std::endl;
    return;
  }
  std::string cadena;
  while (FicheroLectura >> cadena) {
    MostrarResultado(cadena, estructura);
  }
  FicheroLectura.close();
}

void Simulador::MostrarResultado(const std::string& cadena,
                                 Estructura& estructura) {
  bool aceptada = AnalizarCadena(cadena, estructura);
  std::cout << cadena << " --- " << (aceptada ? "Accepted" : "Rejected")
            << std::endl;
}

bool Simulador::AnalizarCadena(const std::string& cadena,
                               Estructura& estructura) {
  bool es_aceptado{false};
  // Use the fully defined start state (with transitions) stored in estructura
  Estado estado_inicio =
      estructura.GetEstadoEspecifico(estructura.GetEstadoArranque().GetIdentificador());
  std::set<Estado> estados_actuales = {estado_inicio};
  for (char c : cadena) {
    if (!VerificarValorTransicion(c, estructura)) {
      std::cerr << "Error, el valor de transicion no pertenece al alfabeto"
                << std::endl;
      break;
    }
    estados_actuales = AvanzarEstado(estados_actuales, c, estructura);
    if (estados_actuales.empty()) {
      es_aceptado = false;
    }
  }
  // Verifica si el estado es de aceptacion
  for (Estado estado : estados_actuales) {
    if (estado.EsFinal()) {
      es_aceptado = true;
    }
  }
  return es_aceptado;
}

std::set<Estado> Simulador::AvanzarEstado(
    const std::set<Estado>& cadena_estados, char simbolo,
    Estructura& estructura) {
  std::set<Estado> estados_siguientes;
  for (const auto& estado : cadena_estados) {
    for (const auto& transiciones : estado.GetSetTransiciones()) {
      if (transiciones.GetValorTransicion() == simbolo) {
        Estado destino =
            estructura.GetEstadoEspecifico(transiciones.GetDestino());
        estados_siguientes.insert(destino);
      }
    }
  }
  return estados_siguientes;
}

// Comprobaciones
bool Simulador::VerificarValorTransicion(const char simbolo,
                                         const Estructura& estructura) {
  std::set<char> alfabeto = estructura.GetAlfabeto();
  return alfabeto.find(simbolo) != alfabeto.end();
}