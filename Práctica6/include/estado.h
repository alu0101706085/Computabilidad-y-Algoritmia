#ifndef ESTADO_H
#define ESTADO_H

#include <set>

#include "transicion.h"

class Estado {
 public:
  Estado() = default;
  Estado(int numero_estado, bool es_final, int numero_transiciones,
         std::set<Transicion> transiciones)
      : numero_estado_(numero_estado),
        es_final_(es_final),
        numero_transiciones_(numero_transiciones),
        transiciones_(transiciones) {}
  // Getters
  unsigned GetNumeroEstado() const { return numero_estado_; }
  bool GetEsAceptado() const { return es_final_; }
  int GetNumeroTransiciones() const { return numero_transiciones_; }
  std::set<Transicion> GetSetTransiciones() const { return transiciones_; }
  // Setters
  void SetNumeroEstado(unsigned numero_estados) { numero_estado_ = numero_estados; }
  void SetEsAceptado(bool es_final) { es_final_ = es_final; }
  void SetNumeroTransiciones(int numero_transiciones) {
    numero_transiciones_ = numero_transiciones;
  }
  void SetSetTranscion(std::set<Transicion> transiciones) {
    transiciones_ = transiciones;
  }
  // Sobrecarga de operadores
  bool operator<(const Estado& otro) {
    return numero_estado_ < otro.numero_estado_;
  }
  friend std::istream& operator>>(std::istream& is, Estado& estado) {
    is >> estado.numero_estado_;
    return is;
  }
 private:
  unsigned numero_estado_;
  bool es_final_;
  int numero_transiciones_;
  std::set<Transicion> transiciones_;
};

#endif