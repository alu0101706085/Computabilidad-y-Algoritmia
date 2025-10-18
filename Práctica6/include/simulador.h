// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 18/10/2025
// Archivo simulador.h: Programa encargado de declarar los atributos y las
// fucniones que tendra la clase simulador.
// Referencias:
// https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#ifndef SIMULADOR_H
#define SIMULADOR_H

#include "../include/estado.h"
#include "../include/estructura.h"
#include "string"

class Simulador {
 public:
  Simulador() = default;
  void RealizarSimulador(const std::string& FicheroDeEntrada,
                         Estructura estructura);
  bool AnalizarCadena(const std::string& cadena, Estructura& estructura);
  std::set<Estado> AvanzarEstado(const std::set<Estado> cadena_estados,
                                 char simbolo, Estructura& estructura);
  void MostrarResultado(const std::string& cadena, Estructura& estructura);
  // Comprobaciones
  bool VerificarValorTransicion(const char simbolo,
                                const Estructura& estructura);

 private:
};

#endif