#pragma once

#include <vector>
#include <iostream>

#include "sub_tree.hpp"
#include "point_types.hpp"

namespace EMST {

  class PointSet : public CyA::PointVector {
   public:
    explicit PointSet(const CyA::PointVector& points);
    ~PointSet();

    void ComputeEMST();

    void WriteTree(std::ostream& os) const;
    void WriteDot(std::ostream& os) const; // Requisito opcional implementado

    inline const CyA::Tree& GetTree() const { return emst_arcs_; }
    inline const CyA::PointVector& GetPoints() const { return *this; }
    inline double GetTotalCost() const { return ComputeCost(); }

   private:
    void ComputeArcVector(CyA::ArcVector& arc_vector) const;
    void FindIncidentSubTrees(const Forest& forest, const CyA::Arc& arc, int& index_1, int& index_2) const;
    void MergeSubTrees(Forest& forest, const CyA::Arc& arc, int index_1, int index_2) const;

    double ComputeCost() const;
    double EuclideanDistance(const CyA::Arc& arc) const;

    CyA::Tree emst_arcs_;
  };

}  // namespace EMST