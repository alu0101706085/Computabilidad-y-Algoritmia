#include <iostream>
#include <set>

#include "clase_Simbolo.h"

// Sobrecarga del operador de salida
std::ostream& operator<<(std::ostream& os, const Simbolo& simbolo) {
  os << simbolo.simbolo_;
  return os;
}

// Sobrecarga del operador de entrada
std::istream& operator>>(std::istream& is, Simbolo& simbolo) {
  is >> simbolo.simbolo_;
  return is;
}