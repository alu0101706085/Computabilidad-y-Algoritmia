// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: David Javier Rodríguez Fumero 
// Correo: alu0101706085@ull.edu.es
// Fecha: 19/09/2025
// Archivo clase_Alfabeto.cc: programa de definicion de la clase alfabeto.
// Contiene las definiciones de la clase alfabeto para poder calcular
// si un simbolo pertenece o no a esa clase, además de establecer su escritura.
// Objetivos del Proyecto: Facilitar la operacion con alfabetos.
// Estructura de Datos Utilizadas:
// Referencias:
// Enlaces de inter´es
//
// Historial de revisiones
// 16/09/2025 - Creaci´on (primera versi´on) del c´odigo
// 17/09/2025 - Avance con las clases simbolo y alfabeto
// 18/09/2025 - Avance con las clases cadena, lenguaje y el main
// 19/09/2025 - Obtención de los resultados esperados

#include <iostream>
#include <sstream>

#include "clase_Alfabeto.h"

bool Alfabeto::PerteneceAlAlfabeto(const Simbolo& simbolo) const {
  return alfabeto_.find(simbolo) != alfabeto_.end();
}
void Alfabeto::CrearAlfabeto(const std::string cadena) {
  alfabeto_.clear();
  for (char caracter : cadena) {
    Simbolo simbolo = caracter;
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
  os << "}";
  return os;
}