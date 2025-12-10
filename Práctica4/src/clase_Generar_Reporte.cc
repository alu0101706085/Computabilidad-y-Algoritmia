// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares en C++
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 07/10/2025
// Archivo clase_PatronesRegex.cc: Programa encargado de definir 
// las expresiones regulares empleadas.
// Referencias:
// https://dzone.com/articles/introduction-to-regular-expression-with-modern-c
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#include "../include/clase_Generar_Reporte.h"

#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

#include "../include/clase_Funcion.h"
#include "../include/clase_PatronesRegex.h"

void GenerarReporte::GenerarResultado(const std::string& fichero_salida,
                                      const Estructura& estructura) {
  std::ofstream FicheroEscritura(fichero_salida);
  if (!FicheroEscritura) {
    std::cerr << "Error, no se pudo abrir el fichero de escritura" << std::endl;
  } else {
    EscribirSeccionPrograma(FicheroEscritura, estructura);
    EscribirSeccionDescipcion(FicheroEscritura, estructura);
    EscribirSeccionVariable(FicheroEscritura, estructura);
    EscribirSeccionBucle(FicheroEscritura, estructura);
    EscribirSeccionMain(FicheroEscritura, estructura);
    EscribirSeccionComentarios(FicheroEscritura, estructura);
  }
  FicheroEscritura.close();
}

void GenerarReporte::EscribirSeccionPrograma(std::ofstream& FicheroEscritura,
                                             const Estructura& estructura) {
  FicheroEscritura << "PROGRAM: " << estructura.GetNombreArchivo() << std::endl;
}

void GenerarReporte::EscribirSeccionDescipcion(std::ofstream& FicheroEscritura,
                                               const Estructura& estructura) {
  FicheroEscritura << "DESCRIPTION:" << std::endl;
  std::string descripcion = estructura.GetDescripcionPrograma();
  if (!descripcion.empty()) {
    FicheroEscritura << descripcion << std::endl;
  }
  FicheroEscritura << std::endl;
}

void GenerarReporte::EscribirSeccionVariable(std::ofstream& FicheroEscritura,
                                             const Estructura& estructura) {
  FicheroEscritura << "VARIABLES:" << std::endl;
  std::vector<Variable> cadena = estructura.GetVectorVariables();
  for (const auto& variable : cadena) {
    FicheroEscritura << "[Line " << variable.GetNumeroLinea() << "] ";
    if (variable.GetTipo() == TipoVariable::VAR_INT) {
      FicheroEscritura << "INT: ";
    } else {
      FicheroEscritura << "DOUBLE: ";
    }
    FicheroEscritura << variable.GetNombre();
    if (variable.GetInicializada()) {
      FicheroEscritura << " = " << variable.GetValorInicial();
    }
    FicheroEscritura << std::endl;
  }
  FicheroEscritura << std::endl;
}

void GenerarReporte::EscribirSeccionBucle(std::ofstream& FicheroEscritura,
                                          const Estructura& estructura) {
  FicheroEscritura << "STATEMENTS:" << std::endl;
  std::vector<Bucle> cadena = estructura.GetVectorBucle();
  for (const auto& bucle : cadena) {
    FicheroEscritura << "[Line " << bucle.GetNumeroLinea() << "] LOOP: ";
    if (bucle.GetTipo() == TipoBucle::BUCLE_FOR) {
      FicheroEscritura << "for" << std::endl;
    } else if (bucle.GetTipo() == TipoBucle::BUCLE_WHILE) {
      FicheroEscritura << "while" << std::endl;
    } 
  }
  FicheroEscritura << std::endl;
}

void GenerarReporte::EscribirSeccionMain(std::ofstream& FicheroEscritura,
                                         const Estructura& estructura) {
  FicheroEscritura << "MAIN:" << std::endl;
  FicheroEscritura << (estructura.GetTieneMain() ? "True" : "False") << std::endl;
  FicheroEscritura << std::endl;
}

void GenerarReporte::EscribirSeccionComentarios(std::ofstream& FicheroEscritura,
                                                const Estructura& estructura) {
  FicheroEscritura << "COMMENTS:" << std::endl;
  std::vector<Comentario> cadena = estructura.GetVectorComentarios();
  for (const auto& comentario : cadena) {
    const auto& lineas = comentario.GetNumeroLineas();
    // NO mostrar el primer comentario si es la descripcion del archivo
    if (lineas.size() > 0 && lineas[0] == 1 &&
        comentario.GetContenido() == estructura.GetDescripcionPrograma()) {
      FicheroEscritura << "[Line " << lineas.front() << "-" << lineas.back()
                       << "] DESCRIPTION" << std::endl;
    } else if (lineas.size() == 1) {
      FicheroEscritura << "[Line " << lineas[0] << "] "
                       << comentario.GetContenido() << std::endl;
    } else if (lineas.size() > 1) {
      FicheroEscritura << "[Line " << lineas.front() << "-" << lineas.back()
                       << "] " << comentario.GetContenido() << std::endl;
    }
  }
}