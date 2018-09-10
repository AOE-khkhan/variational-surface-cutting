#pragma once

#include "geometry.h"

namespace GC {

    /*
        === Standard operators from DDG, using circumcentric dual, defined over the entire mesh ===

        All use the standard indexing convention according to mesh->getVertexIndices() (etc).
        Edge orientation convention is according to the direction of edge.halfedge.

        Note that discrete_operators.cpp contains explicit instantiations of these for T={double,Complex},
        and D=Euclidean. We should (TODO) probably move that to a .ipp file so they can be instantiated for
        user-specified types, then use macro-magic to explicitly instantiate them for the popular types. 
        Right now, they effectively same real-valued matrix is being built in all cases, its just the type
        that differs.
    */

    // TODO Implement a combined operator that builds all (many?) of these at once, saving recomputation

    // Hodge star on 0-forms. Returns a (nVerts, nVerts) matrix.
    template<typename T, typename D>
    GC::SparseMatrix<T> buildHodge0(Geometry<D>* geometry);

    // Hodge star on 1-forms. Returns a (nEdges, nEdges) matrix.
    template<typename T, typename D>
    GC::SparseMatrix<T> buildHodge1(Geometry<D>* geometry);

    // Hodge star on 2-forms. Returns a (nFaces, nFaces) matrix.
    template<typename T, typename D>
    GC::SparseMatrix<T> buildHodge2(Geometry<D>* geometry);

    // Derivative on 0-forms. Returns a (nEdges, nVerts) matrix
    template<typename T>
    GC::SparseMatrix<T> buildDerivative0(HalfedgeMesh* mesh);

    // Derivative on 1-forms. Returns a (nFaces, nEdges) matrix
    template<typename T>
    GC::SparseMatrix<T> buildDerivative1(HalfedgeMesh* mesh);

}