/**
 * @file point_set.cc
 * @brief Implementación de la lógica de QuickHull.
 */

#include "point_set.h"
#include <algorithm>
#include <cmath>
#include <iomanip>

namespace CyA {

// Inicializamos el contador a 0 en el constructor por seguridad
PointSet::PointSet(const PointVector& points) : points_(points), recursive_calls_(0) {}
void PointSet::QuickHull() {
  hull_.clear();
  
  recursive_calls_ = 0; // Resetear el contador al empezar

  if (points_.size() < 3) {
    hull_ = points_;
    return;
  }

  Point min_x, max_x;
  GetXBounds(min_x, max_x);

  hull_.push_back(min_x);
  hull_.push_back(max_x);

  // Llamadas iniciales (fuera de la recursión pura)
  QuickHull(Line(min_x, max_x), kLeft);
  QuickHull(Line(min_x, max_x), kRight);

  std::cout << "NÚMERO DE LLAMADAS RECURSIVAS: " << recursive_calls_ << std::endl; // Imprimir el resultado en la terminal

  std::sort(hull_.begin(), hull_.end());
  auto last = std::unique(hull_.begin(), hull_.end());
  hull_.erase(last, hull_.end());
}

void PointSet::QuickHull(const Line& line, int side) {
  recursive_calls_++; // Sumar 1 en cada entrada a la función

  Point farthest;
  if (GetFarthestPoint(line, side, farthest)) {
    hull_.push_back(farthest);
    
    // Llamadas recursivas
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
  os << "graph \"Convex Hull\" {\n  layout=neato;\n  node [shape=circle, width=0.1, style=filled, fillcolor=lightgrey];\n";
  int i = 0;
  for (const auto& p : points_) os << "  n" << i++ << " [pos=\"" << p.first << "," << p.second << "!\"];\n";
  if (hull_.size() > 1) {
    Point center = {0, 0};
    for (const auto& p : hull_) { center.first += p.first; center.second += p.second; }
    center.first /= hull_.size(); center.second /= hull_.size();
    PointVector sorted_hull = hull_;
    std::sort(sorted_hull.begin(), sorted_hull.end(), [&](const Point& a, const Point& b) {
        return atan2(a.second - center.second, a.first - center.first) < atan2(b.second - center.second, b.first - center.first);
    });
    os << "  edge [color=red, penwidth=2.0];\n";
    for (size_t j = 0; j < sorted_hull.size(); ++j) {
      os << "  \"" << sorted_hull[j].first << "," << sorted_hull[j].second << "\" -- \"" 
         << sorted_hull[(j + 1) % sorted_hull.size()].first << "," << sorted_hull[(j + 1) % sorted_hull.size()].second << "\";\n";
      os << "  \"" << sorted_hull[j].first << "," << sorted_hull[j].second << "\" [pos=\"" << sorted_hull[j].first << "," << sorted_hull[j].second << "!\" fillcolor=red width=0.15];\n";
    }
  }
  os << "}\n";
}

}  // namespace CyA