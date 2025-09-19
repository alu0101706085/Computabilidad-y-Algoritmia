#include <iostream>
#include <algorithm>

#include "clase_Cadena.h"

int Cadena::ObtenerLongitud() {
  int resultado{0};
  if (cadenaLeida_.empty()) {
    resultado = 0;
  } else {
    resultado = cadenaLeida_.size();
  }
  return resultado;
}
std::string Cadena::ObtenerInversa() {
  if (cadenaLeida_.empty()) {
    return "&";
  } else {
    std::string resultado = cadenaLeida_;
    std::reverse(resultado.begin(), resultado.end());
    return resultado;
  }
}
std::ostream& operator<<(std::ostream& os, const Cadena& otro) {
  os << otro.cadenaLeida_;
  return os;
}
std::istream& operator>>(std::istream& is, Cadena& otro) {
  is >> otro.cadenaLeida_;
  return is;
}