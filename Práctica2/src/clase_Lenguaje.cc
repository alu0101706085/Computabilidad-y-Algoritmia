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
  if (cadena == CADENA_VACIA) {  // Implica cadena vacia
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
  os << "{" << CADENA_VACIA;
  for (auto elemento = lenguaje.lenguaje_.begin();
       elemento != lenguaje.lenguaje_.end(); ++elemento) {
    std::string vacio = CADENA_VACIA;
    Cadena cadenaVacia = vacio;
    if (*elemento == cadenaVacia) {
      os << "}";
      return os;
    }
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