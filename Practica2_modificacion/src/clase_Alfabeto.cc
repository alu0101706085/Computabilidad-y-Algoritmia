// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 22/09/2025
// Archivo clase_Alfabeto.cc: programa de definicion de la clase alfabeto.
// Contiene las definiciones de la clase alfabeto para poder calcular
// si un simbolo pertenece o no a esa clase, además de establecer su escritura.
// Objetivos del Proyecto: Facilitar la operacion con alfabetos.
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

#include "clase_Alfabeto.h"

#include <iostream>
#include <sstream>

bool Alfabeto::PerteneceAlAlfabeto(const Simbolo& simbolo) const {
  return alfabeto_.find(simbolo) != alfabeto_.end();
}
void Alfabeto::CrearAlfabeto(const std::string cadena) {
  alfabeto_.clear();
  for (Simbolo caracter : cadena) {
    // Solo añadimos si no está ya en el alfabeto
    if (alfabeto_.find(caracter) == alfabeto_.end()) {
      alfabeto_.insert(caracter);
    }
  }
}
std::ostream& operator<<(std::ostream& os, const Alfabeto& otro) {
  os << "{";
  for (auto elemento = otro.alfabeto_.begin(); elemento != otro.alfabeto_.end();
       ++elemento) {
    os << *elemento;
    if (std::next(elemento) != otro.alfabeto_.end()) {
      os << ", ";
    }
  }
  os << "}";
  return os;
}