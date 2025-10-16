#include "../include/simulador.h"

#include <iostream>

#include "../include/estado.h"
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
    bool aceptada = AnalizarCadena(cadena, estructura);
    std::cout << cadena << " --- "
              << (aceptada ? "Accepted" : "Rejected") << std::endl;
  }
}

bool Simulador::AnalizarCadena(const std::string& cadena,
                               Estructura estructura) {
  for (char simbolo : cadena) {
    if (!VerificarValorTransicion(simbolo, estructura)) {
      std::cerr << "Error, la cadena posee valores fuera de su alfabeto"
                << std::endl;
    } else {
      Estado estado_inicial = estructura.GetEstadoArranque();
      AnalizarNFA(simbolo, estado_inicial, estructura);
    }
  }
}

void Simulador::AnalizarNFA(const char simbolo, Estado estado,  Estructura estructura) {
  std::set<Transicion> transiciones = estado.GetSetTransiciones();
  for (auto transicion : transiciones) {
    if (transicion.GetValorTransicion() == simbolo ||
        transicion.GetValorTransicion() == '&') {
      Estado destino = transicion.GetDestino();
      AnalizarNFA(simbolo, estado, estructura); // No tiene lógica
    }
  }
}

// Comprobaciones
bool Simulador::VerificarValorTransicion(const char simbolo,
                                         const Estructura& estructura) {
  std::set<char> alfabeto = estructura.GetAlfabeto();
  return alfabeto.find(simbolo) != alfabeto.end();
}