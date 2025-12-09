/**
 * @file point_set.cpp
 * @brief Implementación para calcular el Árbol de Expansión MÁXIMA.
 */

#include "point_set.hpp"

#include <cmath>
#include <algorithm>
#include <iomanip>
#include <map>

namespace EMST {

  PointSet::PointSet(const CyA::VectorPuntos& puntos) 
      : CyA::VectorPuntos(puntos), emst_aristas_() {}

  PointSet::~PointSet() {}

  void PointSet::CalcularEMST() {
    CyA::VectorAristas todas_aristas;
    CalcularVectorAristas(todas_aristas);

    Bosque bosque;

    // 1. Inicialización: Cada punto crea su propio sub-árbol
    for (const CyA::Punto& punto : *this) {
      SubTree sub_arbol;
      sub_arbol.AgregarPunto(punto);
      bosque.push_back(sub_arbol);
    }

    // 2. Bucle Voraz: Procesar aristas.
    for (const CyA::AristaPonderada& arista_pond : todas_aristas) {
      int id_arbol_1, id_arbol_2;
      EncontrarSubArbolesIncidentes(bosque, arista_pond.second, id_arbol_1, id_arbol_2);

      // Si los puntos están en árboles distintos, fusionamos (evitamos ciclos)
      if (id_arbol_1 != id_arbol_2) {
        FusionarSubArboles(bosque, arista_pond.second, id_arbol_1, id_arbol_2);
      }
    }

    // Al final, el bosque debería tener un solo componente
    if (!bosque.empty()) {
      emst_aristas_ = bosque[0].ObtenerAristas();
    }
  }

  void PointSet::CalcularVectorAristas(CyA::VectorAristas& vector_aristas) const {
    vector_aristas.clear();
    const int num_puntos = size();

    // Generar grafo completo (todos contra todos)
    for (int i = 0; i < num_puntos - 1; ++i) {
      const CyA::Punto& p_i = (*this)[i];

      for (int j = i + 1; j < num_puntos; ++j) {
        const CyA::Punto& p_j = (*this)[j];

        CyA::Arista arista = std::make_pair(p_i, p_j);
        double dist = DistanciaEuclidea(arista);

        vector_aristas.push_back(std::make_pair(dist, arista));
      }
    }

    // --- MODIFICACIÓN---
    std::sort(vector_aristas.rbegin(), vector_aristas.rend());
  }

  void PointSet::EncontrarSubArbolesIncidentes(const Bosque& bosque, const CyA::Arista& arista, int& id_1, int& id_2) const {
    id_1 = -1;
    id_2 = -1;

    for (size_t i = 0; i < bosque.size(); ++i) {
      if (bosque[i].Contiene(arista.first)) {
        id_1 = static_cast<int>(i);
      }
      if (bosque[i].Contiene(arista.second)) {
        id_2 = static_cast<int>(i);
      }
      
      // Optimización: salir si ya encontramos ambos
      if (id_1 != -1 && id_2 != -1) return;
    }
  }

  void PointSet::FusionarSubArboles(Bosque& bosque, const CyA::Arista& arista, int id_1, int id_2) const {
    double peso = DistanciaEuclidea(arista);
    CyA::AristaPonderada arista_pond = std::make_pair(peso, arista);

    // Fusionar el árbol en posición id_2 dentro del árbol en id_1
    bosque[id_1].Fusionar(bosque[id_2], arista_pond);

    // Eliminar el árbol absorbido del bosque
    bosque.erase(bosque.begin() + id_2);
  }

  double PointSet::CalcularCoste() const {
    double coste_total = 0.0;
    for (const auto& arista : emst_aristas_) {
      coste_total += DistanciaEuclidea(arista);
    }
    return coste_total;
  }

  double PointSet::DistanciaEuclidea(const CyA::Arista& arista) const {
    double dx = arista.first.first - arista.second.first;
    double dy = arista.first.second - arista.second.second;
    return std::hypot(dx, dy); 
  }

  void PointSet::EscribirArbol(std::ostream& os) const {
    for (const auto& arista : emst_aristas_) {
      os << "(" << arista.first.first << ", " << arista.first.second << ") -> "
         << "(" << arista.second.first << ", " << arista.second.second << ")"
         << " [" << std::fixed << std::setprecision(2) << DistanciaEuclidea(arista) << "]" << std::endl;
    }
    os << std::endl << "Coste total (MÁXIMO): " << ObtenerCosteTotal() << std::endl;
  }

  void PointSet::EscribirDOT(std::ostream& os) const {
    os << "graph MaxST {" << std::endl;
    os << "  node [shape=circle, style=filled, fillcolor=white];" << std::endl;

    std::map<CyA::Punto, int> ids_puntos;
    int contador_id = 0;

    for (const auto& punto : *this) {
      ids_puntos[punto] = contador_id;
      os << "  " << contador_id << " [pos=\"" 
         << punto.first << "," << punto.second << "!\", label=\"" 
         << contador_id << "\"];" << std::endl;
      contador_id++;
    }

    for (const auto& arista : emst_aristas_) {
      int id_1 = ids_puntos[arista.first];
      int id_2 = ids_puntos[arista.second];
      double dist = DistanciaEuclidea(arista);
      
      os << "  " << id_1 << " -- " << id_2 
         << " [label=\"" << std::fixed << std::setprecision(2) << dist << "\"];" 
         << std::endl;
    }

    os << "}" << std::endl;
  }

}  // namespace EMST