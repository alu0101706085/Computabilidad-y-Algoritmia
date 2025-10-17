#ifndef ESTADO_H
#define ESTADO_H

#include <iostream>
#include <set>
#include "transicion.h"  // Incluir transicion.h

class Estado {
 public:
  Estado() : identificador_(-1), aceptacion_(false) {}
  Estado(int identificador, bool aceptacion = false) 
      : identificador_(identificador), aceptacion_(aceptacion) {}

  int GetIdentificador() const { return identificador_; }
  bool EsFinal() const { return aceptacion_; }
  std::set<Transicion> GetSetTransiciones() const { return transiciones_; }

  void SetIdentificador(int identificador) { identificador_ = identificador; }
  void SetAceptacion(bool aceptacion) { aceptacion_ = aceptacion; }
  void SetTransiciones(const std::set<Transicion>& transiciones) { 
    transiciones_ = transiciones; 
  }
  void AgregarTransicion(const Transicion& transicion) {
    transiciones_.insert(transicion);
  }

  bool operator<(const Estado& otro) const {
    return identificador_ < otro.identificador_;
  }

  bool operator==(const Estado& otro) const {
    return identificador_ == otro.identificador_;
  }
  friend std::istream& operator>>(std::istream& is, Estado& estado);
  friend std::ostream& operator<<(std::ostream& os, const Estado& estado);
 private:
  int identificador_;
  bool aceptacion_;
  std::set<Transicion> transiciones_;
};



#endif  // ESTADO_H