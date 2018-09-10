#pragma once

inline HalfedgeDual HalfedgeMesh::dual() {
   return HalfedgeDual(*this);
}

// Methods for getting number of mesh elements

// Primal

inline size_t HalfedgeMesh::nHalfedges          (void) const { return          rawHalfedges.size(); }
inline size_t HalfedgeMesh::nCorners            (void) const { return          rawHalfedges.size(); }
inline size_t HalfedgeMesh::nVertices           (void) const { return           rawVertices.size(); }
inline size_t HalfedgeMesh::nEdges              (void) const { return              rawEdges.size(); }
inline size_t HalfedgeMesh::nFaces              (void) const { return              rawFaces.size(); }
inline size_t HalfedgeMesh::nBoundaryLoops      (void) const { return      rawBoundaryLoops.size(); }
inline size_t HalfedgeMesh::nImaginaryHalfedges (void) const { return rawImaginaryHalfedges.size(); }

// Dual

inline size_t HalfedgeDual::nHalfedges (void) const { return rawHalfedges.size(); }
inline size_t HalfedgeDual::nVertices  (void) const { return  rawVertices.size(); }
inline size_t HalfedgeDual::nEdges     (void) const { return     rawEdges.size(); }
inline size_t HalfedgeDual::nFaces     (void) const { return     rawFaces.size(); }


// Methods for iterating over mesh elements w/ range-based for loops ===========

// Primal

inline HalfedgePtrSet HalfedgeMesh::halfedges(void) {

   size_t nH = rawHalfedges.size();
   HalfedgePtr beginptr(&rawHalfedges[0]);
   HalfedgePtr endptr(&rawHalfedges[nH]); // note that we really want nH and not nH-1, since we want the address one past the final element

   return HalfedgePtrSet(beginptr, endptr);
}

inline HalfedgePtrSet HalfedgeMesh::imaginaryHalfedges(void) {

   size_t nH = rawImaginaryHalfedges.size();
   HalfedgePtr beginptr(&rawImaginaryHalfedges[0]);
   HalfedgePtr endptr(&rawImaginaryHalfedges[nH]);

   return HalfedgePtrSet(beginptr, endptr);
}

inline CutPtrSet HalfedgeMesh::cutBoundary(int loop) {
    
    if (nBoundaryLoops() == 0) {
        for (EdgePtr e: edges()) {
            if (e.isCut()) return CutPtrSet(e.halfedge());
        }
    }
    
    HalfedgePtr he = loop == -1 ? boundaryLoop(longestBoundaryLoop()).halfedge() :
                                  boundaryLoop(loop).halfedge();
    return CutPtrSet(he);
}

inline CornerPtrSet HalfedgeMesh::corners(void) {
    
    size_t nC = rawHalfedges.size();
    CornerPtr beginptr(&rawHalfedges[0]);
    CornerPtr endptr(&rawHalfedges[nC]);
    
    return CornerPtrSet(beginptr, endptr);
}

inline VertexPtrSet HalfedgeMesh::vertices(void) {

   size_t nV = rawVertices.size();
   VertexPtr beginptr{&rawVertices[0]};
   VertexPtr endptr{&rawVertices[nV]};

   return VertexPtrSet(beginptr, endptr);
}

inline EdgePtrSet HalfedgeMesh::edges(void) {

   size_t nE = rawEdges.size();
   EdgePtr beginptr{&rawEdges[0]};
   EdgePtr endptr{&rawEdges[nE]};

   return EdgePtrSet(beginptr, endptr);
}

inline FacePtrSet HalfedgeMesh::faces(void) {

   size_t nF = rawFaces.size();
   FacePtr beginptr{&rawFaces[0]};
   FacePtr endptr{&rawFaces[nF]};

   return FacePtrSet(beginptr, endptr);
}

inline BoundaryPtrSet HalfedgeMesh::boundaryLoops(void) {

   size_t nBL = rawBoundaryLoops.size();
   BoundaryPtr beginptr{&rawBoundaryLoops[0]};
   BoundaryPtr endptr{&rawBoundaryLoops[nBL]};

   return BoundaryPtrSet(beginptr, endptr);
}

// Dual

inline DualHalfedgePtrSet HalfedgeDual::halfedges(void) {

   size_t ndH = rawHalfedges.size();
   DualHalfedgePtr beginptr(&rawHalfedges[0]);
   DualHalfedgePtr endptr(&rawHalfedges[ndH]);

   return DualHalfedgePtrSet(beginptr, endptr);
}

inline DualVertexPtrSet HalfedgeDual::vertices(void) {

   size_t ndV = rawVertices.size();
   DualVertexPtr beginptr{&rawVertices[0]};
   DualVertexPtr endptr{&rawVertices[ndV]};

   return DualVertexPtrSet(beginptr, endptr);
}

inline DualEdgePtrSet HalfedgeDual::edges(void) {

   size_t ndE = rawEdges.size();
   DualEdgePtr beginptr{&rawEdges[0]};
   DualEdgePtr endptr{&rawEdges[ndE]};

   return DualEdgePtrSet(beginptr, endptr);
}

inline DualFacePtrSet HalfedgeDual::faces(void) {

   size_t ndF = rawFaces.size();
   DualFacePtr beginptr{&rawFaces[0]};
   DualFacePtr endptr{&rawFaces[ndF]};

   return DualFacePtrSet(beginptr, endptr);
}

// Methods for accessing elements by index =====================================

// Primal

inline HalfedgePtr HalfedgeMesh::halfedge(size_t index) {
   return HalfedgePtr{&rawHalfedges[index]};
}

inline HalfedgePtr HalfedgeMesh::imaginaryHalfedge(size_t index) {
   return HalfedgePtr{&rawImaginaryHalfedges[index]};
}

inline CornerPtr HalfedgeMesh::corner(size_t index) {
    return CornerPtr{&rawHalfedges[index]};
}

inline VertexPtr HalfedgeMesh::vertex(size_t index) {
   return VertexPtr{&rawVertices[index]};
}

inline EdgePtr HalfedgeMesh::edge(size_t index) {
   return EdgePtr{&rawEdges[index]};
}

inline FacePtr HalfedgeMesh::face(size_t index) {
   return FacePtr{&rawFaces[index]};
}

inline BoundaryPtr HalfedgeMesh::boundaryLoop(size_t index) {
   return BoundaryPtr{&rawBoundaryLoops[index]};
}

// Dual

inline DualHalfedgePtr HalfedgeDual::halfedge(size_t index) {
   return DualHalfedgePtr{&rawHalfedges[index]};
}

inline DualVertexPtr HalfedgeDual::vertex(size_t index) {
   return DualVertexPtr{&rawVertices[index]};
}

inline DualEdgePtr HalfedgeDual::edge(size_t index) {
   return DualEdgePtr{&rawEdges[index]};
}

inline DualFacePtr HalfedgeDual::face(size_t index) {
   return DualFacePtr{&rawFaces[index]};
}


