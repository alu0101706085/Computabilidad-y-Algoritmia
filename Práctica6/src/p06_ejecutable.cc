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