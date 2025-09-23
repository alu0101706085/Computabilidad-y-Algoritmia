// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 22/09/2025
// Archivo clase_Cadena.cc: programa de definicion de la clase cadena.
// Contiene las definiciones de la clase cadena para poder calcular
// longitudes e inversas, además de establecer como leer y escribir cadenas.
// Objetivos del Proyecto: Facilitar la operacion con cadenas.
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

#include "clase_Cadena.h"

#include <algorithm>
#include <iostream>

const char* CADENA_VACIA_ = "&";

int Cadena::ObtenerLongitud() {
  int resultado{0};
  if (cadenaLeida_ == CADENA_VACIA_) {
    resultado = 0;
  } else {
    resultado = cadenaLeida_.size();
  }
  return resultado;
}
std::string Cadena::ObtenerInversa() {
  if (cadenaLeida_ == CADENA_VACIA_) {
    return CADENA_VACIA_;
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