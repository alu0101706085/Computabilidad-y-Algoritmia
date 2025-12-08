/**
 * @file point_types.cpp
 * @brief Implementación de la sobrecarga de operadores para E/S.
 */

#include "point_types.hpp"

#include <iomanip>

std::ostream& operator<<(std::ostream& os, const CyA::VectorPuntos& puntos) {
  os << puntos.size() << std::endl;

  for (const CyA::Punto& punto : puntos) {
    os << punto << std::endl;
  }

  return os;
}

std::ostream& operator<<(std::ostream& os, const CyA::Punto& punto) {
  os << std::setw(MAX_ANCHO_COORD) << std::fixed << std::setprecision(MAX_PRECISION) 
     << punto.first << "\t" 
     << std::setw(MAX_ANCHO_COORD) << std::fixed << std::setprecision(MAX_PRECISION) 
     << punto.second;

  return os;
}

std::istream& operator>>(std::istream& is, CyA::VectorPuntos& puntos) {
  int num_puntos;
  is >> num_puntos;

  puntos.clear();

  for (int i = 0; i < num_puntos; ++i) {
    CyA::Punto punto;
    is >> punto;
    puntos.push_back(punto);
  }

  return is;
}

std::istream& operator>>(std::istream& is, CyA::Punto& punto) {
  is >> punto.first >> punto.second;
  return is;
}