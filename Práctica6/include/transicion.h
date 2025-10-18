// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 18/10/2025
// Archivo transicion.h: Programa encargado de declarar los atributos y las
// fucniones que tendra la clase transicion.
// Referencias:
// https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#ifndef TRANSICION_H
#define TRANSICION_H

class Transicion {
 public:
  Transicion() = default;
  Transicion(int destino, char valor_transicion)
      : destino_(destino), valor_transicion_(valor_transicion) {}
  // Getters
  int GetDestino() const { return destino_; }
  char GetValorTransicion() const { return valor_transicion_; }
  // Setters
  void SetDestino(int destino) { destino_ = destino; }
  void SetValorTransicion(char valor_transicion) {
    valor_transicion_ = valor_transicion;
  }
  // Sobrecarga de operadores
  bool operator<(const Transicion& otro) const {
    if (valor_transicion_ == otro.valor_transicion_)
      return destino_ < otro.destino_;
    return valor_transicion_ < otro.valor_transicion_;
  }
  friend std::istream& operator>>(std::istream& is, Transicion& transicion) {
    is >> transicion.valor_transicion_;
    return is;
  }

 private:
  int destino_;
  char valor_transicion_;
};

#endif