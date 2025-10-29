#include "../include/simbolo.h"

#include <iostream>

std::ostream& operator<<(std::ostream& os, const Simbolo& simbolo) {
  os << simbolo.simbolo_;
  return os;
}
std::istream& operator>>(std::istream& is, Simbolo& simbolo) {
  is >> simbolo.simbolo_;
  return is;
}