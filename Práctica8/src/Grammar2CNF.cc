#include <iostream>

#include "../include/gramatica.h"
#include "../include/lector_gramatica.h"
#include "../include/escritor_gramatica.h"

int main(int argc, char* argv[]) {
  if (std::string(argv[1]) == "--help") {
    std::cout << "Modo de uso: ./Grammar2CNF input.gra output.gra\n";
    std::cout << "El programa se encarga de ir leyendo cada linea del fichero "
                 "de entrada\n";
    std::cout
        << "con el fin de definir una gramática independiente del contexto,\n";
    std::cout << "entendiendo sus simboplos terminales, no terminales y "
                 "producciones.\n";
    std::cout << std::endl;
    std::cout << "Con estos datos, se generará una gramática equivalente en "
                 "Forma Normal de Chomsky.\n";
    return 1;
  } else if (argc != 3) {
    std::cout << "Modo de empleo: ./Grammar2CNF input.gra output.gra"
              << std::endl;
    std::cout << "Pruebe 'Grammar2CNF --help' para mas informacion"
              << std::endl;
    return 1;
  }
  Gramatica gramatica;
  LectorGramatica generador;
  generador.GenerarGramatica(argv[1], gramatica);
  gramatica.TransformarGramatica();
  EscritorGramatica guardar_resultado;
  guardar_resultado.EscribirFNC(argv[2], gramatica);
  return 0;
}