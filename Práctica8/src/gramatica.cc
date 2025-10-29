#include "../include/gramatica.h"

#include <set>
#include <map>

void Gramatica::TransformarGramatica() {
  TieneProduccionesUnitarias();
  TieneEpsilonProducciones();
  EliminarProduccionesVacias();
  EliminarProduccionesUnitarias();
  ConvertirFormaNormalChomsky();
}

bool Gramatica::TieneProduccionesUnitarias() {
  for (const auto& produccion : producciones_) {
    if (produccion.GetSecuencia().size() == 1 && isupper(produccion.GetSecuencia()[0].GetSimbolo())) {
      return true;
    }
  }
  return false;
}

bool Gramatica::TieneEpsilonProducciones() {
  for (const auto& produccion : producciones_) {
    if (produccion.GetSimbolo() != GetEstadoArranque()) {
      Simbolo cadena_vacia = '&';
      if (produccion.GetSecuencia()[0] == cadena_vacia) {
        return true;
      }
    }
  }
  return false;
}

void Gramatica::EliminarProduccionesVacias() {
  if (TieneEpsilonProducciones) {

  }
}

void Gramatica::EliminarProduccionesUnitarias() {
  if (TieneProduccionesUnitarias) {
    // Paso 1: Construir H = {(A,B) | A ⇒* B}
    std::set<std::pair<Simbolo, Simbolo>> H;
    // Inicializar H con producciones unitarias directas
    for (const auto& produccion : producciones_) {
      if (produccion.EsUnitaria()) {
        H.insert({produccion.GetSimbolo(), produccion.GetSecuencia()[0].GetSimbolo()});
      }
    }
    // Cierre transitivo de H
    bool cambio{true};
    while (cambio) {
      cambio = false;
      std::set<std::pair<Simbolo, Simbolo>> nuevosPares;
      // Buscar pares (A,B) y (B,C) para agregar (A,C)
      for (const auto& par1 : H) {
        for (const auto& par2 : H) {
          if (par1.second == par2.first) {
            std::pair<Simbolo, Simbolo> nuevoPar = {par1.first, par2.second};
            if (H.find(nuevoPar) == H.end()) {
              nuevosPares.insert(nuevoPar);
              cambio = true;
            }
          }
        }
      } 
      // Agregar los nuevos pares encontrados
      H.insert(nuevosPares.begin(), nuevosPares.end());
    }
    // Paso 2: Eliminar todas las producciones unitarias
    std::vector<Produccion> nuevasProducciones;
    for (const auto& produccion : producciones_) {
      if (!produccion.EsUnitaria()) {
        nuevasProducciones.push_back(produccion);
      }
    }
    producciones_ = nuevasProducciones;
    // Paso 3: Para cada par (A,B) en H, agregar A → α por cada B → α
    for (const auto& par : H) {
      const Simbolo& A = par.first;
      const Simbolo& B = par.second;
      for (const auto& produccion : producciones_) {
        if (produccion.GetSimbolo() == B) {
          // Agregar A → α donde B → α
          Produccion nueva_produccion;
          nueva_produccion.SetSimbolo(A);
          nueva_produccion.SetSecuencia(produccion.GetSecuencia());
          // Verificar que no exista ya esta producción
          for (const auto& prod : producciones_) {
            if (prod.GetSimbolo() == nueva_produccion.GetSimbolo() &&
                prod.GetSecuencia() == nueva_produccion.GetSecuencia()) {
                  producciones_.push_back(nueva_produccion);
            }
          }
        }
      }
    }
  }
}

void Gramatica::ConvertirFormaNormalChomsky() {

}