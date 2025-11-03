// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramáticas en Forma Normal de Chomsky
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 03/11/2025
// Archivo main.cc: Programa principal encargado de coordinar la lectura,
// transformación y escritura de una gramática en Forma Normal de Chomsky.
// Referencias: https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#include <iostream>

#include "../include/gramatica.h"
#include "../include/lector_gramatica.h"
#include "../include/escritor_gramatica.h"

/**
 * @brief Programa principal que convierte una gramática a su Forma Normal de Chomsky (FNC).
 * @param argc Número de argumentos de línea de comandos.
 * @param argv Vector con los argumentos de entrada.
 * @return 0 si la conversión se realiza correctamente, 1 en caso de error.
 */
int main(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "--help") {
    std::cout << "Modo de uso: ./Grammar2CNF input.gra output.gra\n";
    std::cout << "El programa se encarga de leer una gramática independiente del contexto\n";
    std::cout << "desde el fichero de entrada especificado y generar una gramática equivalente\n";
    std::cout << "en Forma Normal de Chomsky en el fichero de salida.\n";
    std::cout << std::endl;
    std::cout << "Ejemplo:\n";
    std::cout << "  ./Grammar2CNF ejemplo.gra resultado.gra\n";
    return 1;
  } else if (argc != 3) {
    std::cerr << "Modo de empleo: ./Grammar2CNF input.gra output.gra\n";
    std::cerr << "Pruebe './Grammar2CNF --help' para más información.\n";
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
