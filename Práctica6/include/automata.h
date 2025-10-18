// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 18/10/2025
// Archivo automata.h: Programa encargado de declarar los atributos y las
// fucniones que tendra la clase automata.
// Referencias:
// https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#ifndef AUTOMATA_H
#define AUTOMATA_H

#include "../include/estructura.h"
#include "string"

class Automata {
 public:
  Automata() = default;
  void DefinirAutomata(const std::string& FicheroDeEntrada,
                       Estructura& estructura);

 private:
  void DetectarAlfabeto(std::ifstream& FicheroLectura, Estructura& estructura);
  void DetectarTotalEstadosYEstadoInicial(std::ifstream& FicheroLectura,
                                          Estructura& estructura);
  void DetectarEstados(std::ifstream& FicheroLectura, Estructura& estructura);
};

#endif