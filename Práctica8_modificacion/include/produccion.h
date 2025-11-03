// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramáticas en Forma Normal de Chomsky
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 03/11/2025
// Archivo produccion.h
// Referencias: https://google.github.io/styleguide/cppguide.html

#ifndef PRODUCCION_H
#define PRODUCCION_H

#include "../include/simbolo.h"
#include <vector>
#include <iostream>

/**
 * @brief Representa una producción de una gramática formal.
 *
 * Cada producción consta de un símbolo no terminal en el lado izquierdo
 * y una secuencia de símbolos (terminales o no terminales) en el lado derecho.
 */
class Produccion {
 public:
  Produccion() = default;
  // Getters
  Simbolo GetSimbolo() const { return no_terminal_; }
  std::vector<Simbolo> GetSecuencia() const { return secuencia_; }
  // Setters
  void SetSimbolo(const Simbolo& no_terminal) { no_terminal_ = no_terminal; }
  void SetSecuencia(const std::vector<Simbolo>& secuencia) { secuencia_ = secuencia; }
  /// @brief Determina si la producción es unitaria (A → B).
  bool EsUnitaria() const;
  // Sobrecarga de operadores de E/S
  friend std::ostream& operator<<(std::ostream& os, const Produccion& produccion);
  friend std::istream& operator>>(std::istream& is, Produccion& produccion);
 private:
  Simbolo no_terminal_;                ///< Símbolo no terminal del lado izquierdo.
  std::vector<Simbolo> secuencia_;     ///< Secuencia de símbolos del lado derecho.
};
#endif  // PRODUCCION_H
