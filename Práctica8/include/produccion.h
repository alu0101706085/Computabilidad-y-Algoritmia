#ifndef PRODUCCION_H
#define PRODUCCION_H

#include "../include/simbolo.h"

#include <vector>

class Produccion {
 public:
  // Contructor
  Produccion() = default;
  // Getters
  Simbolo GetSimbolo() const { return no_terminal_; }
  std::vector<Simbolo> GetSecuencia() const { return secuencia_; }
  // Setters
  void SetSimbolo(Simbolo no_terminal) { no_terminal_ = no_terminal; }
  void SetSecuencia(std::vector<Simbolo> secuencia) { secuencia_ = secuencia; }
  // Métodos
  bool EsUnitaria() const;
  // Sobrecarga de E/S
  friend std::ostream& operator<<(std::ostream& os, const Produccion& produccion);
  friend std::istream& operator>>(std::istream& is, Produccion& produccion);
 private:
  Simbolo no_terminal_;
  std::vector<Simbolo> secuencia_;
};
 
#endif