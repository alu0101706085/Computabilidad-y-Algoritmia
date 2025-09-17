#include <iostream>
#include <fstream>

#include "clase_Alfabeto.h"
#include "clase_Cadena.h"
#include "clase_Lenguaje.h"
#include "clase_Simbolo.h"

int main(int argc, char* argv[]) {
  if (argc == 2 && argv[1] == "--help") {
    std::cout << "Modo de uso: " << std::endl;
    return 1;
  } else if (argc != 4) {
    std::cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode" << std::endl;
    std::cout << "Pruebe ´./p02_strings --help´ para mas informacion." << std::endl;
    return 1;
  } else {
    std::ifstream FicheroLectura(argv[1]);
    if (!FicheroLectura) {
      std::cerr << "Error, no se pudo abrir el fichero de lectura" << std::endl;
      return 1;
    }
    std::ofstream FicheroEscritura(argv[2]);
    if (!FicheroEscritura) {
      std::cerr << "Error, no se pudo abrir el fichero de lectura" << std::endl;
      return 1;
    }


    FicheroEscritura.close();
    FicheroLectura.close();
    return 0;
  }
}