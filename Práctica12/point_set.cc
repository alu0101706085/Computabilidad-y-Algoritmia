/**
 * @file point_set.cc
 * @brief Implementación de la lógica de QuickHull.
 */

#include "point_set.h"

#include <algorithm>
#include <cmath>
#include <iomanip>

namespace CyA {

PointSet::PointSet(const PointVector& points) : points_(points) {}

void PointSet::QuickHull() {
  hull_.clear();
  if (points_.size() < 3) {
    hull_ = points_;
    return;
  }

  Point min_x, max_x;
  GetXBounds(min_x, max_x);

  // Añadimos extremos iniciales
  hull_.push_back(min_x);
  hull_.push_back(max_x);

  // Llamadas recursivas para ambos lados de la línea base
  QuickHull(Line(min_x, max_x), kLeft);
  QuickHull(Line(min_x, max_x), kRight);

  // Ordenamos y eliminamos duplicados para tener una envoltura limpia
  std::sort(hull_.begin(), hull_.end());
  auto last = std::unique(hull_.begin(), hull_.end());
  hull_.erase(last, hull_.end());
}

void PointSet::QuickHull(const Line& line, int side) {
  Point farthest;
  if (GetFarthestPoint(line, side, farthest)) {
    hull_.push_back(farthest);
    
    // Divide y vencerás: nuevos triángulos formados por el punto lejano
    // El "lado" a buscar es el opuesto a donde queda el otro punto del triángulo base
    QuickHull(Line(line.first, farthest), 
              -FindSide(Line(line.first, farthest), line.second));
    QuickHull(Line(farthest, line.second), 
              -FindSide(Line(farthest, line.second), line.first));
  }
}

void PointSet::GetXBounds(Point& min_x, Point& max_x) const {
  if (points_.empty()) return;
  min_x = max_x = points_[0];

  for (const auto& p : points_) {
    if (p.first < min_x.first) min_x = p;
    if (p.first > max_x.first) max_x = p;
  }
}

double PointSet::PointToLine(const Line& line, const Point& p) const {
  return (p.second - line.first.second) * (line.second.first - line.first.first) -
         (line.second.second - line.first.second) * (p.first - line.first.first);
}

int PointSet::FindSide(const Line& line, const Point& p) const {
  double val = PointToLine(line, p);
  if (val > kEpsilon) return kLeft;
  if (val < -kEpsilon) return kRight;
  return kCenter;
}

double PointSet::Distance(const Line& line, const Point& p) const {
  return std::abs(PointToLine(line, p));
}

bool PointSet::GetFarthestPoint(const Line& line, int side, Point& farthest) const {
  double max_dist = -1.0;
  bool found = false;

  for (const auto& p : points_) {
    double dist = Distance(line, p);
    if (FindSide(line, p) == side && dist > max_dist) {
      farthest = p;
      max_dist = dist;
      found = true;
    }
  }
  return found;
}

void PointSet::WriteHull(std::ostream& os) const {
  for (const auto& p : hull_) {
    os << p.first << " " << p.second << "\n";
  }
}

void PointSet::WriteDot(std::ostream& os) const {
  os << "graph \"Convex Hull\" {\n";
  os << "  layout=neato;\n"; // Usar layout neato para coordenadas exactas
  os << "  node [shape=circle, width=0.1, style=filled, fillcolor=lightgrey];\n";

  // 1. Dibujar todos los puntos
  int i = 0;
  for (const auto& p : points_) {
    os << "  n" << i++ << " [pos=\"" << p.first << "," << p.second << "!\"];\n";
  }

  // 2. Dibujar las aristas de la envoltura
  // Para dibujar el polígono, necesitamos que los puntos estén ordenados angularmente.
  // El algoritmo QuickHull básico devuelve puntos, pero no siempre en orden angular perfecto.
  // Para la visualización perfecta, calculamos el centroide y ordenamos angularmente.
  
  if (hull_.size() > 1) {
    Point center = {0, 0};
    for (const auto& p : hull_) { center.first += p.first; center.second += p.second; }
    center.first /= hull_.size();
    center.second /= hull_.size();

    PointVector sorted_hull = hull_;
    std::sort(sorted_hull.begin(), sorted_hull.end(), [&](const Point& a, const Point& b) {
        return atan2(a.second - center.second, a.first - center.first) <
               atan2(b.second - center.second, b.first - center.first);
    });

    os << "  edge [color=red, penwidth=2.0];\n";
    for (size_t j = 0; j < sorted_hull.size(); ++j) {
      // Encontrar IDs originales es costoso pero necesario para DOT exacto
      // (O simplemente dibujamos nodos nuevos encima)
      os << "  \"" << sorted_hull[j].first << "," << sorted_hull[j].second << "\" -- \"" 
         << sorted_hull[(j + 1) % sorted_hull.size()].first << "," 
         << sorted_hull[(j + 1) % sorted_hull.size()].second << "\";\n";
      
      // Nodo de envoltura en rojo
      os << "  \"" << sorted_hull[j].first << "," << sorted_hull[j].second 
         << "\" [pos=\"" << sorted_hull[j].first << "," << sorted_hull[j].second 
         << "!\" fillcolor=red width=0.15];\n";
    }
  }

  os << "}\n";
}

}  // namespace CyA