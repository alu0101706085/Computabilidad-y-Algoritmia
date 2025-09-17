#include <iostream>
#include <sstream>

#include "clase_Alfabeto.h"

// Función que verifica si un símbolo pertenece al alfabeto
bool Alfabeto::PerteneceAlAlfabeto(const Simbolo& simbolo) const {
    return alfabeto_.find(simbolo) != alfabeto_.end();
}
// Función que lee una cadena y procesa cada carácter como símbolo
void Alfabeto::LeerCadena(const std::string cadena) {
    for (char caracter : cadena) {
        Simbolo simbolo(caracter);
        // Solo añadimos si no está ya en el alfabeto
        if (alfabeto_.find(simbolo) == alfabeto_.end()) {
            alfabeto_.insert(simbolo);
        }
    }
}
// Sobrecarga del operador de salida
std::ostream& operator<<(std::ostream& os, const Alfabeto& otro) {
    os << "{ ";
    for (auto elemento = otro.alfabeto_.begin(); elemento != otro.alfabeto_.end(); ++elemento) {
        os << *elemento;
        if (std::next(elemento) != otro.alfabeto_.end()) {
            os << ", ";
        }
    }
    os << " }";
    return os;
}
// Sobrecarga del operador de entrada
std::istream& operator>>(std::istream& is, Alfabeto& otro) {
  std::string linea;
  std::getline(is, linea);
  // Limpiar el alfabeto actual
  otro.alfabeto_.clear();
  // Usar un stringstream para dividir la línea en palabras
  std::stringstream ss(linea);
  std::string primeraPalabra, alfabetoStr;
  // Leer las dos palabras
  ss >> primeraPalabra >> alfabetoStr;
  // Si no hay segunda palabra, salir
  if (alfabetoStr.empty()) {
    return is;
  }
  // Procesar cada carácter de la segunda palabra (el alfabeto)
  for (char c : alfabetoStr) {
    Simbolo simbolo(c);
    otro.alfabeto_.insert(simbolo);
  } 
  return is;
}