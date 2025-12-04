#include "point_types.hpp"

#include <iomanip>

std::ostream& operator<<(std::ostream& os, const CyA::PointVector& points) {
  os << points.size() << std::endl;

  for (const CyA::Point& point : points) {
    os << point << std::endl;
  }

  return os;
}

std::ostream& operator<<(std::ostream& os, const CyA::Point& point) {
  os << std::setw(MAX_COORD_WIDTH) << std::fixed << std::setprecision(MAX_PRECISION) 
     << point.first << "\t" 
     << std::setw(MAX_COORD_WIDTH) << std::fixed << std::setprecision(MAX_PRECISION) 
     << point.second;

  return os;
}

std::istream& operator>>(std::istream& is, CyA::PointVector& points) {
  int number_of_points;
  is >> number_of_points;

  points.clear();

  for (int i = 0; i < number_of_points; ++i) {
    CyA::Point point;
    is >> point;
    points.push_back(point);
  }

  return is;
}

std::istream& operator>>(std::istream& is, CyA::Point& point) {
  is >> point.first >> point.second;
  return is;
}