#include "../include/simbolo.h"
#include "../include/produccion.h"

#include <iostream>

bool Produccion::EsUnitaria() const {
  return secuencia_.size() == 1 && !secuencia_[0].GetEsTerminal();
}

std::ostream& operator<<(std::ostream& os, const Produccion& produccion) {
  os << produccion.no_terminal_ << " ";
  for (const auto& s : produccion.secuencia_) {
    os << s;
  }
  return os;
}
std::istream& operator>>(std::istream& is, Produccion& produccion) {
  is >> produccion.no_terminal_;
  produccion.secuencia_.clear();
  Simbolo simbolo;
  while (is >> simbolo) {
    produccion.secuencia_.push_back(simbolo);
  }
  return is;
}