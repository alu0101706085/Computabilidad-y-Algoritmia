/**
 * @file main.cpp
 * @brief Programa principal para el cálculo del EMST.
 * * Lee puntos de la entrada estándar y muestra el árbol resultante.
 * Soporta la opción -d para salida en formato DOT.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include "point_types.hpp"
#include "point_set.hpp"

int main(int argc, char* argv[]) {
  CyA::VectorPuntos puntos;

  // Lectura de entrada estándar
  if (!(std::cin >> puntos)) {
    std::cerr << "Error: Entrada vacía o formato incorrecto." << std::endl;
    return 1;
  }

  // Creación del objeto y ejecución del algoritmo
  EMST::PointSet conjunto(puntos);
  conjunto.CalcularEMST();

  // Gestión de argumentos de línea de comandos
  bool modo_dot = false;
  if (argc > 1 && std::strcmp(argv[1], "-d") == 0) {
    modo_dot = true;
  }

  // Salida de resultados
  if (modo_dot) {
    conjunto.EscribirDOT(std::cout);
  } else {
    conjunto.EscribirArbol(std::cout);
  }

  return 0;
}