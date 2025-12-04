#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include "point_types.hpp"
#include "point_set.hpp"

int main(int argc, char* argv[]) {
  CyA::PointVector points;

  // Lectura de puntos desde la entrada estándar
  // Se espera que el usuario redirija un archivo: ./emst < data.txt
  if (!(std::cin >> points)) {
    std::cerr << "Error: No se pudieron leer los puntos de la entrada estándar." << std::endl;
    return 1;
  }

  // Inicialización y cálculo del algoritmo
  EMST::PointSet point_set(points);
  point_set.ComputeEMST();

  // Comprobar argumentos para salida opcional DOT (-d)
  bool dot_output_mode = false;
  if (argc > 1 && std::strcmp(argv[1], "-d") == 0) {
    dot_output_mode = true;
  }

  if (dot_output_mode) {
    point_set.WriteDot(std::cout);
  } else {
    point_set.WriteTree(std::cout);
  }

  return 0;
}