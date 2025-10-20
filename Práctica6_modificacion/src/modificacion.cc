// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: David Javier Rodríguez Fumero
// Correo: alu0101706085@ull.edu.es
// Fecha: 18/10/2025
// Archivo modificacion.cc: Programa encargado de definir los métodos de la clase
// modificacion.
// Referencias: https://google.github.io/styleguide/cppguide.html
// Enlaces de interés:
// https://campusvirtual.ull.es/2526/ingenieriaytecnologia/mod/resource/view.php?id=11856

#include "../include/modificacion.h"

#include <set>
#include <vector>

#include "../include/transicion.h"
#include "../include/estado.h"

bool Modificacion::EsDFA(Estructura& estructura) const {
  std::set<char> alfabeto = estructura.GetAlfabeto();
  std::set<Estado> estados = estructura.GetCadenaEstados();
  for (const auto& estado : estados) {
      std::set<Transicion> transiciones = estado.GetSetTransiciones();
      std::set<char> simbolos_transicionados;
    for (const auto& transicion : transiciones) {
      char valor = transicion.GetValorTransicion();
      // Verificar que el símbolo esté en el alfabeto
      if (alfabeto.find(valor) == alfabeto.end()) {
        return false;
      }
      // Verificar unicidad de símbolos
      if (simbolos_transicionados.find(valor) != simbolos_transicionados.end()) {
        return false; // más de una transición para el mismo símbolo
      }
      simbolos_transicionados.insert(valor);
    }
    // Verificar que haya una transición para cada símbolo del alfabeto
    if (simbolos_transicionados.size() != alfabeto.size()) {
      return false;
    }
  }
  return true;
}

void Modificacion::MotrarEstadosAlcanzables(const int identificador, Estructura& estructura) {
    Estado estado = estructura.GetEstadoEspecifico(identificador);
    std::set<unsigned> estados_alcanzables;
    // Guardamos los destinos directos de las transiciones
    for (const auto& transicion : estado.GetSetTransiciones()) {
        estados_alcanzables.insert(transicion.GetDestino());
    }
    // Mostrar los estados alcanzables directamente
    std::cout << "Los estados alcanzables por q" << identificador << " son: ";
    for (unsigned id_estado : estados_alcanzables) {
        std::cout << id_estado << " ";
    }
    std::cout << std::endl;
    // Mostrar los estados no alcanzables directamente
    std::cout << "Los estados no alcanzables por q" << identificador << " son: ";
    for (const auto& estado_obj : estructura.GetCadenaEstados()) {
        unsigned id_estado = estado_obj.GetIdentificador(); // <-- usar el ID
        if (estados_alcanzables.find(id_estado) == estados_alcanzables.end()) {
            std::cout << id_estado << " ";
        }
    }
    std::cout << std::endl;
}
