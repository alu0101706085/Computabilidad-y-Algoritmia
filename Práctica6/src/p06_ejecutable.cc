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
  Estructura estructura;
  Automata automata;
  // Carga la definición del autómata desde el fichero .fa
  automata.DefinirAutomata(argv[1], estructura);
  Simulador simulador;
  // Simula el procesamiento de las cadenas del fichero de entrada
  simulador.RealizarSimulador(argv[2], estructura);
  return 0;
}
