#ifndef CLASE_LENGUAJE_H
#define CLASE_LENGUAJE_H

#include <iostream>
#include <set>

#include "clase_Cadena.h" 

class Lenguaje : public Cadena{
 public:
  // Constructores
  Lenguaje() = default;
  explicit Lenguaje(const std::set<Cadena>& cadenas);
  // Getter (devuelve referencia constante para eficiencia)
  const std::set<Cadena>& GetLenguaje() const { return lenguaje_; }
  // Crear Lenguaje
  void CrearLenguaje(const std::string cadena);
  // Insertar una cadena en el lenguaje
  void Insertar(const Cadena& cadena);
  // Funciones útiles
  std::set<Cadena> CalcularPrefijos();
  std::set<Cadena> CalcularSufijos();
  // Sobrecarga de operadores de E/S
  friend std::ostream& operator<<(std::ostream& os, const Lenguaje& lenguaje);
  // No se necesita operator>> para esta práctica (solo salida)
 private:
  std::set<Cadena> lenguaje_;  // Conjunto de cadenas
};

#endif