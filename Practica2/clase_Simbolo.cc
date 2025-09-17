#include <iostream>
#include <set>

#include "clase_Simbolo.h"

char Simbolo::GetSimbolo() const {
  return simboloLeido_;
}

bool Simbolo::esMayor(const char letra) {
  return simboloLeido_ > letra;
}

std::ostream& operator<<(std::ostream& os, const Simbolo& letra) {
  os << letra.GetSimbolo();
  return os;
}

std::istream& operator>>(std::istream& is, const Simbolo& letra) {
  is >> letra;
  return is;
}