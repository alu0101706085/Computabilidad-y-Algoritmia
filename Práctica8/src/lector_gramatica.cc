// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramáticas en Forma Normal de Chomsky
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 03/11/2025
// Archivo lector_gramatica.cc: Implementación de la clase LectorGramatica.
// Referencias: https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#include "../include/lector_gramatica.h"

#include <iostream>
#include <fstream>
#include <string>

#include "../include/simbolo.h"
#include "../include/produccion.h"
#include "../include/gramatica.h"

/**
 * @brief Genera un objeto de tipo Gramatica a partir de un fichero de entrada.
 *
 * El fichero debe seguir el formato:
 * ```
 * <número_terminales>
 * <lista_terminales>
 * <número_no_terminales>
 * <lista_no_terminales>
 * <número_producciones>
 * <lista_producciones>
 *
 * La función asigna el primer no terminal leído como estado de arranque
 * e identifica los símbolos terminales y no terminales de cada producción.
 *
 * @param fichero_entrada Nombre del fichero de entrada.
 * @param gramatica Objeto de tipo Gramatica donde se almacenará la información.
 */
void LectorGramatica::GenerarGramatica(std::string fichero_entrada, Gramatica& gramatica) {
  std::ifstream FicheroLectura(fichero_entrada);
  if (!FicheroLectura) {
    std::cerr << "Error: no se pudo abrir el fichero de lectura" << std::endl;
    return;
  }
  // --- Lectura de símbolos terminales ---
  unsigned numero_simbolos_terminales{0};
  FicheroLectura >> numero_simbolos_terminales;
  for (unsigned i{0}; i < numero_simbolos_terminales; ++i) {
    Simbolo terminal;
    FicheroLectura >> terminal;
    terminal.SetEsTerminal(true);
    gramatica.AddTerminal(terminal);
  }
  // --- Lectura de símbolos no terminales ---
  unsigned numero_no_terminales{0};
  FicheroLectura >> numero_no_terminales;
  for (unsigned i{0}; i < numero_no_terminales; ++i) {
    Simbolo no_terminal;
    FicheroLectura >> no_terminal;
    no_terminal.SetEsTerminal(false);
    gramatica.AddNoTerminal(no_terminal);
    if (i == 0) {
      gramatica.SetEstadoArranque(no_terminal);  // Fijar estado de arranque
    }
  }
  // --- Lectura de producciones ---
  unsigned numero_producciones{0};
  FicheroLectura >> numero_producciones;
  for (unsigned i{0}; i < numero_producciones; ++i) {
    Produccion produccion;
    FicheroLectura >> produccion;
    // Fijar el tipo (terminal/no terminal) de cada símbolo de la producción
    std::vector<Simbolo> secuencia = produccion.GetSecuencia();
    for (auto& simbolo : secuencia) {
      if (gramatica.GetTerminales().count(simbolo)) {
        simbolo.SetEsTerminal(true);
      } else if (gramatica.GetNoTerminales().count(simbolo)) {
        simbolo.SetEsTerminal(false);
      }
    }
    produccion.SetSecuencia(secuencia);
    gramatica.AddProduccion(produccion);
  }
  FicheroLectura.close();
}
