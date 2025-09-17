#ifndef CLASE_SIMBOLO_H
#define CLASE_SIMBOLO_H

#include <iostream>
#include <fstream>
#include <string>

class Simbolo {
 public:
  // Constructor
  Simbolo() : simboloLeido_() {}
  Simbolo(char simboloLeido) : simboloLeido_(simboloLeido) {}
  // Getters
  char GetSimbolo() const;
  //Funciones de utilidad
  bool esMayor(const char letra);
  // Sobrecarga de operadores
  friend std::ostream& operator<<(std::ostream& os, const Simbolo& otro);
  friend std::istream& operator>>(std::istream& is, Simbolo& otro);
 private:
  char simboloLeido_;
};

#endif