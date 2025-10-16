#ifndef RECONOCER_CADENAS
#define RECONOCER_CADENAS

#include "string"

#include "../include/estructura.h"

class Reconocimiento {
 public:
  Reconocimiento() = default;
  void ReconocerCadena(const std::string& FicheroDeEntrada, Estructura estructura);
 private:
};

#endif