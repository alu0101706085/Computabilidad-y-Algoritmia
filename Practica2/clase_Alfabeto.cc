#include <iostream>

#include "clase_Alfabeto.h"

std::set<Simbolo> Alfabeto::GetAlfabeto() {
    return alfabeto_;
}

std::ostream& operator<<(std::ostream& os, const Alfabeto& alfabeto) {
  os << "{";
  for (std::set<Simbolo>::iterator elemento = alfabeto.alfabeto_.begin(); elemento != alfabeto.alfabeto_.end(); ++elemento) {
    os << *elemento << ", ";
}
  os << "}";
  return os;
}

std::istream& operator>>(std::istream& is, const Alfabeto& alfabeto) {
  std::string cadena;
  is >> cadena;
  is.clear();
  is >> alfabeto;
  return is;
}