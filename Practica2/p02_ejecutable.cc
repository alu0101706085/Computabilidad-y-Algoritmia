// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: David Javier Rodríguez Fumero 
// Correo: alu0101706085@ull.edu.es
// Fecha: 19/09/2025
// Archivo p02_ejecutable.cc: programa cliente.
// Contiene la funci´on main del proyecto que usa las clases Simbolo, Cadena, Alfabeto y Lenguaje
// para poder operar correctamente con esos valores de una manera más general y sencilla. En este caso,
// el codigo presente permite calcular un alfabeto, la longitud e inversa de una cadena y los prefijos y 
// sufijos de una cadena y volverlo a nivel práctico, un lenguaje.
// Objetivos del Proyecto:
// Estructura de Datos Utilizadas:
// Referencias:
// Enlaces de inter´es
//
// Historial de revisiones
// 16/09/2025 - Creaci´on (primera versi´on) del c´odigo
// 17/09/2025 - Avance con las clases simbolo y alfabeto
// 18/09/2025 - Avance con las clases cadena, lenguaje y el main
// 19/09/2025 - Obtención de los resultados esperados

#include <iostream>
#include <fstream>

#include "clase_Alfabeto.h"
#include "clase_Cadena.h"
#include "clase_Lenguaje.h"
#include "clase_Simbolo.h"

int main(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "--help") {
    std::cout << "Modo de uso: ./p02_ejecutable filein.txt fileout.txt opcode\n" << std::endl;
    std::cout << "El archivo de lectura lee una cadena y un alfabeto por linea." << std::endl;
    std::cout << "La cadena introducida debe pertenecer al alfabeto propuesto." << std::endl;
    std::cout << "Con esos datos, puede hacer diferentes operaciones según el opcode introducido:" << std::endl;
    std::cout << "        1. Alfabeto: Muestra el alfabeto asociado a cada una de las cadenas de entrada." << std::endl;
    std::cout << "        2. Longitud: Calcula la longitud de cada cadena de entrada." << std::endl;
    std::cout << "        3. Inversa: Calcula la inversa de cada cadena de entrada." << std::endl;
    std::cout << "        4. Prefijos: Calcula un lenguaje conformado por el conjunto de cadenas" << std::endl;
    std::cout << "        que son prefijos de la cadena de entrada correspondiente." << std::endl;
    std::cout << "        5. Sufijos: Calcula un lenguaje conformado por el conjunto de cadenas" << std::endl;
    std::cout << "        que son sufijos de la cadena de entrada correspondiente.\n" << std::endl;
    std::cout << "Los resultados de las operaciones se verán expresadas en el archivo de salida." << std::endl;
    return 1;
  } else if (argc != 4) {
    std::cout << "Modo de empleo: ./p02_ejecutable filein.txt fileout.txt opcode" << std::endl;
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
    int opcode = std::stoi(argv[3]);
    if (opcode < 1 || opcode > 5) {
      std::cerr << "Error, opcode fuera de rango.\n";
    }
    Cadena cadena_;
    Alfabeto alfabeto_;
    Lenguaje lenguaje_;
    std::string linea, alfabetoStr, cadenaStr;
    while(FicheroLectura >> cadenaStr >> alfabetoStr) {
      for (char caracter : cadenaStr) {
        if (alfabetoStr.find(caracter) == std::string::npos) {
          std::cout << "Error, la cadena introducida no pertenece al alfabeto propuesto." << std::endl;
          return 1;
        }
      }
      switch (opcode) {
        case 1:
          alfabeto_.CrearAlfabeto(alfabetoStr);
          FicheroEscritura << alfabeto_ << "\n";
          break;
        case 2:
          cadena_.SetCadena(cadenaStr);
          FicheroEscritura << cadena_.ObtenerLongitud() << "\n";
          break;
        case 3:
          cadena_.SetCadena(cadenaStr);
          FicheroEscritura << cadena_.ObtenerInversa() << "\n";
          break;
        case 4:
          lenguaje_.CalcularPrefijos(cadenaStr);
          FicheroEscritura << lenguaje_ << "\n";
          break;
        case 5:
          lenguaje_.CalcularSufijos(cadenaStr);
          FicheroEscritura << lenguaje_ << "\n";
          break;
      }
    }
    FicheroEscritura.close();
    FicheroLectura.close();
    return 0;
  }
}