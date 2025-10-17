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
    std::set<Estado> estados_actuales;
    MostrarResultado(cadena, estructura);
  }
}

void Simulador::MostrarResultado(const std::string& cadena,
                                 Estructura& estructura) {
  bool aceptada = AnalizarCadena(cadena, estructura);
  std::cout << cadena << " --- " << (aceptada ? "Accepted" : "Rejected")
            << std::endl;
}

std::set<Estado> Simulador::AvanzarEstado(const std::set<Estado> cadena_estados, char simbolo) {
  std::set<Estado> estados_siguientes;
  for (const auto& estado : cadena_estados) {
    if (estado.GetIdentificador() == simbolo) {
      estados_siguientes.insert(estado);
    }
  }
  return estados_siguientes;
}

bool Simulador::AnalizarCadena(const std::string& cadena, Estructura& estructura) {
  std::set<Estado> estados_actuales = {estructura.GetEstadoArranque()};
  for (char c : cadena) {
    estados_actuales = AvanzarEstado(estados_actuales, c);
    if (estados_actuales.empty()) {
      return false;
    }
  }
    //Verifica si el estado es de aceptacion
  for (Estado estado : estados_actuales) {
    int numero_estado = estado.GetIdentificador();
    if (estructura.GetEstadoEspecifico(numero_estado).EsFinal()) {
      return true;
    }
  }
  return false;  
}

// Comprobaciones
bool Simulador::VerificarValorTransicion(const char simbolo,
                                         const Estructura& estructura) {
  std::set<char> alfabeto = estructura.GetAlfabeto();
  return alfabeto.find(simbolo) != alfabeto.end();
}