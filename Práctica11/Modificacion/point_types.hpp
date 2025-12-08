/**
 * @file point_types.hpp
 * @brief Definición de tipos de datos básicos para geometría computacional.
 */

#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include <set>

#define MAX_ANCHO_COORD 3
#define MAX_PRECISION 4

namespace CyA {

  /** @brief Representa un punto en el plano 2D (x, y). */
  using Punto = std::pair<double, double>;

  /** @brief Vector de puntos. */
  using VectorPuntos = std::vector<Punto>;

  /** @brief Conjunto de puntos (para búsquedas rápidas). */
  using ColeccionPuntos = std::set<Punto>;

  /** @brief Representa una arista (conexión entre dos puntos). */
  using Arista = std::pair<Punto, Punto>;

  /** @brief Representa una arista con peso (peso, arista). */
  using AristaPonderada = std::pair<double, Arista>;

  /** @brief Vector de aristas ponderadas. */
  using VectorAristas = std::vector<AristaPonderada>;

  /** @brief Un árbol es un vector de aristas. */
  using Arbol = std::vector<Arista>;

}  // namespace CyA

// Sobrecarga de operadores de flujo
std::ostream& operator<<(std::ostream& os, const CyA::VectorPuntos& puntos);
std::ostream& operator<<(std::ostream& os, const CyA::Punto& punto);
std::istream& operator>>(std::istream& is, CyA::VectorPuntos& puntos);
std::istream& operator>>(std::istream& is, CyA::Punto& punto);