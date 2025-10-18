// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 18/10/2025
// Archivo estado.cc: Programa encargado de definir las métodos de la clase
// estado. Referencias: https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#include "../include/estado.h"

std::istream& operator>>(std::istream& is, Estado& estado) {
  is >> estado.identificador_ >> estado.aceptacion_;
  return is;
}

std::ostream& operator<<(std::ostream& os, const Estado& estado) {
  os << estado.identificador_ << " " << estado.aceptacion_;
  return os;
}