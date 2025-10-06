// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares en C++
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 07/10/2025
// Archivo clase_Variable.h: Programa encargado de definir las 
// funciones de las variables encontradas.
// Referencias:
// https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

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