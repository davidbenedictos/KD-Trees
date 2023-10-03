#include "kdtree.hh"


struct Point {
    std::vector<int> coordinates;
};

class KDTreeNode {
public:
    Point point;
    KDTreeNode* left;
    KDTreeNode* right;

    KDTreeNode(const Point& p) : point(p), left(nullptr), right(nullptr) {}
};

class KDTree {
private:
    KDTreeNode* root;

    KDTreeNode* buildTree(std::vector<Point>& points, int depth) {
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

public:
    KDTree(std::vector<Point>& points) : root(nullptr) {
        root = buildTree(points, 0);
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

int main() {
    // Ejemplo de uso:
    std::vector<Point> points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
    KDTree kdTree(points);

    // Realiza operaciones de búsqueda, inserción, eliminación, etc., según sea necesario.
    
    return 0;
}
