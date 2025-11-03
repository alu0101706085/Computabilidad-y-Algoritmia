// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramáticas en Forma Normal de Chomsky
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 03/11/2025
// Archivo produccion.cc: Implementación de la clase Produccion.
// Referencias: https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#include "../include/simbolo.h"
#include "../include/produccion.h"

#include <iostream>
#include <sstream>

/**
 * @brief Comprueba si la producción es unitaria.
 * Una producción es unitaria si tiene exactamente un símbolo en su parte derecha
 * y este símbolo es un no terminal.
 * @return true si la producción es unitaria (A → B).
 */
bool Produccion::EsUnitaria() const {
  return secuencia_.size() == 1 && !secuencia_[0].GetEsTerminal();
}

/**
 * @brief Sobrecarga del operador de salida para imprimir una producción.
 * @param os Flujo de salida.
 * @param produccion Producción a imprimir.
 * @return Referencia al flujo de salida.
 */
std::ostream& operator<<(std::ostream& os, const Produccion& produccion) {
  os << produccion.GetSimbolo() << " ";
  for (size_t i = 0; i < produccion.GetSecuencia().size(); ++i) {
    os << produccion.GetSecuencia()[i];
    if (i + 1 < produccion.GetSecuencia().size()) os << ' ';
  }
  return os;
}

/**
 * @brief Sobrecarga del operador de entrada para leer una producción desde un flujo.
 * @param is Flujo de entrada.
 * @param produccion Producción que se rellenará.
 * @return Referencia al flujo de entrada.
 */
std::istream& operator>>(std::istream& is, Produccion& produccion) {
  if (!(is >> produccion.no_terminal_)) return is;
  produccion.secuencia_.clear();
  std::string resto;
  std::getline(is, resto);
  std::istringstream iss(resto);
  std::string cadena;
  while (iss >> cadena) {
    if (cadena.size() == 1) {
      Simbolo simbolo(cadena, false);
      produccion.secuencia_.push_back(simbolo);
    } else {
      for (char c : cadena) {
        std::string s(1, c);
        Simbolo simbolo(s, false);
        produccion.secuencia_.push_back(simbolo);
      }
    }
  }
  return is;
}