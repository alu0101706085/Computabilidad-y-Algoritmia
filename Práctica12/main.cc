/**
 * @file main.cc
 * @brief Programa principal.
 *
 * Uso: ./quickhull [-d archivo.dot] < entrada.txt
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "point_set.h"

int main(int argc, char* argv[]) {
  CyA::PointVector points;
  double x, y;
  std::string dot_filename;

  // Gestión de argumentos para el requisito opcional
  for (int i = 1; i < argc; ++i) {
    if (std::strcmp(argv[i], "-d") == 0 && i + 1 < argc) {
      dot_filename = argv[++i];
    }
  }

  // Lectura de entrada estándar
  while (std::cin >> x >> y) {
    points.emplace_back(x, y);
  }

  if (points.size() < 3) {
    std::cerr << "Error: Se necesitan al menos 3 puntos.\n";
    return 1;
  }

  CyA::PointSet point_set(points);
  point_set.QuickHull();

  // 1. Salida estándar (Requisito mínimo)
  point_set.WriteHull(std::cout);

  // 2. Salida DOT (Requisito opcional)
  if (!dot_filename.empty()) {
    std::ofstream dot_file(dot_filename);
    if (dot_file.is_open()) {
      point_set.WriteDot(dot_file);
      // Mensaje de depuración en cerr, no cout, para no ensuciar la salida
      std::cerr << "Archivo DOT generado exitosamente: " << dot_filename << "\n";
    } else {
      std::cerr << "Error al abrir el archivo DOT.\n";
    }
  }

  return 0;
}