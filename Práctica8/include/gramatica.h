#ifndef GRAMATICA_H
#define GRAMATICA_H

#include "../include/simbolo.h"
#include "../include/produccion.h"

#include <set>
#include <vector>

class Gramatica {
 public:
  // Contructor 
  Gramatica() = default;
  // Getters
  std::set<Simbolo> GetNoTerminales() const { return no_terminales_; }
  std::set<Simbolo> GetTerminales() const { return terminales_; }
  Simbolo GetEstadoArranque() const { return estado_arranque_; }
  std::vector<Produccion> GetProducciones() const { return producciones_; }
  // Métodos
  void AddNoTerminal(Simbolo& simbolo) { no_terminales_.insert(simbolo); }
  void AddTerminal(Simbolo& simbolo) { terminales_.insert(simbolo); }
  void AddProduccion(Produccion& otro) { producciones_.emplace_back(otro); }
  void TransformarGramatica();
 private:
  // Métodos privados
  bool TieneProduccionesUnitarias();
  bool TieneEpsilonProducciones();
  void ConvertirFormaNormalChomsky();
  // Atributos
  std::set<Simbolo> terminales_;
  std::set<Simbolo> no_terminales_;
  Simbolo estado_arranque_;
  std::vector<Produccion> producciones_;
};

#endif