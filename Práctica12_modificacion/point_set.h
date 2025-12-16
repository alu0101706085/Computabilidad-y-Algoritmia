/**
 * @file point_set.h
 * @brief Clase PointSet con contador de recursividad.
 */

#ifndef CYA_POINT_SET_H_
#define CYA_POINT_SET_H_

#include <iostream>
#include <vector>
#include "point_types.h"

namespace CyA {

class PointSet {
 public:
  explicit PointSet(const PointVector& points);
  void QuickHull();
  void WriteHull(std::ostream& os) const;
  void WriteDot(std::ostream& os) const;

  const PointVector& GetHull() const { return hull_; }

 private:
  PointVector points_;
  PointVector hull_;
  
  // MODIFICACIÓN: Variable para contar las llamadas
  int recursive_calls_;

  void QuickHull(const Line& line, int side);
  double Distance(const Line& line, const Point& p) const;
  int FindSide(const Line& line, const Point& p) const;
  double PointToLine(const Line& line, const Point& p) const;
  bool GetFarthestPoint(const Line& line, int side, Point& farthest) const;
  void GetXBounds(Point& min_x, Point& max_x) const;
};

}  // namespace CyA

#endif