// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramáticas en Forma Normal de Chomsky
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 03/11/2025
// Archivo escritor_gramatica.cc: Implementación de la clase EscritorGramatica.
// Referencias: https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#include "../include/escritor_gramatica.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../include/simbolo.h"
#include "../include/produccion.h"
#include "../include/gramatica.h"

/**
 * @brief Escribe en un fichero la gramática dada en su Forma Normal de Chomsky (FNC).
 *
 * Se divide la escritura en tres grupos de producciones:
 *  - Producciones de entrada (símbolos regulares).
 *  - Producciones que reemplazan terminales (prefijo 'C').
 *  - Producciones intermedias o auxiliares (prefijo 'D').
 *
 * El orden de escritura es: entrada → reemplazo terminales → intermedias.
 *
 * @param fichero_salida Nombre del fichero de salida.
 * @param gramatica Referencia a la gramática que será escrita.
 */
void EscritorGramatica::EscribirFNC(std::string fichero_salida, Gramatica& gramatica) {
  std::ofstream FicheroEscritura(fichero_salida);
  if (!FicheroEscritura) {
    std::cerr << "Error: No se pudo abrir el fichero de escritura" << std::endl;
    return;
  }
  std::vector<Produccion> producciones_entrada;
  std::vector<Produccion> producciones_reemplazo_terminales;
  std::vector<Produccion> producciones_intermedias;
  for (const auto& produccion : gramatica.GetProducciones()) {
    std::string simbolo = produccion.GetSimbolo().GetSimbolo();
    if (!simbolo.empty() && simbolo[0] == 'C') {
      producciones_reemplazo_terminales.emplace_back(produccion);
    } else if (!simbolo.empty() && simbolo[0] == 'D') {
      producciones_intermedias.emplace_back(produccion);
    } else {
      producciones_entrada.emplace_back(produccion);
    }
  }
  for (const auto& prod : producciones_entrada) {
    EscribirProduccionCompacta(FicheroEscritura, prod);
  }
  for (const auto& prod : producciones_reemplazo_terminales) {
    EscribirProduccionCompacta(FicheroEscritura, prod);
  }
  for (const auto& prod : producciones_intermedias) {
    EscribirProduccionCompacta(FicheroEscritura, prod);
  }
}

/**
 * @brief Escribe una producción de forma compacta en el fichero.
 * @param os Flujo de salida asociado al fichero.
 * @param produccion Producción que se escribirá.
 *
 * El formato de salida es:
 * ```
 * <Simbolo> <SecuenciaDeSimbolos>
 * ```
 */
void EscritorGramatica::EscribirProduccionCompacta(std::ofstream& os, const Produccion& produccion) {
  os << produccion.GetSimbolo().GetSimbolo() << ' ';
  for (const auto& simbolo : produccion.GetSecuencia()) {
    os << simbolo.GetSimbolo();
  }
  os << '\n';
}
