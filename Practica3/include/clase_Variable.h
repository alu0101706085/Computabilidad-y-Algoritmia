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
  TipoVariable GetTipo() { return tipo_; }
  std::string GetNombre() { return nombre_; }
  int GetNumeroLinea() { return numero_linea_; }
  bool GetInicializada() { return inicializada_; }
  // Setters
  void SetTipo(TipoVariable tipo) { tipo_ = tipo; }
  void SetNombre(std::string& nombre) { nombre_ = nombre; }
  void SetNumeroLinea(int numero_linea) { numero_linea_ = numero_linea; }
  void SetInicializada(bool inicializada) { inicializada_ = inicializada; }
 private:
  TipoVariable tipo_;
  std::string nombre_;
  int numero_linea_;
  bool inicializada_;
};

#endif