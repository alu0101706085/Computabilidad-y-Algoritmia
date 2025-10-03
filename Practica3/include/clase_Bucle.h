#ifndef CLASE_BUCLE
#define CLASE_BUCLE

#include <iostream>
#include <string>

enum class TipoBucle { BUCLE_FOR, BUCLE_WHILE };

class Bucle {
 public:
  Bucle() = default;
  Bucle(TipoBucle tipo, int numero_linea)
      : tipo_(tipo), numero_linea_(numero_linea) {}
  // Getters
  TipoBucle GetTipo() const { return tipo_; }
  int GetNumeroLinea() const { return numero_linea_; }
  // Setters
  void SetTipo(const TipoBucle& tipo) { tipo_ = tipo; }
  void SetNumeroLinea(const int numero_linea) { numero_linea_ = numero_linea; }
 private:
  TipoBucle tipo_;
  int numero_linea_;
};

#endif