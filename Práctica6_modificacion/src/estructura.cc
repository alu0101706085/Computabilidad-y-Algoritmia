// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 18/10/2025
// Archivo estructura.cc: Programa encargado de definir los métodos de la clase
// estructura.
// Referencias: https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#include "../include/estructura.h"

Estado Estructura::GetEstadoEspecifico(const int identificador) {
  Estado estado_especifico;
  for (const auto& estado : GetCadenaEstados()) {
    if (estado.GetIdentificador() == identificador) {
      estado_especifico = estado;
    }
  }
  return estado_especifico;
}