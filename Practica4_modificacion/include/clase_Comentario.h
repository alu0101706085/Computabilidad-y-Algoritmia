// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares en C++
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 07/10/2025
// Archivo clase_Comentario.h: Programa encargado de definir las 
// funciones necesarias para detectar comentarios de un programa.
// Referencias:
// https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

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