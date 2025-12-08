/**
 * @file point_set.hpp
 * @brief Clase principal que hereda de vector de puntos e implementa Kruskal.
 */

#pragma once

#include <vector>
#include <iostream>

#include "sub_tree.hpp"
#include "point_types.hpp"

namespace EMST {

  /**
   * @class PointSet
   * @brief Gestiona un conjunto de puntos y calcula su EMST.
   */
  class PointSet : public CyA::VectorPuntos {
   public:
    /**
     * @brief Constructor.
     * @param puntos Vector inicial de puntos.
     */
    explicit PointSet(const CyA::VectorPuntos& puntos);
    ~PointSet();

    /**
     * @brief Ejecuta el algoritmo Voraz (Kruskal) para calcular el EMST.
     */
    void CalcularEMST();

    /**
     * @brief Escribe el árbol resultante en texto plano a un flujo de salida.
     * @param os Flujo de salida.
     */
    void EscribirArbol(std::ostream& os) const;

    /**
     * @brief Escribe el árbol en formato DOT (Graphviz).
     * @param os Flujo de salida.
     */
    void EscribirDOT(std::ostream& os) const;

    inline const CyA::Arbol& ObtenerArbol() const { return emst_aristas_; }
    inline const CyA::VectorPuntos& ObtenerPuntos() const { return *this; }
    inline double ObtenerCosteTotal() const { return CalcularCoste(); }

   private:
    /**
     * @brief Genera todas las posibles aristas entre puntos y calcula sus distancias.
     * @param vector_aristas Vector donde se almacenarán las aristas ponderadas ordenadas.
     */
    void CalcularVectorAristas(CyA::VectorAristas& vector_aristas) const;

    /**
     * @brief Busca en qué sub-árboles del bosque se encuentran los extremos de una arista.
     * @param bosque El bosque actual de sub-árboles.
     * @param arista La arista a comprobar.
     * @param id_1 Referencia para devolver el índice del sub-árbol del primer punto.
     * @param id_2 Referencia para devolver el índice del sub-árbol del segundo punto.
     */
    void EncontrarSubArbolesIncidentes(const Bosque& bosque, const CyA::Arista& arista, int& id_1, int& id_2) const;

    /**
     * @brief Fusiona dos sub-árboles del bosque.
     * @param bosque El bosque a modificar.
     * @param arista La arista que conecta los árboles.
     * @param id_1 Índice del primer sub-árbol.
     * @param id_2 Índice del segundo sub-árbol.
     */
    void FusionarSubArboles(Bosque& bosque, const CyA::Arista& arista, int id_1, int id_2) const;

    double CalcularCoste() const;
    double DistanciaEuclidea(const CyA::Arista& arista) const;

    CyA::Arbol emst_aristas_; /**< Almacena el resultado final del árbol */
  };

}  // namespace EMST