// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 22/09/2025
// Archivo clase_Lenguaje.cc: programa de definicion de la clase lenguaje
// Contiene las definiciones de la clase lenguaje para poder establecer
// como desde una cadena establecer sus prefijos y sufijos.
// Objetivos del Proyecto: Facilitar la operacion con lenguajes
// Referencias: https://google.github.io/styleguide/cppguide.html
// Enlaces de inter´es: https://google.github.io/styleguide/cppguide.html
//
// Historial de revisiones
// 16/09/2025 - Creaci´on (primera versi´on) del c´odigo
// 17/09/2025 - Avance con las clases simbolo y alfabeto
// 18/09/2025 - Avance con las clases cadena, lenguaje y el main
// 19/09/2025 - Obtención de los resultados esperados
// 21/09/2025 - Mejoras en el main con restricciones y ayudas
// 22/09/2025 - Introduccion de constantes y mejorar la apliación de la guia de
// estilo de Google

#include "clase_Lenguaje.h"

#include <algorithm>
#include <iostream>

#include "clase_Cadena.h"

const char* CADENA_VACIA = "&";

void Lenguaje::CalcularPrefijos(const std::string cadena) {
  lenguaje_.clear();
  Cadena palabra;
  if (cadena == CADENA_VACIA) {  // Implica cadena vacia
    palabra.SetCadena(cadena);
    lenguaje_.push_back(palabra);
  } else {
    std::string palabraActualizada = "";
    Cadena cadenaActualizada = palabraActualizada;
    for (char caracter : cadena) {
      palabraActualizada += caracter;
      cadenaActualizada.SetCadena(palabraActualizada);
      lenguaje_.push_back(cadenaActualizada);
    }
  }
}

void Lenguaje::CalcularSufijos(const std::string cadena) {
  lenguaje_.clear();
  if (cadena == CADENA_VACIA) {  // Implica cadena vacia
    Cadena palabra = cadena;
    lenguaje_.push_back(palabra);
  } else {
    std::string palabraActualizada = "";
    Cadena cadenaActualizada = palabraActualizada;
    for (int i = static_cast<int>(cadena.size()) - 1; i >= 0; i--) {
      palabraActualizada += cadena[i];
      cadenaActualizada.SetCadena(palabraActualizada);
      lenguaje_.push_back(cadenaActualizada);
    }
  }
}

// El problema estaba en que tenia un set y no un vector, modificacion ya
// funcional
void Lenguaje::CalcularSubcadenas(const std::string cadena) {
  lenguaje_.clear();
  if (cadena == CADENA_VACIA || cadena.empty()) {
    return;  // no añadimos "&" al vector, solo se imprimirá en operator<<
  }
  for (int i = 0; i < static_cast<int>(cadena.size()); ++i) {
    for (int j = 1; j <= static_cast<int>(cadena.size()) - i; ++j) {
      std::string subcadena = cadena.substr(i, j);
      Cadena cadenaSubcadena;
      cadenaSubcadena.SetCadena(subcadena);
      lenguaje_.push_back(cadenaSubcadena);  // guarda con duplicados
    }
  }
}

std::ostream& operator<<(std::ostream& os, const Lenguaje& lenguaje) {
  os << "{" << CADENA_VACIA;  // la cadena vacía siempre presente
  if (!lenguaje.lenguaje_.empty()) {
    os << ", ";
  }
  for (size_t i = 0; i < lenguaje.lenguaje_.size(); ++i) {
    os << lenguaje.lenguaje_[i];
    if (i + 1 < lenguaje.lenguaje_.size()) {
      os << ", ";
    }
  }
  os << "}";
  return os;
}
