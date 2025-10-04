#include "clase_Estructura.h"

#include <iostream>

void Estructura::AddVariable(const Variable& variable) {
  variables_.push_back(variable);
}

void Estructura::AddBucle(const Bucle& bucle) {
  bucles_.push_back(bucle);
}

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