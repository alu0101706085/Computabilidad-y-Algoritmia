#include <iostream>
#include <algorithm>

#include "clase_Lenguaje.h"
#include "clase_Cadena.h"

void Lenguaje::CalcularPrefijos(const std::string cadena) {
  lenguaje_.clear();
  if (cadena == "") {  // Implica lenguaje vacío
    Cadena palabra = cadena;
    lenguaje_.insert(palabra);
  } else {
    std::string cadenaVacia = "&";
    Cadena vacio = cadenaVacia;
    lenguaje_.insert(cadenaVacia);
    std::string palabraActualizada = "";
    for (char caracter : cadena) {
      palabraActualizada += caracter;
      lenguaje_.insert(palabraActualizada);
    }
  }
}

void Lenguaje::CalcularSufijos(const std::string cadena) {
  lenguaje_
  .clear();
  if (cadena == "") {  // Implica lenguaje vacío
    Cadena palabra = cadena;
    lenguaje_
    .insert(palabra);
  } else {
    std::string cadenaVacia = "&";
    Cadena vacio = cadenaVacia;
    lenguaje_
    .insert(cadenaVacia);
    std::string palabraActualizada = "";
    for (int i{cadena.size() - 1}; i >= 0; i--) {
      palabraActualizada += cadena[i];
      lenguaje_
      .insert(palabraActualizada);
    }
  }
}

std::ostream& operator<<(std::ostream& os, const Lenguaje& lenguaje) {
  os << "{";
  for (auto elemento = lenguaje.lenguaje_.begin(); elemento != lenguaje.lenguaje_.end(); ++elemento) {
    os << *elemento;
    if (std::next(elemento) != lenguaje.lenguaje_.end()) {
      os << ", ";
    }
  }
  os << " }";
  return os;
}