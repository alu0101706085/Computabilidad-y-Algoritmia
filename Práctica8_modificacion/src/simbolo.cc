// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramáticas en Forma Normal de Chomsky
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 03/11/2025
// Archivo simbolo.cc: Implementación de la clase Simbolo.
// Referencias: https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#include "../include/simbolo.h"
#include <iostream>

/**
 * @brief Sobrecarga del operador de salida para imprimir un símbolo.
 * @param os Flujo de salida.
 * @param simbolo Símbolo a imprimir.
 * @return Referencia al flujo de salida.
 */
std::ostream& operator<<(std::ostream& os, const Simbolo& simbolo) {
  os << simbolo.simbolo_;
  return os;
}

/**
 * @brief Sobrecarga del operador de entrada para leer un símbolo desde un flujo.
 * @param is Flujo de entrada.
 * @param simbolo Símbolo que se rellenará.
 * @return Referencia al flujo de entrada.
 */
std::istream& operator>>(std::istream& is, Simbolo& simbolo) {
  is >> simbolo.simbolo_;
  return is;
}
