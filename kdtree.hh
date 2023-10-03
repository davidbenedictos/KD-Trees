#ifndef kdtree.hh
#define kdtree.hh

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

struct Point {
    std::vector<int> coordinates;
};

class KDTreeNode {
public:
    Point point;
    KDTreeNode* left;
    KDTreeNode* right;

    KDTreeNode(const Point& p) : point(p), left(nullptr), right(nullptr);
};

class KDTree {
private:
    KDTreeNode* root;

    KDTreeNode* buildTree(std::vector<Point>& points, int depth) 
  
public:
    KDTree(std::vector<Point>& points) : root(nullptr) {
    
    }

    // Implementar funciones de búsqueda, inserción, eliminación y otras según tus necesidades.

    // Función de búsqueda de un punto en el árbol.
    KDTreeNode* search(const Point& target) {
        // Implementa la búsqueda aquí.
    }

    // Destructor para liberar la memoria.
    ~KDTree() {
        // Implementa la eliminación de nodos y liberación de memoria aquí.
    }
};

