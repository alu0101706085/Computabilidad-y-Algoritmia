// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramáticas en Forma Normal de Chomsky
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 03/11/2025
// Archivo escritor_gramatica.h
// Referencias: https://google.github.io/styleguide/cppguide.html

#ifndef ESCRITOR_GRAMATICA_H
#define ESCRITOR_GRAMATICA_H

#include <string>
#include <fstream>

#include "../include/gramatica.h"

/**
 * @brief Clase responsable de escribir una gramática en un fichero,
 *        específicamente en su Forma Normal de Chomsky (FNC).
 */
class EscritorGramatica {
 public:
  EscritorGramatica() = default;
  /**
   * @brief Escribe la gramática en FNC en un fichero de salida.
   * @param fichero_salida Nombre del fichero donde se guardará la gramática.
   * @param gramatica Objeto de tipo Gramatica que será escrito.
   */
  void EscribirFNC(std::string fichero_salida, Gramatica& gramatica);
 private:
  /// @brief Escribe una producción de forma compacta en el fichero.
  void EscribirProduccionCompacta(std::ofstream& out, const Produccion& p);
};

#endif  // ESCRITOR_GRAMATICA_H
