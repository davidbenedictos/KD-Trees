#include "kdtree.hh"

//Constructor para arbol vacio

KDTree::KDTree() : root(nullptr) {
    // Implementación del constructor para un árbol KD vacío
}


KDTree::KDTree(std::vector<Point>& points){
    root = buildTree(points, 0);
} 

void KDTree::insertPoint(Point point){
    //Ya lo haremos
}

KDTreeNode* KDTree::buildTree(std::vector<Point>& points, int depth) {
        if (points.empty()) {
            return nullptr;
        }

        int k = points[0].coordinates.size();
        int axis = depth % k;
        
        // Sort points and choose median as pivot element
        std::sort(points.begin(), points.end(), [axis](const Point& a, const Point& b) {
            return a.coordinates[axis] < b.coordinates[axis];
        });

        int median = points.size() / 2;

        // Create node and construct subtrees
        KDTreeNode* node = new KDTreeNode(points[median]);
        node->left = buildTree(std::vector<Point>(points.begin(), points.begin() + median), depth + 1);
        node->right = buildTree(std::vector<Point>(points.begin() + median + 1, points.end()), depth + 1);

        return node;
    }


    ~KDTree() {
        // Implementa la eliminación de nodos y liberación de memoria aquí.
    }

/*
int main() {
    // Ejemplo de uso:
    std::vector<Point> points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
    KDTree kdTree(points);

    // Realiza operaciones de búsqueda, inserción, eliminación, etc., según sea necesario.
    
    return 0;
}
*/
