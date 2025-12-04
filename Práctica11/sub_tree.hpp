#pragma once

#include <iostream>
#include <cmath>
#include <vector>

#include "point_types.hpp"

namespace EMST {

  class SubTree {
   public:
    SubTree();
    ~SubTree();

    void AddArc(const CyA::Arc& arc);
    void AddPoint(const CyA::Point& point);
    bool Contains(const CyA::Point& point) const;
    void Merge(const SubTree& other_subtree, const CyA::WeightedArc& connecting_arc);

    inline const CyA::Tree& GetArcs() const { return arcs_; }
    inline double GetCost() const { return cost_; }

   private:
    CyA::Tree arcs_;
    CyA::PointCollection points_;
    double cost_;
  };

  using Forest = std::vector<SubTree>;

}  // namespace EMST