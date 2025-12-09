/**
 * @file sub_tree.hpp
 * @brief Definición de la clase SubTree para el manejo de componentes conexos.
 */

#pragma once

#include <iostream>
#include <cmath>
#include <vector>

#include "point_types.hpp"

namespace EMST {

  /**
   * @class SubTree
   * @brief Representa un sub-árbol o componente conexo en el bosque.
   * * Mantiene las aristas que forman el sub-árbol, los puntos que contiene
   * y el coste acumulado.
   */
  class SubTree {
   public:
    SubTree();
    ~SubTree();

    /**
     * @brief Añade una arista al sub-árbol.
     * @param arista La arista a añadir.
     */
    void AgregarArista(const CyA::Arista& arista);

    /**
     * @brief Añade un punto al conjunto de puntos del sub-árbol.
     * @param punto El punto a añadir.
     */
    void AgregarPunto(const CyA::Punto& punto);

    /**
     * @brief Verifica si un punto pertenece a este sub-árbol.
     * @param punto El punto a buscar.
     * @return true si el punto está presente, false en caso contrario.
     */
    bool Contiene(const CyA::Punto& punto) const;

    /**
     * @brief Fusiona otro sub-árbol con este.
     * @param otro_subarbol El sub-árbol a fusionar dentro de este.
     * @param arista_union La arista ponderada que conecta ambos sub-árboles.
     */
    void Fusionar(const SubTree& otro_subarbol, const CyA::AristaPonderada& arista_union);

    /** @return Referencia constante al vector de aristas. */
    inline const CyA::Arbol& ObtenerAristas() const { return aristas_; }

    /** @return El coste total del sub-árbol. */
    inline double ObtenerCoste() const { return coste_; }

   private:
    CyA::Arbol aristas_;            /**< Aristas internas del sub-árbol */
    CyA::ColeccionPuntos puntos_;   /**< Conjunto de puntos para búsqueda rápida */
    double coste_;                  /**< Suma de los pesos de las aristas */
  };

  /** @brief Un bosque es un vector de sub-árboles. */
  using Bosque = std::vector<SubTree>;

}  // namespace EMST