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

#include "../include/clase_PatronesRegex.h"

#include <iostream>
#include <regex>

const std::regex PatronesRegex::INT_VARIABLE_REGEX(R"(int\s+(\w+)\s*((\=)\s*(\d+))?\s*;)");
const std::regex PatronesRegex::DOUBLE_VARIABLE_REGEX(R"(double\s+(\w+)\s*((\=)\s*(\d+)(\.\d+))?\s*;)");
const std::regex PatronesRegex::FOR_LOOP_REGEX(R"(for\s*\()");
const std::regex PatronesRegex::WHILE_LOOP_REGEX(R"(while\s*\()");
const std::regex PatronesRegex::SINGLE_LINE_COMMENT_REGEX(R"(\/\/[^\n]*)");
const std::regex PatronesRegex::MULTI_LINE_COMMENT_START_REGEX(R"(\/\*)");
const std::regex PatronesRegex::MULTI_LINE_COMMENT_END_REGEX(R"(\*\/)");
const std::regex PatronesRegex::MAIN_FUNCTION_REGEX(R"(int\s+main\s*\()");
// Modificaciones
const std::regex PatronesRegex::DO_WHILE_LOOP_START_REGEX(R"(^\s*do\s*\{?)");
const std::regex PatronesRegex::DO_WHILE_LOOP_END_REGEX(R"(}\s*while\s*\(.*\)\s*;)");
const std::regex PatronesRegex::STD_VARIABLE_REGEX(R"(std\s*::\s*\w+\s*\w+\s*(?:=\s*.+)?\s*;)");
const std::regex PatronesRegex::CLASE_VARIABLE_REGEX(R"(\b(?:class|struct)\s+(\w+)\s*(?::\s*(?:public|private|protected)\s+\w+)?\s*\{)");
const std::regex PatronesRegex::SWITCH_LOOP_REGEX(R"(switch\s*\((.*?)\)\s*\{)");
const std::regex PatronesRegex::IF_ELSE_LOOP_REGEX(R"(if\s*\((.*?)\)\s*(?:\{|\s*\w+))");