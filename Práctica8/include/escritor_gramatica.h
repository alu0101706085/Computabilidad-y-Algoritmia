#ifndef ESCRITOR_GRAMATICA_H
#define ESCRITOR_GRAMATICA_H

#include <string>

#include "../include/gramatica.h"

class EscritorGramatica {
 public:
  EscritorGramatica() = default;
  void EscribirFNC(std::string fichero_salida, Gramatica& gramatica);
};

#endif