#include <iostream>
#include <sstream>

#include "clase_Alfabeto.h"

bool Alfabeto::PerteneceAlAlfabeto(const Simbolo& simbolo) const {
  return alfabeto_.find(simbolo) != alfabeto_.end();
}
void Alfabeto::CrearAlfabeto(const std::string cadena) {
  alfabeto_.clear();
  for (char caracter : cadena) {
    Simbolo simbolo(caracter);
    // Solo añadimos si no está ya en el alfabeto
    if (alfabeto_.find(simbolo) == alfabeto_.end()) {
      alfabeto_.insert(simbolo);
    }
  }
}
std::ostream& operator<<(std::ostream& os, const Alfabeto& otro) {
  os << "{";
  for (auto elemento = otro.alfabeto_.begin(); elemento != otro.alfabeto_.end(); ++elemento) {
    os << *elemento;
    if (std::next(elemento) != otro.alfabeto_.end()) {
      os << ", ";
    }
  }
  os << " }\n";
  return os;
}