#ifndef CLASE_VARIABLE
#define CLASE_VARIABLE

#include <iostream>
#include <string>

enum class TipoVariable { VAR_INT, VAR_DOUBLE };

class Variable {
 public:
  Variable() = default;
  Variable(TipoVariable tipo, std::string nombre, int numero_linea,
           bool inicializada)
      : tipo_(tipo),
        nombre_(nombre),
        numero_linea_(numero_linea),
        inicializada_(inicializada) {}
  // Getters
  TipoVariable GetTipo() const { return tipo_; }
  std::string GetNombre() const { return nombre_; }
  int GetNumeroLinea() const { return numero_linea_; }
  bool GetInicializada() const { return inicializada_; }
  std::string GetValorInicial() const { return valor_inicial_; }
  // Setters
  void SetTipo(TipoVariable tipo) { tipo_ = tipo; }
  void SetNombre(std::string& nombre) { nombre_ = nombre; }
  void SetNumeroLinea(int numero_linea) { numero_linea_ = numero_linea; }
  void SetInicializada(bool inicializada) { inicializada_ = inicializada; }
  void SetValorInicial(const std::string& valor) { valor_inicial_ = valor; }
 private:
  TipoVariable tipo_;
  std::string nombre_;
  int numero_linea_;
  bool inicializada_;
  std::string valor_inicial_;
};

#endif