#ifndef CLASE_SIMBOLO_H
#define CLASE_SIMBOLO_H

#include <iostream>

class Simbolo {
 public:
  Simbolo() : simbolo_('\0') {}  // Inicializar a valor por defecto
  Simbolo(char caracter) : simbolo_(caracter) {}
  // Getter 
  char GetSimbolo() const { return simbolo_; }
  // Operadores de comparación
  bool operator<(const Simbolo& otro) const { return simbolo_ < otro.simbolo_; }
  bool operator==(const Simbolo& otro) const { return simbolo_ == otro.simbolo_; }
  // Sobrecarga de E/S
  friend std::ostream& operator<<(std::ostream& os, const Simbolo& simbolo);
  friend std::istream& operator>>(std::istream& is, Simbolo& simbolo);
 private:
  char simbolo_;
};

#endif