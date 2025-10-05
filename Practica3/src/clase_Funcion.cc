#include "clase_Funcion.h"
#include "clase_PatronesRegex.h"

#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <string>

void Funcion::AnalizarFichero(const std::string& fichero_entrada, Estructura& estructura) {
  estructura.SetNombreArchivo(fichero_entrada);
  std::ifstream ficheroLectura(fichero_entrada);
  if (!ficheroLectura) {
    std::cerr << "Error, no se pudo abrir el fichero de lectura.\n";
  } else {
    std::string linea;
    int numero_linea{1};
    while (std::getline(ficheroLectura, linea)) {
      AnalizarLinea(linea, numero_linea, estructura);
      numero_linea++;
    }
  }
  estructura.SetTieneMain(main_encontrado);
  ficheroLectura.close();
}

void Funcion::AnalizarLinea(const std::string& linea, int numero_linea, Estructura& estructura) {
  DetectarVariable(linea, numero_linea, estructura);
  DetectarBucle(linea, numero_linea, estructura);
  DetectarComentario(linea, numero_linea, estructura);
  DetectarMain(linea, numero_linea, estructura);
}

void Funcion::DetectarVariable(const std::string& linea, int numero_linea, Estructura& estructura) {
  std::smatch matches;
  if (std::regex_search(linea, matches, PatronesRegex::INT_VARIABLE_REGEX)) {
    Variable valor;
    valor.SetTipo(TipoVariable::VAR_INT);
    std::string nombre = matches[1].str();
    valor.SetNombre(nombre);
    valor.SetNumeroLinea(numero_linea);
    bool esta_inicializada = matches[2].matched;
    valor.SetInicializada(esta_inicializada);
    if (matches[2].matched) {
      std::string valor_inical = matches[2].str();
      if (!valor_inical.empty() && valor_inical[0] == '=') {
        valor_inical = valor_inical.substr(1);
      }
      valor.SetValorInicial(valor_inical);
    }
    estructura.AddVariable(valor);
  } else if (std::regex_search(linea, matches, PatronesRegex::DOUBLE_VARIABLE_REGEX)) {
    Variable valor;
    valor.SetTipo(TipoVariable::VAR_DOUBLE);
    std::string nombre = matches[1].str();
    valor.SetNombre(nombre);
    valor.SetNumeroLinea(numero_linea);
    bool esta_inicializada = matches[2].matched;
    valor.SetInicializada(esta_inicializada);
    if (matches[2].matched) {
      std::string valor_inical = matches[2].str();
      if (!valor_inical.empty() && valor_inical[0] == '=') {
        valor_inical = valor_inical.substr(1);
      }
      valor.SetValorInicial(valor_inical);
    }
    estructura.AddVariable(valor);
  }
}

void Funcion::DetectarBucle(const std::string& linea, int numero_linea, Estructura& estructura) {
  std::smatch matches;
  if (std::regex_search(linea, matches, PatronesRegex::FOR_LOOP_REGEX)) {
    Bucle bucle;
    bucle.SetNumeroLinea(numero_linea);
    bucle.SetTipo(TipoBucle::BUCLE_FOR);
    estructura.AddBucle(bucle);
  } else if (std::regex_search(linea, matches, PatronesRegex::WHILE_LOOP_REGEX)) {
    Bucle bucle;
    bucle.SetNumeroLinea(numero_linea);
    bucle.SetTipo(TipoBucle::BUCLE_WHILE);
    estructura.AddBucle(bucle);
  }
}

void Funcion::DetectarComentario(const std::string& linea, int numero_linea, Estructura& estructura) {
  std::smatch matches;
  // Caso 1: Buscamos una sola linea
  if (std::regex_search(linea, matches, PatronesRegex::SINGLE_LINE_COMMENT_REGEX)) {
    Comentario comentario;
    comentario.SetTipo(TipoComentario::UNA_LINEA);
    std::string contenido = matches[0].str();
    comentario.SetContenido(contenido);
    std::vector<int> numero;
    numero.push_back(numero_linea);
    comentario.SetNumeroLineas(numero);
    if (!primer_comentario_encontrado && numero_linea == 1) {
      estructura.SetDescripcionPrograma(contenido);
      primer_comentario_encontrado = true;
      descripcion_establecida = true;
    }
    estructura.AddComentario(comentario);
  // Caso 2: Buscamos el inicio de un comentario multilinea
  } else if (std::regex_search(linea, matches, PatronesRegex::MULTI_LINE_COMMENT_START_REGEX)) {
    dentro_de_un_comentario_multilinea = true;
    inicio_multi_linea = numero_linea;
    contenido_comentario_multi_linea = linea + "\n";
    if (!primer_comentario_encontrado && numero_linea == 1) {
      primer_comentario_encontrado = true;
    }
    if (std::regex_search(linea, matches, PatronesRegex::MULTI_LINE_COMMENT_END_REGEX)) {
      Comentario comentario;
      comentario.SetTipo(TipoComentario::MULTIPLE_LINEA);
      comentario.SetContenido(contenido_comentario_multi_linea);
      comentario.SetNumeroLineas({numero_linea});
      if(!descripcion_establecida && numero_linea == 1) {
        estructura.SetDescripcionPrograma(contenido_comentario_multi_linea);
        descripcion_establecida = true;
      }
      estructura.AddComentario(comentario);
      dentro_de_un_comentario_multilinea = false;
      contenido_comentario_multi_linea.clear();
    }
  // Caso 3: Seguimos dentro de un comentario multilinea
  } else if (dentro_de_un_comentario_multilinea) {
    contenido_comentario_multi_linea += linea + "\n";
    if (std::regex_search(linea, matches, PatronesRegex::MULTI_LINE_COMMENT_END_REGEX)) {
      Comentario comentario;
      comentario.SetTipo(TipoComentario::MULTIPLE_LINEA);
      comentario.SetContenido(contenido_comentario_multi_linea);
      std::vector<int> lineas;
      for (int i{inicio_multi_linea}; i <= numero_linea; i++) {
        lineas.push_back(i);
      }
      comentario.SetNumeroLineas(lineas);
      if (!descripcion_establecida && inicio_multi_linea == 1) {
        estructura.SetDescripcionPrograma(contenido_comentario_multi_linea);
        descripcion_establecida = true;
      }
      estructura.AddComentario(comentario);
      dentro_de_un_comentario_multilinea = false;
      contenido_comentario_multi_linea.clear();
    }
    return;
  }
}

void Funcion::DetectarMain(const std::string& linea, int numero_linea, Estructura& estructura) {
  std::smatch matches;
  if (std::regex_search(linea, matches, PatronesRegex::MAIN_FUNCTION_REGEX)) {
    main_encontrado = true;
    estructura.SetTieneMain(true);
  }
}