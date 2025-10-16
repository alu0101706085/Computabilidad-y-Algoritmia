#ifndef AUTOMATA
#define AUTOMATA

#include "string"

#include "../include/estructura.h"

class Automata {
 public:
  Automata() = default;
  void DefinirAutomata(const std::string& FicheroDeEntrada, Estructura estructura);
 private:
  void DetectarAlfabeto(std::ifstream& FicheroLectura, Estructura estructura);
  void DetectarTotalEstadosYEstadoInicial(std::ifstream& FicheroLectura, Estructura estructura);
  void DetectarEstado(std::ifstream& FicheroLectura, Estructura estructura);
};

#endif