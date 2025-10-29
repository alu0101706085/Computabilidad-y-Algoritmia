#include <fstream>
#include <string>

#include "../include/simbolo.h"
#include "../include/produccion.h"
#include "../include/gramatica.h"

void GenerarGramatica(std::string fichero_entrada, Gramatica& gramatica) {
  std::ifstream FicheroLectura(fichero_entrada);
  if (!FicheroLectura) {
    std::cerr << "Error, no se pudo abrir el fichero de lectura" << std::endl;
  }
  unsigned numero_simbolos_terminales{0};
  FicheroLectura >> numero_simbolos_terminales;
  for (int i{0}; i < numero_simbolos_terminales; i++) {
    Simbolo terminal;
    FicheroLectura >> terminal;
    terminal.SetEsTerminal(true);
    gramatica.AddTerminal(terminal);
  }
  unsigned numero_no_terminales{0};
  FicheroLectura >> numero_no_terminales;
  for (int i{0}; i < numero_no_terminales; i++) {
    Simbolo no_terminal;
    FicheroLectura >> no_terminal;
    no_terminal.SetEsTerminal(false);
    gramatica.AddNoTerminal(no_terminal);
  }
  unsigned numero_producciones{0};
  FicheroLectura >> numero_producciones;
  for (int i{0}; i < numero_producciones; i++) {
    Produccion produccion;
    FicheroLectura >> produccion;
    gramatica.AddProduccion(produccion);
  }
}