#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <iostream>

class Simbolo {
 public:
  Simbolo() = default;
  Simbolo(std::string caracter, bool es_terminal) : simbolo_(caracter), es_terminal_(es_terminal) {}
  // Getter
  std::string GetSimbolo() const { return simbolo_; }
  bool GetEsTerminal() const { return es_terminal_; }
  // Setter
  void SetSimbolo (const Simbolo& simbolo) { simbolo_ = simbolo.GetSimbolo(); }
  void SetEsTerminal(bool es_terminal) { es_terminal_ = es_terminal; }
  // Operadores de comparación
  bool operator<(const Simbolo& otro) const { return simbolo_ < otro.simbolo_; }
  bool operator==(const Simbolo& otro) const {
    return simbolo_ == otro.simbolo_;
  }
  bool operator!=(const Simbolo& otro) const {
    return simbolo_ != otro.simbolo_;
  }
  // Sobrecarga de E/S
  friend std::ostream& operator<<(std::ostream& os, const Simbolo& simbolo);
  friend std::istream& operator>>(std::istream& is, Simbolo& simbolo);
 private:
  std::string simbolo_;
  bool es_terminal_;
};

#endif