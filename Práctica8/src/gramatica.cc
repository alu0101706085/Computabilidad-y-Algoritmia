// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramáticas en Forma Normal de Chomsky
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 03/11/2025
// Archivo gramatica.cc: Implementación de la clase Gramatica.
// Referencias: https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#include "../include/gramatica.h"

#include <iostream>
#include <map>
#include <set>

const Simbolo kCADENA_VACIA("&", true);
const std::vector<Simbolo> kVECTOR_CADENA_VACIA{kCADENA_VACIA};

/**
 * @brief Inicia el proceso de transformación de la gramática a la
 *        Forma Normal de Chomsky (FNC).
 *
 * La función verifica primero si existen producciones épsilon o unitarias,
 * y si no las hay, procede con la conversión a FNC.
 */
void Gramatica::TransformarGramatica() {
  bool tieneEpsilon = TieneEpsilonProducciones();
  bool tieneUnitarias = TieneProduccionesUnitarias();
  if (tieneEpsilon || tieneUnitarias) {
    std::cerr << "Aviso: la gramática tiene ";
    if (tieneEpsilon) std::cerr << "producciones épsilon ";
    if (tieneUnitarias) std::cerr << "producciones unitarias ";
  } else {
    ConvertirFormaNormalChomsky();
  }
}

/**
 * @brief Comprueba si existen producciones unitarias (A → B).
 * @return true si la gramática contiene alguna producción unitaria.
 */
bool Gramatica::TieneProduccionesUnitarias() {
  for (const auto& produccion : producciones_) {
    if (produccion.GetSecuencia().size() == 1 &&
        !produccion.GetSecuencia()[0].GetEsTerminal()) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Comprueba si existen producciones épsilon (A → &),
 *        distintas del símbolo inicial.
 * @return true si la gramática contiene producciones épsilon.
 */
bool Gramatica::TieneEpsilonProducciones() {
  for (const auto& produccion : producciones_) {
    if (produccion.GetSimbolo() != GetEstadoArranque()) {
      if (produccion.GetSecuencia().size() == 1 &&
          produccion.GetSecuencia()[0] == kCADENA_VACIA) {
        return true;
      }
    }
  }
  return false;
}

/**
 * @brief Convierte la gramática a su Forma Normal de Chomsky (FNC).
 *
 * Este proceso consta de dos fases:
 *  1. Sustituir los terminales en producciones largas por no terminales auxiliares (Cx → x).
 *  2. Descomponer producciones con más de dos no terminales en producciones binarias
 *     mediante la introducción de símbolos intermedios (D1, D2, ...).
 */
void Gramatica::ConvertirFormaNormalChomsky() {
  // --- Primera fase: reemplazar terminales dentro de producciones largas ---
  for (auto& produccion : producciones_) {
    if (produccion.GetSecuencia().size() >= 2) {
      std::vector<Simbolo> nueva_secuencia;
      for (const auto& simbolo : produccion.GetSecuencia()) {
        // Si el símbolo es terminal
        if (terminales_.find(simbolo) != terminales_.end()) {
          std::string nuevo_nombre_simbolo = "C" + simbolo.GetSimbolo();
          Simbolo nuevo_simbolo(nuevo_nombre_simbolo, false);
          // Crear producción Cx -> x si no existe
          Produccion nueva_produccion;
          nueva_produccion.SetSimbolo(nuevo_simbolo);
          nueva_produccion.SetSecuencia({simbolo});
          bool existe_produccion{false};
          for (const auto& produccion_ : producciones_) {
            if (nueva_produccion.GetSimbolo() == produccion_.GetSimbolo() &&
                nueva_produccion.GetSecuencia() == produccion_.GetSecuencia()) {
              existe_produccion = true;
            }
          }
          if (!existe_produccion) {
            producciones_.emplace_back(nueva_produccion);
            no_terminales_.insert(nuevo_simbolo);
          }
          nueva_secuencia.emplace_back(nuevo_simbolo);
        } else {
          nueva_secuencia.emplace_back(simbolo);
        }
      }
      produccion.SetSecuencia(nueva_secuencia);
    }
  }
  // --- Segunda fase: descomponer producciones con más de dos no terminales ---
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
        std::string nuevo_no_terminal = "D" + std::to_string(contador);
        Simbolo nuevo_simbolo(nuevo_no_terminal, false);
        Produccion nueva_produccion;
        nueva_produccion.SetSimbolo(simbolo_actual);
        nueva_produccion.SetSecuencia({secuencia_actual[0], nuevo_simbolo});
        nuevas_producciones.emplace_back(nueva_produccion);
        simbolo_actual = nuevo_simbolo;
        secuencia_actual.erase(secuencia_actual.begin());
        contador++;
      }
      Produccion ultima_produccion;
      ultima_produccion.SetSimbolo(simbolo_actual);
      ultima_produccion.SetSecuencia({secuencia_actual[0], secuencia_actual[1]});
      nuevas_producciones.emplace_back(ultima_produccion);
    }
  }
  producciones_ = nuevas_producciones;
}
