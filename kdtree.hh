#ifndef kdtree.hh
#define kdtree.hh

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

typedef std::vector<float> Point;


struct KDTreePoint
{
        Point point;
        KDTreeNode* left;
        KDTreeNode* right;
       
        KDTreePoint(const Point& p) : point(p), left(nullptr), right(nullptr));
};

class KDTree {

private:
    KDTreeNode* root;

    KDTreeNode* buildTree(std::vector<Point>& points, int depth);
  
public:
    //Constructor arbol vacio
    KDTree();

    //Constructor con n puntos k-dimensionales
    KDTree(std::vector<Point> points);
 

    //Metodo para añadir una clave k-dimensional al árbol
    void insertPoint(Point);

    // Función de búsqueda de un punto en el árbol.
    search(const Point& target);

    // Destructor para liberar la memoria.
    ~KDTree();
};

