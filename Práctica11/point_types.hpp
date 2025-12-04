#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include <set>

#define MAX_COORD_WIDTH 3
#define MAX_PRECISION 4

namespace CyA {

  // Definición de tipos básicos
  using Point = std::pair<double, double>;
  using PointVector = std::vector<Point>;
  using PointCollection = std::set<Point>;

  // Arcos: Un par de puntos
  using Arc = std::pair<Point, Point>;
  
  // Arco Ponderado: Un par (peso, arco)
  using WeightedArc = std::pair<double, Arc>;
  using ArcVector = std::vector<WeightedArc>;
  
  // Árbol: Un vector de arcos
  using Tree = std::vector<Arc>;

}  // namespace CyA

// Sobrecarga de operadores de flujo para entrada/salida
std::ostream& operator<<(std::ostream& os, const CyA::PointVector& points);
std::ostream& operator<<(std::ostream& os, const CyA::Point& point);

std::istream& operator>>(std::istream& is, CyA::PointVector& points);
std::istream& operator>>(std::istream& is, CyA::Point& point);