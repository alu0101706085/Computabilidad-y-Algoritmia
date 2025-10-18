// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 18/10/2025
// Archivo estructura.h: Programa encargado de declarar los atributos y las
// fucniones que tendra la clase estructura.
// Referencias:
// https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

#include <set>

#include "estado.h"

class Estructura {
 public:
  Estructura() = default;
  Estructura(std::set<char> alfabeto, unsigned numero_total_estados,
             Estado& estado_arranque, std::set<Estado> cadena_estados)
      : alfabeto_(alfabeto),
        numero_total_estados_(numero_total_estados),
        estado_arranque_(estado_arranque),
        cadena_estados_(cadena_estados) {}
  // Getters
  std::set<char> GetAlfabeto() const { return alfabeto_; }
  unsigned GetNumeroTotalEstados() const { return numero_total_estados_; }
  Estado GetEstadoArranque() const { return estado_arranque_; }
  std::set<Estado> GetCadenaEstados() const { return cadena_estados_; }
  // Setters
  void SetNumeroTotalEstados(unsigned numero_total_estados) {
    numero_total_estados_ = numero_total_estados;
  }
  void SetEstadoArranque(Estado& estado_arranque) {
    estado_arranque_ = estado_arranque;
  }
  // Métodos
  void AddCaracterAlfabeto(char caracter) { alfabeto_.insert(caracter); }
  void AddCadenaEstados(Estado& estado) { cadena_estados_.insert(estado); }
  Estado GetEstadoEspecifico(const int identificador) {
    Estado estado_especifico;
    for (const auto& estado : GetCadenaEstados()) {
      if (estado.GetIdentificador() == identificador) {
        estado_especifico = estado;
      }
    }
    return estado_especifico;
  }

 private:
  std::set<char> alfabeto_;
  unsigned numero_total_estados_;
  Estado estado_arranque_;
  std::set<Estado> cadena_estados_;
};

#endif