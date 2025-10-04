#include <fstream>
#include <iostream>

#include "clase_Bucle.h"
#include "clase_Comentario.h"
#include "clase_Estructura.h"
#include "clase_Funcion.h"
#include "clase_Generar_Reporte.h"
#include "clase_PatronesRegex.h"
#include "clase_Variable.h"

int main(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "--help") {
    std::cout << "Modo de uso: ./p03_ejecutable filein.txt fileout.txt\n" << std::endl;
    std::cout << "El programa se encarga de ir leyendo cada linea del fichero de entrada\n";
    std::cout << "con el fin detectar variables (int o double), bucles (while o for),\n";
    std::cout << "comentarios(de una linea o multiple) y la existencia de un main o no.\n";
    std::cout << std::endl;
    std::cout << "Con estos datos, incluirá un resumen básico de todo lo analizado en el fichero de salida.\n";
    return 1;
  } else if (argc != 3) {
    std::cout << "Modo de empleo: ./p03_ejecutable filein.txt fileout.txt" << std::endl;
    std::cout << "Pruebe ´./p02_strings --help´ para mas informacion." << std::endl;
    return 1;
  } else {
    std::string nombre_archivo_entrada(argv[1]);
    Funcion programa;
    Estructura estructura;
    GenerarReporte reporte;
    programa.AnalizarFichero(nombre_archivo_entrada, estructura);
    reporte.GenerarResultado(argv[2], estructura);
    std::cout << "Análisis completado. Resultados en: " << argv[2] << std::endl;
  }
}