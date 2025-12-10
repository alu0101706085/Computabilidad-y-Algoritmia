/**
 * @file point_set.h
 * @brief Clase PointSet que encapsula el algoritmo Divide & Conquer.
 */

#ifndef CYA_POINT_SET_H_
#define CYA_POINT_SET_H_

#include <iostream>
#include <vector>
#include "point_types.h"

namespace CyA {

class PointSet {
 public:
  /**
   * @brief Constructor con el conjunto de puntos inicial.
   */
  explicit PointSet(const PointVector& points);

  ~PointSet() = default;

  /**
   * @brief Ejecuta el algoritmo QuickHull para encontrar la envoltura convexa.
   */
  void QuickHull();

  /**
   * @brief Escribe los puntos de la envoltura en la salida estándar.
   * @param os Flujo de salida.
   */
  void WriteHull(std::ostream& os) const;

  /**
   * @brief Genera el código DOT para visualizar en Graphviz.
   * @param os Flujo de salida donde escribir el DOT.
   */
  void WriteDot(std::ostream& os) const;

  const PointVector& GetHull() const { return hull_; }
  const PointVector& GetPoints() const { return points_; }

 private:
  PointVector points_;
  PointVector hull_;

  // Métodos privados del algoritmo
  void QuickHull(const Line& line, int side);
  double Distance(const Line& line, const Point& p) const;
  int FindSide(const Line& line, const Point& p) const;
  double PointToLine(const Line& line, const Point& p) const;
  bool GetFarthestPoint(const Line& line, int side, Point& farthest) const;
  void GetXBounds(Point& min_x, Point& max_x) const;
};

}  // namespace CyA

#endif  // CYA_POINT_SET_H_