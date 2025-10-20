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
// Modificacion
#include "../include/modificacion.h"

/**
 * @brief Función principal del programa.
 *
 * Este programa simula el comportamiento de un autómata finito. Para ello:
 * 1. Lee la definición del autómata desde un fichero `.fa`.
 * 2. Lee un conjunto de cadenas desde un fichero `.txt`.
 * 3. Muestra por pantalla si cada cadena es **aceptada** o **rechazada**
 *    por el autómata definido.
 *
 * **Uso desde la terminal:**
 * ```
 * ./p06_ejecutable automata.fa cadenas.txt
 * ```
 *
 * @param argc Número de argumentos de línea de comandos.
 * @param argv Array de punteros a cadenas con los argumentos:
 *  - `argv[1]`: Ruta al fichero `.fa` con la definición del autómata.
 *  - `argv[2]`: Ruta al fichero `.txt` con las cadenas a evaluar.
 * @return 0 Si la ejecución finaliza correctamente.
 */
int main(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "--help") {
    std::cout << "Modo de uso: ./p06_automata_simulator input.fa input.txt\n";
    std::cout << "El programa se encarga de ir leyendo cada linea del fichero .fa\n";
    std::cout << "con el fin de determinar la estructura de un autómata finito\n";
    std::cout << std::endl;
    std::cout << "Con estos datos determinara el comportamiento del autómata para determinar \n"
                 "si las cadenas de input.txt son aceptadas por al automata o no.\n";
    return 1;
  } else if (argc != 3) {
    std::cout << "Modo de empleo: ./p06_automata_simulator input.fa input.txt"
              << std::endl;
    std::cout << "Pruebe './p06_automata_simulator --help' para mas informacion."
              << std::endl;
    return 1;
  } else {
    Estructura estructura;
    Automata automata;
    // Carga la definición del autómata desde el fichero .fa
    automata.DefinirAutomata(argv[1], estructura);
    Simulador simulador;
    // Simula el procesamiento de las cadenas del fichero de entrada
    simulador.RealizarSimulador(argv[2], estructura);
    // Modificaciones
    // Muestra si un automata es DFA o NFA
    Modificacion modificacion;
    if (!modificacion.EsDFA(estructura)) {
      std::cout << "El autómata finito proporcionado es un no determinista. Es un NFA" << std::endl;
    } else {
      std::cout << "El autómata finito proporcionado es determinista. Es un DFA" << std::endl;
    }
    modificacion.MotrarEstadosAlcanzables(0, estructura); 
  }
  return 0;
}
