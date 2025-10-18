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
// define a un automata finito y definir su comportamiento, guardando sus
// valores en Estructura.
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

void Automata::DefinirAutomata(const std::string& FicheroDeEntrada,
                               Estructura& estructura) {
  std::ifstream FicheroLectura(FicheroDeEntrada);
  if (!FicheroLectura) {
    std::cerr << "Error, no se pudo abrir el fichero de salida" << std::endl;
    return;
  }
  DetectarAlfabeto(FicheroLectura, estructura);
  DetectarTotalEstadosYEstadoInicial(FicheroLectura, estructura);
  DetectarEstados(FicheroLectura, estructura);
  FicheroLectura.close();
}

void Automata::DetectarAlfabeto(std::ifstream& FicheroLectura,
                                Estructura& estructura) {
  std::string linea;
  std::getline(FicheroLectura, linea);
  for (char simbolo : linea) {
    if (simbolo == '&') {
      std::cerr << "El alfabeto no puede definirse con una cadena vacia"
                << std::endl;
      break;
    } else if (simbolo != ' ' && simbolo != '\n') {
      estructura.AddCaracterAlfabeto(simbolo);
    }
  }
}

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
}