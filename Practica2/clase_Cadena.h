#ifndef CLASE_CADENA_H
#define CLASE_CADENA_H

#include <iostream>
#include <fstream>
#include <set>
#include <string>

#include "clase_Simbolo.h"

class Cadena : public Simbolo{
 public:
  // Constructor
  Cadena() : cadenaLeida_() {}
  Cadena(std::string cadenaLeida) : cadenaLeida_(cadenaLeida) {}
  // Getters
  std::string GetCadena() const { return cadenaLeida_; }
  // Setter
  void SetCadena(const std::string cadena) { cadenaLeida_ = cadena; }
  // Funciones de comparación
  bool operator<(const Cadena& otro) const { return cadenaLeida_.size() < otro.cadenaLeida_.size(); }
  bool operator==(const Cadena& otro) const { return cadenaLeida_.size() == otro.cadenaLeida_.size(); }
  // Funciones útiles
  int ObtenerLongitud();
  std::string ObtenerInversa();
  // Sobrecarga de operadores
  friend std::ostream& operator<<(std::ostream& os, const Cadena& otro);
  friend std::istream& operator>>(std::istream& is, Cadena& otro);
 private:
  std::string cadenaLeida_;
};

#endif