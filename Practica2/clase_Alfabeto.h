#ifndef CLASE_ALFABETO_H
#define CLASE_ALFABETO_H

#include <iostream>
#include <fstream>
#include <set>

#include "clase_Simbolo.h"

class Alfabeto : public Simbolo {
 public:
  // Constructor
  Alfabeto() : alfabeto_() {}
  Alfabeto(std::set<Simbolo> alfabeto) : alfabeto_(alfabeto) {}
  // Getter
  std::set<Simbolo> GetAlfabeto() const { return alfabeto_; }
  // Funciones de utilidad
  void Alfabeto::CrearAlfabeto(const std::string cadena);
  bool PerteneceAlAlfabeto(const Simbolo& simbolo) const;
  // Sobrecarga de operadores
  friend std::ostream& operator<<(std::ostream& os, const Alfabeto& otro);
 private:
  std::set<Simbolo> alfabeto_; // Conjunto de símbolos
};

#endif