#ifndef TRANSICION_H
#define TRANSICION_H

class Estado;

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
  // 🔹 Comparador const (necesario para std::set)
  bool operator<(const Transicion& otro) const {
    if (valor_transicion_ == otro.valor_transicion_)
      return destino_ < otro.destino_;
    return valor_transicion_ < otro.valor_transicion_;
  }

  // 🔹 Sobrecarga de lectura solo para el símbolo
  //    (no intentamos leer un puntero a Estado)
  friend std::istream& operator>>(std::istream& is, Transicion& transicion) {
    is >> transicion.valor_transicion_;
    return is;
  }
 private:
  int destino_;
  char valor_transicion_;
};

#endif