// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 18/10/2025
// Archivo transicion.cc: Programa encargado de definir los métodos de la clase
// Transicion.
// Referencias: https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#include "../include/transicion.h"

#include <iostream>

/**
 * @brief Compara dos transiciones.
 *
 * Si las transiciones tienen el mismo símbolo, se comparan por su destino.
 * @param otro Transición con la que se compara.
 * @return true si la transición actual es menor que la otra.
 */
bool Transicion::operator<(const Transicion& otro) const {
  if (valor_transicion_ == otro.valor_transicion_)
    return destino_ < otro.destino_;
  return valor_transicion_ < otro.valor_transicion_;
}

/**
 * @brief Lee el símbolo de una transición desde un flujo de entrada.
 *
 * @param is Flujo de entrada desde el que se leerá.
 * @param transicion Objeto donde se almacenará el símbolo leído.
 * @return Referencia al flujo de entrada.
 */
std::istream& operator>>(std::istream& is, Transicion& transicion) {
  is >> transicion.valor_transicion_;
  return is;
}
