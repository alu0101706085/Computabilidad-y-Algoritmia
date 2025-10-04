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
  bool main_encontrado;
};

#endif


