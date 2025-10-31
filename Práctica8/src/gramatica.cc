#include "../include/gramatica.h"

#include <iostream>
#include <map>
#include <set>

const Simbolo kCADENA_VACIA("&", true);
const std::vector<Simbolo> kVECTOR_CADENA_VACIA{kCADENA_VACIA};

void Gramatica::TransformarGramatica() {
  bool tieneEpsilon = TieneEpsilonProducciones();
  bool tieneUnitarias = TieneProduccionesUnitarias();
  if (tieneEpsilon || tieneUnitarias) {
    std::cerr << "Aviso: la gramática tiene ";
    if (tieneEpsilon) std::cerr << "producciones epsilon ";
    if (tieneUnitarias) std::cerr << "producciones unitarias ";
    std::cerr << " — intentando conversión a FNC de todas formas\n";
  }
  ConvertirFormaNormalChomsky();
}

bool Gramatica::TieneProduccionesUnitarias() {
  for (const auto& produccion : producciones_) {
    if (produccion.GetSecuencia().size() == 1 &&
        isupper(produccion.GetSecuencia()[0].GetSimbolo()[0])) {
      return true;
    }
  }
  return false;
}

bool Gramatica::TieneEpsilonProducciones() {
  for (const auto& produccion : producciones_) {
    if (produccion.GetSimbolo() != GetEstadoArranque()) {
      if (produccion.GetSecuencia()[0] == kCADENA_VACIA &&
          produccion.GetSecuencia().size() == 1) {
        return true;
      }
    }
  }
  return false;
}

void Gramatica::ConvertirFormaNormalChomsky() {
  // Primera fase: Reemplazar teminales dentro de producciones largas
  // Para todas las producciones con secuencia >= 2
  for (auto& produccion : producciones_) {
    if (produccion.GetSecuencia().size() >= 2) {
      std::vector<Simbolo> nueva_secuencia;
      // Para cada simbolo de la secuencia
      for (const auto& simbolo : produccion.GetSecuencia()) {
        // Si pertenece al alfabeto definido (si es terminal)
        if (terminales_.find(simbolo) != terminales_.end()) {
          std::string nuevo_nombre_simbolo = "C" + simbolo.GetSimbolo();
          Simbolo nuevo_simbolo(nuevo_nombre_simbolo, false);
          // Si no existe una produccion tal que Cx -> x la añadimos
          Produccion nueva_produccion;
          nueva_produccion.SetSimbolo(nuevo_simbolo);
          nueva_produccion.SetSecuencia({simbolo});
          bool existe_produccion{false};
          for (const auto& produccion_ : producciones_) {
            if (nueva_produccion.GetSimbolo() == produccion_.GetSimbolo() &&
                nueva_produccion.GetSecuencia() == produccion_.GetSecuencia()) {
                existe_produccion=true;
            }
          }
          if (!existe_produccion) {
            producciones_.emplace_back(nueva_produccion);
            no_terminales_.insert(nuevo_simbolo);
          }
          nueva_secuencia.emplace_back(nuevo_simbolo);
        // Si no pertenece al alfabeto definido (es no terminal)
        } else {
          nueva_secuencia.emplace_back(simbolo);
        }
      }
      produccion.SetSecuencia(nueva_secuencia);
    }
  }
  // Segunda fase: Descomponer producciones con más de dos no terminales
  std::vector<Produccion> nuevas_producciones;
  for (const auto& produccion : producciones_) {
    if (produccion.GetSecuencia().size() <= 2) {
      nuevas_producciones.emplace_back(produccion);
    } else {
      Produccion produccion_actual = produccion;
      Simbolo simbolo_actual = produccion.GetSimbolo();
      std::vector<Simbolo> secuencia_actual = produccion.GetSecuencia(); 
      unsigned contador{1};
      while (secuencia_actual.size() > 2) {
        // Crear las variables intermedias D1, D2, ...
        std::string nuevo_no_terminal = "D" + std::to_string(contador);
        Produccion nueva_produccion;
        nueva_produccion.SetSimbolo(simbolo_actual);
        Simbolo nuevo_simbolo(nuevo_no_terminal, false);
        std::vector<Simbolo> secuencia{secuencia_actual[0], nuevo_simbolo};
        nueva_produccion.SetSecuencia(secuencia);
        nuevas_producciones.emplace_back(nueva_produccion);
        simbolo_actual = nuevo_simbolo;
        secuencia_actual.erase(secuencia_actual.begin());
        contador++;
      }
      Produccion ultima_produccion;
      ultima_produccion.SetSimbolo(simbolo_actual);
      std::vector<Simbolo> ultima_secuencia{secuencia_actual[0], secuencia_actual[1]};
      ultima_produccion.SetSecuencia(ultima_secuencia);
      nuevas_producciones.emplace_back(ultima_produccion);
    }
  }
  producciones_=nuevas_producciones;
}