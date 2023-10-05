#ifndef __KDTREE_HH__
#define __KDTREE_HH__

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

typedef std::vector<float> Point;

struct KDTreeNode
    {
        Point point;
        KDTreeNode* left;
        KDTreeNode* right;     
    };

class KDTree {

private:

    KDTreeNode* root;

    //KDTreeNode* buildTree(std::vector<Point>& points, int depth);

    KDTreeNode* createNode(const Point& p);

    void destroyTree(KDTreeNode* node);

    void printTree(KDTreeNode* node, int depth);
  
public:
    //Constructor arbol vacio
    KDTree();

    //Constructor con n puntos k-dimensionales
    KDTree(std::vector<Point>& points);

    //Constructor con n puntos k-dimensionales aleatorios
    KDTree(int N, int K);

    //Metodo para añadir una clave k-dimensional al árbol
    KDTreeNode* insertPoint(KDTreeNode* r, const Point& p, int depth);

    // Función de búsqueda de un punto en el árbol.
    //search(const Point& target);

    // Función para imprimir el árbol.
    void print();

    // Función para un punto en el árbol.
    void insert(const Point& p);

    // Destructor para liberar la memoria.
    ~KDTree();
};

#endif
