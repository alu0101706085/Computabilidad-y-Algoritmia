#ifndef TRANSICION_H
#define TRANSICION_H

class Transicion {
 public:
  Transicion() = default;
  Transicion(Estado destino, char valor_transicion)
      : destino_(destino), valor_transicion_(valor_transicion) {}
  // Getters
  Estado GetDestino() const { return destino_; }
  char GetValorTransicion() const { return valor_transicion_; }
  // Setters
  void SetDestino(Estado destino) { destino_ = destino; }
  void SetValorTransicion(char valor_transicion) {
    valor_transicion_ = valor_transicion;
  }
  // Sobrecarga de operadores
  bool operator<(const Transicion& otro) {
    return valor_transicion_ < otro.valor_transicion_&& destino_ < otro.destino_;
  }
  friend std::istream& operator>>(std::istream& is, Transicion& transicion) {
    is >> transicion.valor_transicion_ >> transicion.destino_;
    return is;
  }
 private:
  Estado destino_;
  char valor_transicion_;
};

#endif