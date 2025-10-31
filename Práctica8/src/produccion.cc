#include "../include/simbolo.h"
#include "../include/produccion.h"

#include <iostream>
#include <sstream>

bool Produccion::EsUnitaria() const {
  return secuencia_.size() == 1 && !secuencia_[0].GetEsTerminal();
}

std::ostream& operator<<(std::ostream& os, const Produccion& produccion) {
  os << produccion.GetSimbolo() << " ";
  for (size_t i = 0; i < produccion.GetSecuencia().size(); ++i) {
    os << produccion.GetSecuencia()[i];
    if (i + 1 < produccion.GetSecuencia().size()) os << ' ';
  }
  return os;
}

std::istream& operator>>(std::istream& is, Produccion& produccion) {
  if (!(is >> produccion.no_terminal_)) return is;
  produccion.secuencia_.clear();

  // Leer el resto de la línea (no todo el stream)
  std::string resto;
  std::getline(is, resto);
  std::istringstream iss(resto);
  Simbolo simbolo;
  while (iss >> simbolo) {
    produccion.secuencia_.push_back(simbolo);
  }
  return is;
}