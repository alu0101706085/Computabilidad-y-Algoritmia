// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 18/10/2025
// Archivo estado.h: Programa encargado de declarar los atributos y las
// fucniones que tendra la clase estado.
// Referencias:
// https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#ifndef ESTADO_H
#define ESTADO_H

#include <iostream>
#include <set>

#include "transicion.h"  // Incluir transicion.h

class Estado {
 public:
  Estado() : identificador_(-1), aceptacion_(false) {}
  Estado(int identificador, bool aceptacion = false)
      : identificador_(identificador), aceptacion_(aceptacion) {}

  int GetIdentificador() const { return identificador_; }
  bool EsFinal() const { return aceptacion_; }
  const std::set<Transicion>& GetSetTransiciones() const { return transiciones_; }

  void SetIdentificador(int identificador) { identificador_ = identificador; }
  void SetAceptacion(bool aceptacion) { aceptacion_ = aceptacion; }
  void SetTransiciones(const std::set<Transicion>& transiciones) {
    transiciones_ = transiciones;
  }
  void AgregarTransicion(const Transicion& transicion) {
    transiciones_.insert(transicion);
  }

  bool operator<(const Estado& otro) const {
    return identificador_ < otro.identificador_;
  }

  bool operator==(const Estado& otro) const {
    return identificador_ == otro.identificador_;
  }
  friend std::istream& operator>>(std::istream& is, Estado& estado);
  friend std::ostream& operator<<(std::ostream& os, const Estado& estado);

 private:
  int identificador_;
  bool aceptacion_;
  std::set<Transicion> transiciones_;
};

#endif  // ESTADO_H