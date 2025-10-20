// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 18/10/2025
// Archivo simulador.h: Programa encargado de declarar los atributos y las
// fucniones que tendra la clase modificacion.
// Referencias:
// https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#ifndef MODIFICACION_H
#define MODIFICACION_H

#include "estructura.h"

class Modificacion {
 public:
  // Constructor
  Modificacion() = default;
  // Métodos
  bool EsDFA(Estructura& estructura) const;
  void MotrarEstadosAlcanzables(const int identificador, Estructura& estructura);
 private:
};

#endif