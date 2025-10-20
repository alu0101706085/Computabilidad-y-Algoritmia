// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 18/10/2025
// Archivo estado.cc: Programa encargado de definir los métodos de la clase
// Estado.
// Referencias: https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#include "../include/estado.h"

/**
 * @brief Lee los datos de un estado desde un flujo de entrada.
 *
 * Se espera que el flujo contenga el identificador y el valor booleano
 * que indica si el estado es de aceptación.
 * @param is Flujo de entrada.
 * @param estado Objeto Estado donde se almacenarán los datos leídos.
 * @return Referencia al flujo de entrada.
 */
std::istream& operator>>(std::istream& is, Estado& estado) {
  is >> estado.identificador_ >> estado.aceptacion_;
  return is;
}

/**
 * @brief Escribe la información de un estado en un flujo de salida.
 *
 * Se muestran el identificador y la marca de aceptación separados por un espacio.
 * @param os Flujo de salida.
 * @param estado Estado cuyos datos se van a imprimir.
 * @return Referencia al flujo de salida.
 */
std::ostream& operator<<(std::ostream& os, const Estado& estado) {
  os << estado.identificador_ << " " << estado.aceptacion_;
  return os;
}
