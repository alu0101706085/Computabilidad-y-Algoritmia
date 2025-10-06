// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares en C++
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 07/10/2025
// Archivo clase_Generar_Reporte.h: Programa encargado de definir las 
// funciones necesarias para generar los resultados buscados.
// Referencias:
// https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#ifndef CLASE_GENERAR_REPORTE
#define CLASE_GENERAR_REPORTE

#include <string>
#include "clase_Estructura.h"

class GenerarReporte {
public:
    void GenerarResultado(const std::string& fichero_salida, const Estructura& estructura);
private:
    void EscribirSeccionPrograma(std::ofstream& FicheroEscritura, const Estructura& estructura);
    void EscribirSeccionDescipcion(std::ofstream& FicheroEscritura, const Estructura& estructura);
    void EscribirSeccionVariable(std::ofstream& FicheroEscritura, const Estructura& estructura);
    void EscribirSeccionBucle(std::ofstream& FicheroEscritura, const Estructura& estructura);
    void EscribirSeccionMain(std::ofstream& FicheroEscritura, const Estructura& estructura);
    void EscribirSeccionComentarios(std::ofstream& FicheroEscritura, const Estructura& estructura);
};

#endif