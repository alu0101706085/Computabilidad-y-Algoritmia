#ifndef ESTRUCTURA
#define ESTRUCTURA

#include <set>

#include "estado.h"

class Estructura {
 public:
  Estructura() = default;
  Estructura(std::set<char> alfabeto, unsigned numero_total_estados,
             unsigned estado_arranque, std::set<Estado> cadena_estados)
      : alfabeto_(alfabeto),
        numero_total_estados_(numero_total_estados),
        estado_arranque_(estado_arranque),
        cadena_estados_(cadena_estados) {}
  // Getters
  std::set<char> GetAlfabeto() const { return alfabeto_; }
  unsigned GetNumeroTotalEstados() const { return numero_total_estados_; }
  unsigned GetEstadoArranque() const { return estado_arranque_; }
  std::set<Estado> GetCadenaEstados() const { return cadena_estados_; }
  // Setters
  void SetNumeroTotalEstados(unsigned numero_total_estados) { numero_total_estados_ = numero_total_estados; }
  void SetEstadoArranque(unsigned estado_arranque) { estado_arranque_ = estado_arranque; }
  // Métodos
  void AddCaracterAlfabeto(char caracter) { alfabeto_.insert(caracter); }
  void AddCadenaEstados(Estado estado) { cadena_estados_.insert(estado); }
 private:
  std::set<char> alfabeto_;
  unsigned numero_total_estados_;
  unsigned estado_arranque_;
  std::set<Estado> cadena_estados_;
};

#endif