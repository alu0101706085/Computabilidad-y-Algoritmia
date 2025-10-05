// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares en C++
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 07/10/2025
// Archivo clase_Estructura.h: Programa encargado de definir las 
// funciones necesarias para guardar datos necesarios.
// Referencias:
// https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#ifndef CLASE_ESTRUCTURA
#define CLASE_ESTRUCTURA

#include <iostream>
#include <string>
#include <vector>

#include "clase_Bucle.h"
#include "clase_Comentario.h"
#include "clase_Variable.h"

class Estructura {
 public:
  Estructura() = default;
  Estructura(std::string nombre_archivo, std::vector<Variable> variables,
             std::vector<Bucle> bucles, std::vector<Comentario> comentarios,
             bool tiene_main, std::string descripcion_programa)
      : nombre_archivo_(nombre_archivo),
        variables_(variables),
        bucles_(bucles),
        comentarios_(comentarios),
        tiene_main_(tiene_main),
        descripcion_programa_(descripcion_programa) {}
  // Getters
  std::string GetNombreArchivo() const { return nombre_archivo_; }
  std::vector<Variable> GetVectorVariables() const { return variables_; }
  std::vector<Bucle> GetVectorBucle() const { return bucles_; }
  std::vector<Comentario> GetVectorComentarios() const { return comentarios_; }
  bool GetTieneMain() const { return tiene_main_; }
  std::string GetDescripcionPrograma() const { return descripcion_programa_; }
  // Setters
  void SetNombreArchivo(const std::string& nombre_archivo) {
    nombre_archivo_ = nombre_archivo;
  }
  void SetVariables(const std::vector<Variable>& variables) {
    variables_ = variables;
  }
  void SetBucles(const std::vector<Bucle>& bucles) { bucles_ = bucles; }
  void SetComentarios(const std::vector<Comentario>& comentarios) {
    comentarios_ = comentarios;
  }
  void SetTieneMain(bool tiene_main) { tiene_main_ = tiene_main; }
  void SetDescripcionPrograma(const std::string& descripcion_programa) {
    descripcion_programa_ = descripcion_programa;
  }
  // Métodos
  void AddVariable(const Variable& variable);
  void AddBucle(const Bucle& bucle);
  void AddComentario(const Comentario& comentario);
  int GetNumeroBuclesPorTipo(TipoBucle tipo) const;
  int GetNumeroVariablesPorTipo(TipoVariable tipo) const;

 private:
  std::string nombre_archivo_;
  std::vector<Variable> variables_;
  std::vector<Bucle> bucles_;
  std::vector<Comentario> comentarios_;
  bool tiene_main_;
  std::string descripcion_programa_;  // Primer comentario del archivo
};

#endif