// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: David Javier Rodríguez Fumero 
// Correo: alu0101706085@ull.edu.es
// Fecha: 19/09/2025
// Archivo clase_Cadena.h: programa de declaración de la clase lenguaje.
// Contiene las declaraciones de la clase lenguaje para poder definirlas
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

#ifndef CLASE_LENGUAJE_H
#define CLASE_LENGUAJE_H

#include <iostream>
#include <set>

#include "clase_Cadena.h" 

class Lenguaje : public Cadena{
 public:
  // Constructores
  Lenguaje() = default;
  explicit Lenguaje(const std::set<Cadena>& cadenas);
  // Getter (devuelve referencia constante para eficiencia)
  const std::set<Cadena>& GetPrefijos() const { return lenguaje_; }
  const std::set<Cadena>& GetSufijos() const { return lenguaje_; }
  // Funciones útiles
  void CalcularPrefijos(const std::string cadena);
  void CalcularSufijos(const std::string cadena);
  // Sobrecarga de operadores de E/S
  friend std::ostream& operator<<(std::ostream& os, const Lenguaje& lenguaje);
  // No se necesita operator>> para esta práctica (solo salida)
 private:
  std::set<Cadena> lenguaje_;  // Conjunto de cadenas
};

#endif