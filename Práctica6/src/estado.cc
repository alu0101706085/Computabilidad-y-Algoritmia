#include "../include/estado.h"

std::istream& operator>>(std::istream& is, Estado& estado) {
  is >> estado.identificador_ >> estado.aceptacion_;
  return is;
}

std::ostream& operator<<(std::ostream& os, const Estado& estado) {
  os << estado.identificador_ << " " << estado.aceptacion_;
  return os;
}