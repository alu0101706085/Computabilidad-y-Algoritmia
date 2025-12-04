#include "point_set.hpp"

#include <cmath>
#include <algorithm>
#include <iomanip>
#include <map>

namespace EMST {

  PointSet::PointSet(const CyA::PointVector& points) 
      : CyA::PointVector(points), emst_arcs_() {}

  PointSet::~PointSet() {}

  void PointSet::ComputeEMST() {
    CyA::ArcVector all_possible_arcs;
    ComputeArcVector(all_possible_arcs);

    Forest forest;

    // 1. Inicialización: Cada punto es un sub-árbol independiente
    for (const CyA::Point& point : *this) {
      SubTree sub_tree;
      sub_tree.AddPoint(point);
      forest.push_back(sub_tree);
    }

    // 2. Algoritmo Voraz (Kruskal)
    for (const CyA::WeightedArc& weighted_arc : all_possible_arcs) {
      int tree_idx_1, tree_idx_2;
      FindIncidentSubTrees(forest, weighted_arc.second, tree_idx_1, tree_idx_2);

      // Si los puntos pertenecen a árboles diferentes, unimos los árboles (evitamos ciclos)
      if (tree_idx_1 != tree_idx_2) {
        MergeSubTrees(forest, weighted_arc.second, tree_idx_1, tree_idx_2);
      }
    }

    // Al final, el bosque debe contener un solo árbol que es el EMST
    if (!forest.empty()) {
      emst_arcs_ = forest[0].GetArcs();
    }
  }

  void PointSet::ComputeArcVector(CyA::ArcVector& arc_vector) const {
    arc_vector.clear();
    const int num_points = size();

    // Generar todos los pares posibles (grafo completo)
    for (int i = 0; i < num_points - 1; ++i) {
      const CyA::Point& point_i = (*this)[i];

      for (int j = i + 1; j < num_points; ++j) {
        const CyA::Point& point_j = (*this)[j];

        CyA::Arc arc = std::make_pair(point_i, point_j);
        double dist = EuclideanDistance(arc);

        arc_vector.push_back(std::make_pair(dist, arc));
      }
    }

    // Paso crítico del algoritmo voraz: Ordenar por coste ascendente
    std::sort(arc_vector.begin(), arc_vector.end());
  }

  void PointSet::FindIncidentSubTrees(const Forest& forest, const CyA::Arc& arc, int& index_1, int& index_2) const {
    index_1 = -1;
    index_2 = -1;

    for (size_t i = 0; i < forest.size(); ++i) {
      if (forest[i].Contains(arc.first)) {
        index_1 = static_cast<int>(i);
      }
      if (forest[i].Contains(arc.second)) {
        index_2 = static_cast<int>(i);
      }
      
      // Optimización: si ya encontramos ambos, salimos
      if (index_1 != -1 && index_2 != -1) return;
    }
  }

  void PointSet::MergeSubTrees(Forest& forest, const CyA::Arc& arc, int index_1, int index_2) const {
    double weight = EuclideanDistance(arc);
    CyA::WeightedArc weighted_arc = std::make_pair(weight, arc);

    // Fusionamos el segundo árbol dentro del primero
    forest[index_1].Merge(forest[index_2], weighted_arc);

    // Eliminamos el segundo árbol del bosque ya que ha sido absorbido
    // Usamos iterador para borrar
    forest.erase(forest.begin() + index_2);
  }

  double PointSet::ComputeCost() const {
    double total_cost = 0.0;
    for (const auto& arc : emst_arcs_) {
      total_cost += EuclideanDistance(arc);
    }
    return total_cost;
  }

  double PointSet::EuclideanDistance(const CyA::Arc& arc) const {
    double dx = arc.first.first - arc.second.first;
    double dy = arc.first.second - arc.second.second;
    return std::sqrt(dx * dx + dy * dy);
  }

  void PointSet::WriteTree(std::ostream& os) const {
    os << "Árbol Generador Mínimo (EMST):" << std::endl;
    for (const auto& arc : emst_arcs_) {
      os << "(" << arc.first.first << ", " << arc.first.second << ") -- "
         << "(" << arc.second.first << ", " << arc.second.second << ")"
         << " Coste: " << EuclideanDistance(arc) << std::endl;
    }
    os << "Coste Total: " << GetTotalCost() << std::endl;
  }

  void PointSet::WriteDot(std::ostream& os) const {
    os << "graph EMST {" << std::endl;
    os << "  node [shape=circle, style=filled, fillcolor=white];" << std::endl;

    // Asignamos un ID entero a cada punto para facilitar la sintaxis DOT
    std::map<CyA::Point, int> point_ids;
    int id_counter = 0;

    // Dibujar nodos con posición fija (formato neato)
    for (const auto& point : *this) {
      point_ids[point] = id_counter;
      os << "  " << id_counter << " [pos=\"" 
         << point.first << "," << point.second << "!\", label=\"" 
         << id_counter << "\"];" << std::endl;
      id_counter++;
    }

    // Dibujar aristas con etiquetas de distancia
    for (const auto& arc : emst_arcs_) {
      int id_1 = point_ids[arc.first];
      int id_2 = point_ids[arc.second];
      double dist = EuclideanDistance(arc);
      
      os << "  " << id_1 << " -- " << id_2 
         << " [label=\"" << std::fixed << std::setprecision(2) << dist << "\"];" 
         << std::endl;
    }

    os << "}" << std::endl;
  }

}  // namespace EMST