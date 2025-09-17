#ifndef CLASE_CADENA_H
#define CLASE_CADENA_H

#include <iostream>
#include <fstream>
#include <string>

class Cadena {
 public:
  // Constructor
  Cadena() : cadena_leida_() {}
  Cadena(std::string letra_leida) : cadena_leida_(letra_leida) {}
  void LeerCadena(std::string cadena_leida, std::string linea);
  // Getters
  std::string GetCadena() const;
  // Sobrecarga de operadores
  friend std::ostream& operator<<(std::ostream& os, const Cadena& otro);
  friend std::istream& operator>>(std::istream& is, Cadena& otro);
 private:
  std::string cadena_leida_;
};

#endif