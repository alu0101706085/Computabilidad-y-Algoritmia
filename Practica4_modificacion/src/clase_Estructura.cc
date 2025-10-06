// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares en C++
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 07/10/2025
// Archivo clase_Estructura.cc: Programa encargado de guardar en vectores 
// todos los datos de interes de un fichero dado.
// Referencias:
// https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#include "../include/clase_Estructura.h"

#include <iostream>

void Estructura::AddVariable(const Variable& variable) {
  variables_.push_back(variable);
}

void Estructura::AddBucle(const Bucle& bucle) { bucles_.push_back(bucle); }

void Estructura::AddComentario(const Comentario& comentario) {
  comentarios_.push_back(comentario);
}

int Estructura::GetNumeroBuclesPorTipo(TipoBucle tipo) const {
  int contador{0};
  for (const Bucle& bucle : bucles_) {
    if (bucle.GetTipo() == tipo) {
      contador++;
    }
  }
  return contador;
}

int Estructura::GetNumeroVariablesPorTipo(TipoVariable tipo) const {
  int contador{0};
  for (const Variable& variable : variables_) {
    if (variable.GetTipo() == tipo) {
      contador++;
    }
  }
  return contador;
}