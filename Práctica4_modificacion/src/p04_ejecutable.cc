// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares en C++
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 07/10/2025
// Archivo p04_ejecutable.cc: Programa principal encargado de establecer el
// funcionamiento final. 
// Objetivos del Proyecto: Analizar un programa y separar
// sus partes más reconocibles mediante expresiones regulares. 
// Referencias:
// https://google.github.io/styleguide/cppguide.html 
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856
//
// Historial de revisiones
// 03/10/2025 - Creación (primera versión) del código
// 04/10/2025 - Primera versión ejecutable
// 05/10/2025 - Obtención de los resultados esperados

#include <fstream>
#include <iostream>

#include "../include/clase_Bucle.h"
#include "../include/clase_Comentario.h"
#include "../include/clase_Estructura.h"
#include "../include/clase_Funcion.h"
#include "../include/clase_Generar_Reporte.h"
#include "../include/clase_PatronesRegex.h"
#include "../include/clase_Variable.h"

int main(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "--help") {
    std::cout << "Modo de uso: ./p04_ejecutable filein.txt fileout.txt\n";
    std::cout << "El programa se encarga de ir leyendo cada linea del fichero "
                 "de entrada\n";
    std::cout << "con el fin detectar variables (int o double), bucles (while "
                 "o for),\n";
    std::cout << "comentarios(de una linea o multiple) y la existencia de un "
                 "main o no.\n";
    std::cout << std::endl;
    std::cout << "Con estos datos, incluirá un resumen básico de todo lo "
                 "analizado en el fichero de salida.\n";
    return 1;
  } else if (argc != 3) {
    std::cout << "Modo de empleo: ./p03_ejecutable filein.txt fileout.txt"
              << std::endl;
    std::cout << "Pruebe './p04_ejecutable --help' para mas informacion."
              << std::endl;
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
  return 0;
}