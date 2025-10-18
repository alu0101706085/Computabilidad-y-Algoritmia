// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 18/10/2025
// Archivo p06_ejecutable.cc: Programa principal encargado de definir el
// comportamiento final del programa ejecutable.
// Referencias:
// https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#include <iostream>

#include "../include/automata.h"
#include "../include/estado.h"
#include "../include/estructura.h"
#include "../include/simulador.h"
#include "../include/transicion.h"

int main(int argc, char* argv[]) {
  Estructura estructura;
  Automata automata;
  automata.DefinirAutomata(argv[1], estructura);
  Simulador simulador;
  simulador.RealizarSimulador(argv[2], estructura);
  return 0;
}