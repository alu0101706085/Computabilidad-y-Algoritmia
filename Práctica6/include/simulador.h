#ifndef SIMULADOR_H
#define SIMULADOR_H

#include "../include/estructura.h"
#include "string"

class Simulador {
 public:
  Simulador() = default;
  void RealizarSimulador(const std::string& FicheroDeEntrada,
                         Estructura estructura);
  bool AnalizarCadena(const std::string& cadena, Estructura estructura);
  void AnalizarNFA(const char simbolo, Estado estado, Estructura estructura);
  void MostrarResultado();
  void CalcularTransicion();  // Nuevos estados tras leer un símbolo
  // Comprobaciones
  bool VerificarValorTransicion(const char simbolo,
                                const Estructura& estructura);

 private:
};

#endif