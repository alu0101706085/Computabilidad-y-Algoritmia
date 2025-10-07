// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares en C++
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 07/10/2025
// Archivo clase_Bucle.h: Programa encargado de definir las 
// funciones necesarias para detectar un bucle dado.
// Referencias:
// https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#ifndef CLASE_BUCLE
#define CLASE_BUCLE

#include <iostream>
#include <string>
#include <vector>

enum class TipoBucle { BUCLE_FOR, BUCLE_WHILE, BUCLE_SWITCH };

class Bucle {
 public:
  Bucle() = default;
  Bucle(TipoBucle tipo, int numero_linea)
      : tipo_(tipo), numero_linea_(numero_linea) {}
  // Getters
  TipoBucle GetTipo() const { return tipo_; }
  int GetNumeroLinea() const { return numero_linea_; }
  std::string GetOpcion() const { return opcion_; } // Modificacion
  int GetNumeroBreaks() const { return numero_breaks; } // Modificacion
  // Setters
  void SetTipo(const TipoBucle& tipo) { tipo_ = tipo; }
  void SetNumeroLinea(const int numero_linea) { numero_linea_ = numero_linea; } // Modificacion
  void SetOpcion(const std::string& opcion) { opcion_ = opcion; } // Modificacion
  void AddNumeroBreaks() { numero_breaks++; }
 private:
  TipoBucle tipo_;
  int numero_linea_;
  // MODIFICACION
  std::string opcion_;
  int numero_breaks = 0;
};

#endif