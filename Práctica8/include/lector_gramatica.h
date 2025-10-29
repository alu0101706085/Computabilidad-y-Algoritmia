#ifndef LECTOR_GRAMATICA_H
#define LECTOR_GRAMATICA_H

#include <string>

#include "../include/gramatica.h"

class LectorGramatica {
 public:
  LectorGramatica() = default;
  void GenerarGramatica(std::string fichero_entrada, Gramatica& gramatica);
};

#endif