#include <fstream>
#include <iostream>
#include <string>

#include "../include/automata.h"
#include "../include/estructura.h"
#include "../include/transicion.h"

void Automata::DefinirAutomata(const std::string& FicheroDeEntrada, Estructura estructura) {
  std::ifstream FicheroLectura(FicheroDeEntrada);
  if (!FicheroLectura) {
    std::cerr << "Error, no se pudo abrir el fichero de salida" << std::endl;
    return;
  }
  DetectarAlfabeto(FicheroLectura, estructura);
  DetectarTotalEstadosYEstadoInicial(FicheroLectura, estructura);
  DetectarEstado(FicheroLectura, estructura);
  FicheroLectura.close();
}

void Automata::DetectarAlfabeto(std::ifstream& FicheroLectura, Estructura estructura) {
  std::string linea;
  std::getline(FicheroLectura, linea);
  for (char simbolo : linea) {
    if (simbolo == '&') {
      std::cerr << "El alfabeto no puede definirse con una cadena vacia" << std::endl;
      break;
    } else if (simbolo != ' ' && simbolo != '\n') {
      estructura.AddCaracterAlfabeto(simbolo);
    }
  }
}

void Automata::DetectarTotalEstadosYEstadoInicial(std::ifstream& FicheroLectura, Estructura estructura) {
  unsigned numero_total_estados{0};
  Estado estado_inicial;
  FicheroLectura >> numero_total_estados >> estado_inicial;
  estructura.SetNumeroTotalEstados(numero_total_estados);
  estructura.SetEstadoArranque(estado_inicial);
}

void Automata::DetectarEstado(std::ifstream& FicheroLectura, Estructura estructura) {
  // ELIMINAR el bucle for - procesar solo UNA línea
  Estado estado;
  unsigned numero_estado;
  bool es_final;
  unsigned numero_transiciones;
  // Leer solo UNA línea
  FicheroLectura >> numero_estado >> es_final >> numero_transiciones;
  Transicion transicion;
  std::set<Transicion> cadena;
  // Leer las transiciones de esta única línea
  for (unsigned j = 0; j < numero_transiciones; j++) {
    char valor_transicion;
    int destino;
    FicheroLectura >> valor_transicion >> destino;
    transicion.SetValorTransicion(valor_transicion);
    transicion.SetDestino(destino);
    cadena.insert(transicion);
  }
  estado.SetSetTranscion(cadena);
  estructura.AddCadenaEstados(estado);
}