#include "sub_tree.hpp"

#include <algorithm>

namespace EMST {

  SubTree::SubTree() : arcs_(), points_(), cost_(0.0) {}

  SubTree::~SubTree() {}

  void SubTree::AddArc(const CyA::Arc& arc) {
    arcs_.push_back(arc);
    points_.insert(arc.first);
    points_.insert(arc.second);
  }

  void SubTree::AddPoint(const CyA::Point& point) {
    points_.insert(point);
  }

  bool SubTree::Contains(const CyA::Point& point) const {
    return points_.find(point) != points_.end();
  }

  void SubTree::Merge(const SubTree& other_subtree, const CyA::WeightedArc& connecting_arc) {
    // Fusionar los arcos del otro sub-árbol
    arcs_.insert(arcs_.end(), other_subtree.arcs_.begin(), other_subtree.arcs_.end());
    
    // Añadir el arco que conecta ambos árboles
    arcs_.push_back(connecting_arc.second);

    // Fusionar los puntos del otro conjunto
    points_.insert(other_subtree.points_.begin(), other_subtree.points_.end());

    // Actualizar el coste total
    cost_ += connecting_arc.first + other_subtree.GetCost();
  }

}  // namespace EMST