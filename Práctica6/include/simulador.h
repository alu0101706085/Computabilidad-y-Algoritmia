#ifndef SIMULADOR_H
#define SIMULADOR_H

#include "../include/estructura.h"
#include "../include/estado.h"
#include "string"

class Simulador {
 public:
  Simulador() = default;
  void RealizarSimulador(const std::string& FicheroDeEntrada,
                         Estructura estructura);
  bool AnalizarCadena(const std::string& cadena, Estructura& estructura);
  std::set<Estado> AvanzarEstado(const std::set<Estado> cadena_estados, char simbolo);
  void MostrarResultado(const std::string& cadena, Estructura& estructura);
  // Comprobaciones
  bool VerificarValorTransicion(const char simbolo,
                                const Estructura& estructura);

 private:
};

#endif