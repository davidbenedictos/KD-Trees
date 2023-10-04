#ifndef kdtree.hh
#define kdtree.hh

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

typedef std::vector<float> Point;

class KDTree {

private:
    struct KDTreeNode
    {
        Point point;
        KDTreeNode* left;
        KDTreeNode* right;     
    };

    KDTreeNode* root;

    KDTreeNode* buildTree(std::vector<Point>& points, int depth);

    KDTreeNode* createNode(Point);

    void destroyTree(KDTreeNode* node);
  
public:
    //Constructor arbol vacio
    KDTree();

    //Constructor con n puntos k-dimensionales
    KDTree(std::vector<Point> p);

    //Metodo para añadir una clave k-dimensional al árbol
    KDTreeNode* insertPoint(KDTreeNode* r, Point p, int depth);

    // Función de búsqueda de un punto en el árbol.
    //search(const Point& target);

    // Destructor para liberar la memoria.
    ~KDTree();
};

