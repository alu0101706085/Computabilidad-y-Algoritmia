#include <iostream>
#include <algorithm>

#include "clase_Lenguaje.h"
#include "clase_Cadena.h"

void Lenguaje::CalcularPrefijos(const std::string cadena) {
  lenguaje_.clear();
  Cadena palabra;
  if (cadena == "&") {  // Implica lenguaje vacío
    palabra.SetCadena(cadena);
    lenguaje_.insert(palabra);
  } else {
    std::string palabraActualizada = "";
    Cadena cadenaActualizada = palabraActualizada;
    for (char caracter : cadena) {
      palabraActualizada += caracter;
      cadenaActualizada.SetCadena(palabraActualizada);
      lenguaje_.insert(cadenaActualizada);
    }
  }
}

void Lenguaje::CalcularSufijos(const std::string cadena) {
  lenguaje_.clear();
  if (cadena == "&") {  // Implica lenguaje vacío
    Cadena palabra = cadena;
    lenguaje_.insert(palabra);
  } else {
    std::string palabraActualizada = "";
    Cadena cadenaActualizada = palabraActualizada;
    for (int i = static_cast<int>(cadena.size()) - 1; i >= 0; i--) {
      palabraActualizada += cadena[i];
      cadenaActualizada.SetCadena(palabraActualizada);
      lenguaje_.insert(cadenaActualizada);
    }
  }
}

std::ostream& operator<<(std::ostream& os, const Lenguaje& lenguaje) {
  os << "{&";
  for (auto elemento = lenguaje.lenguaje_.begin(); elemento != lenguaje.lenguaje_.end(); ++elemento) {
    if (std::prev(elemento) == lenguaje.lenguaje_.end()) {
      os << ", ";
    }
    os << *elemento;
    if (std::next(elemento) != lenguaje.lenguaje_.end()) {
      os << ", ";
    }
  }
  os << "}";
  return os;
}