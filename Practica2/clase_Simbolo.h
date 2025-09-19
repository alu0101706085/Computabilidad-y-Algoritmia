// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: David Javier Rodríguez Fumero 
// Correo: alu0101706085@ull.edu.es
// Fecha: 19/09/2025
// Archivo clase_Cadena.h: programa de declaración de la clase simbolo.
// Contiene las declaraciones de la clase simbolo para poder definirlas
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

#ifndef CLASE_SIMBOLO_H
#define CLASE_SIMBOLO_H

#include <iostream>

class Simbolo {
 public:
  Simbolo() : simbolo_('\0') {}  // Inicializar a valor por defecto
  Simbolo(char caracter) : simbolo_(caracter) {}
  // Getter 
  char GetSimbolo() const { return simbolo_; }
  // Operadores de comparación
  bool operator<(const Simbolo& otro) const { return simbolo_ < otro.simbolo_; }
  bool operator==(const Simbolo& otro) const { return simbolo_ == otro.simbolo_; }
  // Sobrecarga de E/S
  friend std::ostream& operator<<(std::ostream& os, const Simbolo& simbolo);
  friend std::istream& operator>>(std::istream& is, Simbolo& simbolo);
 private:
  char simbolo_;
};

#endif