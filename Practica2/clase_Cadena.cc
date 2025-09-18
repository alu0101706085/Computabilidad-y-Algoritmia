#include <iostream>
#include <algorithm>

#include "clase_Simbolo.h"
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
  std::string resultado;
  if (cadenaLeida_.empty()) {
    resultado = "&";
  } else {
    Simbolo simbolo;
    std::string resultado;
    reverse(cadenaLeida_.begin(), cadenaLeida_.end());
    resultado = resultado;
  }
  return resultado;
}

std::ostream& operator<<(std::ostream& os, const Cadena& otro) {
  os << otro.cadenaLeida_;
}

std::istream& operator>>(std::istream& is, Cadena& otro) {
  is >> otro.cadenaLeida_;
}