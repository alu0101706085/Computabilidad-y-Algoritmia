// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares en C++
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 07/10/2025
// Archivo clase_Funcion.h: Programa encargado de definir las 
// funciones necesarias para analizar un fichero dado.
// Referencias:
// https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#ifndef CLASE_FUNCION
#define CLASE_FUNCION

#include <iostream>
#include <string>
#include <vector>

#include "clase_Bucle.h"
#include "clase_Comentario.h"
#include "clase_Estructura.h"
#include "clase_Variable.h"

class Funcion {
 public:
  Funcion() = default;
  void AnalizarFichero(const std::string& fichero_entrada, Estructura& estructura);
 private:
  void AnalizarLinea(const std::string& linea, int numero_linea, Estructura& estructura);
  void DetectarVariable(const std::string& linea, int numero_linea, Estructura& estructura);
  void DetectarBucle(const std::string& linea, int numero_linea, Estructura& estructura);
  void DetectarComentario(const std::string& linea, int numero_linea, Estructura& estructura);
  void DetectarMain(const std::string& linea, int numero_linea, Estructura& estructura);
  std::string GuardarResultadoFinal(std::string& fichero_salida, Estructura& estructura);
  bool dentro_de_un_comentario_multilinea = false;
  int inicio_multi_linea = 0;
  std::string contenido_comentario_multi_linea;
  bool main_encontrado = false;
  bool primer_comentario_encontrado = false;
  bool descripcion_establecida = false;
  // Modificaciones
  bool dentro_de_un_do_while = false;
  int inicio_do_while = 0;
};

#endif


