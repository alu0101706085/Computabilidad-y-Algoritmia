#ifndef TRANSICION
#define TRANSICION

class Transicion {
 public:
  Transicion() = default;
  Transicion(int origen, int destino, int valor_transicion)
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
  bool operator<(const Transicion& otro) {
    return valor_transicion_ < otro.valor_transicion_&& destino_ < otro.destino_;
  }
  friend std::istream& operator>>(std::istream& is, Transicion& transicion) {
    is >> transicion.valor_transicion_ >> transicion.destino_;
    return is;
  }
 private:
  int destino_;
  char valor_transicion_;
};

#endif