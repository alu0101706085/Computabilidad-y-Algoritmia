#ifndef CLASE_COMENTARIO
#define CLASE_COMENTARIO

#include <iostream>
#include <vector>

enum class TipoComentario { UNA_LINEA, MULTIPLE_LINEA };

class Comentario {
 public:
  Comentario() = default;
  Comentario(TipoComentario tipo, std::vector<int> numero_lineas,
             std::string contenido)
      : tipo_(tipo), numero_lineas_(numero_lineas), contenido_(contenido) {}
  // Getters
  TipoComentario GetTipo() const { return tipo_; }
  std::vector<int> GetNumeroLineas() const { return numero_lineas_; }
  std::string GetContenido() const { return contenido_; }
  // Setters
  void SetTipo(const TipoComentario& tipo) { tipo_ = tipo; }
  void SetNumeroLineas(const std::vector<int>& numero_lineas) {
    numero_lineas_ = numero_lineas;
  }
  void SetContenido(const std::string& contenido) { contenido_ = contenido; }
 private:
  TipoComentario tipo_;
  std::vector<int> numero_lineas_;
  std::string contenido_;
};

#endif