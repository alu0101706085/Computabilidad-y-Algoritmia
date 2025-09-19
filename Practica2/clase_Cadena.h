// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: David Javier Rodríguez Fumero 
// Correo: alu0101706085@ull.edu.es
// Fecha: 19/09/2025
// Archivo clase_Cadena.h: programa de declaración de la clase cadena.
// Contiene las declaraciones de la clase cadena para poder definirlas
// en su .cc y trabajar con ellas.
// Objetivos del Proyecto: Definir el uso de la clase y sus capacidades.
// Estructura de Datos Utilizadas:
// Referencias:
// Enlaces de inter´es
//
// Historial de revisiones
// 16/09/2025 - Creaci´on (primera versi´on) del c´odigo
// 17/09/2025 - Avance con las clases simbolo y alfabeto
// 18/09/2025 - Avance con las clases cadena, lenguaje y el main
// 19/09/2025 - Obtención de los resultados esperados

#ifndef CLASE_CADENA_H
#define CLASE_CADENA_H

#include <iostream>
#include <fstream>
#include <set>
#include <string>

#include "clase_Simbolo.h"

class Cadena : public Simbolo{
 public:
  // Constructor
  Cadena() : cadenaLeida_() {}
  Cadena(std::string cadenaLeida) : cadenaLeida_(cadenaLeida) {}
  // Getters
  std::string GetCadena() const { return cadenaLeida_; }
  // Setter
  void SetCadena(const std::string cadena) { cadenaLeida_ = cadena; }
  // Funciones de comparación
  bool operator<(const Cadena& otro) const { return cadenaLeida_.size() < otro.cadenaLeida_.size(); }
  bool operator==(const Cadena& otro) const { return cadenaLeida_.size() == otro.cadenaLeida_.size(); }
  // Funciones útiles
  int ObtenerLongitud();
  std::string ObtenerInversa();
  // Sobrecarga de operadores
  friend std::ostream& operator<<(std::ostream& os, const Cadena& otro);
  friend std::istream& operator>>(std::istream& is, Cadena& otro);
 private:
  std::string cadenaLeida_;
};

#endif