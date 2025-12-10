/**
 * @file point_types.h
 * @brief Definiciones de tipos para el algoritmo QuickHull.
 */

#ifndef CYA_POINT_TYPES_H_
#define CYA_POINT_TYPES_H_

#include <utility>
#include <vector>

namespace CyA {

using Point = std::pair<double, double>;
using Line = std::pair<Point, Point>;
using PointVector = std::vector<Point>;

// Tolerancia para comparaciones de punto flotante
const double kEpsilon = 1e-9;

enum Side {
  kLeft = -1,
  kCenter = 0,
  kRight = 1
};

}  // namespace CyA

#endif  // CYA_POINT_TYPES_H_