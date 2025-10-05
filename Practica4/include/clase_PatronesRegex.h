// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares en C++
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 07/10/2025
// Archivo clase_PatronesRegex.h: Programa encargado de definir como 
// constantes los lenguajes regulares.
// Referencias:
// https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#ifndef CLASE_PATRONESREGEX
#define CLASE_PATRONESREGEX

#include <iostream>
#include <regex>

class PatronesRegex {
 public:
  static const std::regex INT_VARIABLE_REGEX;
  static const std::regex DOUBLE_VARIABLE_REGEX;
  static const std::regex FOR_LOOP_REGEX;
  static const std::regex WHILE_LOOP_REGEX;
  static const std::regex SINGLE_LINE_COMMENT_REGEX;
  static const std::regex MULTI_LINE_COMMENT_START_REGEX;
  static const std::regex MULTI_LINE_COMMENT_END_REGEX;
  static const std::regex MAIN_FUNCTION_REGEX;
};

#endif