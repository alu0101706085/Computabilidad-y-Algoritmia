#include "../include/escritor_gramatica.h"

#include <iostream>
#include <fstream>
#include <string>

#include "../include/simbolo.h"
#include "../include/produccion.h"
#include "../include/gramatica.h"

void EscritorGramatica::EscribirFNC(std::string fichero_salida, Gramatica& gramatica) {
  std::fstream FicheroEscritura(fichero_salida);
  if (!FicheroEscritura) {
    std::cerr << "Error: No se pudo abrir el fichero de escritura" << std::endl;
  }
  for (const auto& produccion : gramatica.GetProducciones()) {
    FicheroEscritura << produccion << '\n';
  }
  FicheroEscritura.close();
}