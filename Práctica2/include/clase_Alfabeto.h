// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 22/09/2025
// Archivo clase_Alfabeto.h: programa de declaración de la clase alfabeto.
// Contiene las declaraciones de la clase alfabeto para poder definirlas
// en su .cc y trabajar con ellas.
// Objetivos del Proyecto: Definir el uso de la clase y sus capacidades.
// Referencias: https://google.github.io/styleguide/cppguide.html
// Enlaces de inter´es: https://google.github.io/styleguide/cppguide.html
//
// Historial de revisiones
// 16/09/2025 - Creaci´on (primera versi´on) del c´odigo
// 17/09/2025 - Avance con las clases simbolo y alfabeto
// 18/09/2025 - Avance con las clases cadena, lenguaje y el main
// 19/09/2025 - Obtención de los resultados esperados
// 21/09/2025 - Mejoras en el main con restricciones y ayudas
// 22/09/2025 - Introduccion de constantes y mejorar la apliación de la guia de
// estilo de Google

#ifndef CLASE_ALFABETO_H
#define CLASE_ALFABETO_H

#include <fstream>
#include <iostream>
#include <set>

#include "clase_Simbolo.h"

class Alfabeto : public Simbolo {
 public:
  // Constructor
  Alfabeto() : alfabeto_() {}
  Alfabeto(std::set<Simbolo> alfabeto) : alfabeto_(alfabeto) {}
  // Getter
  std::set<Simbolo> GetAlfabeto() const { return alfabeto_; }
  // Funciones de utilidad
  void CrearAlfabeto(const std::string cadena);
  bool PerteneceAlAlfabeto(const Simbolo& simbolo) const;
  // Sobrecarga de operadores
  friend std::ostream& operator<<(std::ostream& os, const Alfabeto& otro);

 private:
  std::set<Simbolo> alfabeto_;  // Conjunto de símbolos
};

#endif