// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramáticas en Forma Normal de Chomsky
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 03/11/2025
// Archivo simbolo.h
// Referencias: https://google.github.io/styleguide/cppguide.html

#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <iostream>
#include <string>
#include <tuple>

/**
 * @brief Representa un símbolo de una gramática formal.
 *
 * Un símbolo puede ser terminal o no terminal y se identifica por una cadena.
 */
class Simbolo {
 public:
  Simbolo() : simbolo_(), es_terminal_(false) {}
  Simbolo(std::string caracter, bool es_terminal)
      : simbolo_(std::move(caracter)), es_terminal_(es_terminal) {}
  // Getters
  std::string GetSimbolo() const { return simbolo_; }
  bool GetEsTerminal() const { return es_terminal_; }
  // Setters
  void SetSimbolo(const std::string& s) { simbolo_ = s; }
  void SetEsTerminal(bool es_terminal) { es_terminal_ = es_terminal; }
  // Operadores de comparación
  bool operator<(const Simbolo& otro) const { return simbolo_ < otro.simbolo_; }
  bool operator==(const Simbolo& otro) const {
    return simbolo_ == otro.simbolo_ && es_terminal_ == otro.es_terminal_;
  }
  bool operator!=(const Simbolo& otro) const { return !(*this == otro); }
  // Sobrecarga de operadores de flujo
  friend std::ostream& operator<<(std::ostream& os, const Simbolo& simbolo);
  friend std::istream& operator>>(std::istream& is, Simbolo& simbolo);
 private:
  std::string simbolo_;   ///< Cadena que representa el símbolo.
  bool es_terminal_;      ///< Indica si el símbolo es terminal o no.
};

#endif  // SIMBOLO_H
