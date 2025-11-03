// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramáticas en Forma Normal de Chomsky
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 03/11/2025
// Archivo gramatica.h
// Referencias: https://google.github.io/styleguide/cppguide.html

#ifndef GRAMATICA_H
#define GRAMATICA_H

#include "../include/simbolo.h"
#include "../include/produccion.h"

#include <set>
#include <vector>

/**
 * @brief Representa una gramática formal y permite su transformación
 *        a la Forma Normal de Chomsky (FNC).
 */
class Gramatica {
 public:
  Gramatica() = default;
  // Getters
  std::set<Simbolo> GetNoTerminales() const { return no_terminales_; }
  std::set<Simbolo> GetTerminales() const { return terminales_; }
  Simbolo GetEstadoArranque() const { return estado_arranque_; }
  std::vector<Produccion> GetProducciones() const { return producciones_; }
  // Setters
  void SetEstadoArranque(Simbolo& simbolo) { estado_arranque_ = simbolo; }
  // Métodos públicos
  void AddNoTerminal(Simbolo& simbolo) { no_terminales_.insert(simbolo); }
  void AddTerminal(Simbolo& simbolo) { terminales_.insert(simbolo); }
  void AddProduccion(Produccion& otro) { producciones_.emplace_back(otro); }
  /// @brief Transforma la gramática a FNC, si es posible.
  void TransformarGramatica();
 private:
  // Métodos auxiliares
  bool TieneProduccionesUnitarias();
  bool TieneEpsilonProducciones();
  void ConvertirFormaNormalChomsky();
  // Atributos
  std::set<Simbolo> terminales_;
  std::set<Simbolo> no_terminales_;
  Simbolo estado_arranque_;
  std::vector<Produccion> producciones_;
};

#endif  // GRAMATICA_H
