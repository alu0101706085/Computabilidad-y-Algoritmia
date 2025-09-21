// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: David Javier Rodríguez Fumero 
// Correo: alu0101706085@ull.edu.es
// Fecha: 19/09/2025
// Archivo clase_Cadena.cc: programa de definicion de la clase cadena.
// Contiene las definiciones de la clase cadena para poder calcular
// longitudes e inversas, además de establecer como leer y escribir cadenas.
// Objetivos del Proyecto: Facilitar la operacion con cadenas.
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
#include <algorithm>

#include "clase_Cadena.h"

int Cadena::ObtenerLongitud() {
  int resultado{0};
  if (cadenaLeida_ == "ε") {
    resultado = 0;
  } else {
    resultado = cadenaLeida_.size();
  }
  return resultado;
}
std::string Cadena::ObtenerInversa() {
  if (cadenaLeida_ == "ε") {
    return "ε";
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