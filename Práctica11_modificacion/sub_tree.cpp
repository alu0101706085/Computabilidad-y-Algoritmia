/**
 * @file sub_tree.cpp
 * @brief Implementación de la clase SubTree.
 */

#include "sub_tree.hpp"
#include <algorithm>

namespace EMST {

  SubTree::SubTree() : aristas_(), puntos_(), coste_(0.0) {}

  SubTree::~SubTree() {}

  void SubTree::AgregarArista(const CyA::Arista& arista) {
    aristas_.push_back(arista);
    puntos_.insert(arista.first);
    puntos_.insert(arista.second);
  }

  void SubTree::AgregarPunto(const CyA::Punto& punto) {
    puntos_.insert(punto);
  }

  bool SubTree::Contiene(const CyA::Punto& punto) const {
    return puntos_.find(punto) != puntos_.end();
  }

  void SubTree::Fusionar(const SubTree& otro_subarbol, const CyA::AristaPonderada& arista_union) {
    // Insertamos las aristas del otro sub-árbol en este
    aristas_.insert(aristas_.end(), otro_subarbol.aristas_.begin(), otro_subarbol.aristas_.end());
    
    // Añadimos la arista que conecta ambos componentes
    aristas_.push_back(arista_union.second);

    // Insertamos los puntos del otro sub-árbol
    puntos_.insert(otro_subarbol.puntos_.begin(), otro_subarbol.puntos_.end());

    // Sumamos el coste de la nueva arista y el coste acumulado del otro sub-árbol
    coste_ += arista_union.first + otro_subarbol.ObtenerCoste();
  }

}  // namespace EMST