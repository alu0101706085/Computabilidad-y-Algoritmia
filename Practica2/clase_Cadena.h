#ifndef CLASE_CADENA_H
#define CLASE_CADENA_H

#include <iostream>
#include <fstream>
#include <string>

class Cadena : public Simbolo {
 public:
  // Constructor
  Cadena() : cadenaLeida_() {}
  Cadena(std::string cadenaLeida) : cadenaLeida_(cadenaLeida) {}
  // Getters
  std::string GetCadena() const;
  // Funciones útiles
  int ObtenerLongitud();
  std::string ObtenerCadena();
  // Sobrecarga de operadores
  friend std::ostream& operator<<(std::ostream& os, const Cadena& otro);
  friend std::istream& operator>>(std::istream& is, Cadena& otro);
 private:
  std::string cadenaLeida_;
};

#endif