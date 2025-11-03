// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramáticas en Forma Normal de Chomsky
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 03/11/2025
// Archivo lector_gramatica.h
// Referencias: https://google.github.io/styleguide/cppguide.html

#ifndef LECTOR_GRAMATICA_H
#define LECTOR_GRAMATICA_H

#include <string>
#include "../include/gramatica.h"

/**
 * @brief Clase encargada de leer una gramática desde un fichero
 *        y construir el objeto correspondiente.
 */
class LectorGramatica {
 public:
  LectorGramatica() = default;

  /**
   * @brief Genera una gramática a partir del contenido de un fichero.
   * @param fichero_entrada Ruta al fichero de entrada.
   * @param gramatica Referencia al objeto donde se almacenará la gramática.
   */
  void GenerarGramatica(std::string fichero_entrada, Gramatica& gramatica);
};

#endif  // LECTOR_GRAMATICA_H
