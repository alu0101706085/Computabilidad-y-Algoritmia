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
  std::string GetAlfabeto();
  // Función de utilidad
  void MeterSimbolos(const std::string alfabeto);
  // Sobrecarga de operadores
  friend std::ostream& operator<<(std::ostream& os, const Alfabeto& otro);
  friend std::istream& operator>>(std::istream& is, Alfabeto& otro);
 private:
  std::set<Simbolo> alfabeto_; // Conjunto de símbolos
  std::string alfabeto;
};

#endif