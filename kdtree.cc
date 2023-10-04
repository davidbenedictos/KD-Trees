#include "kdtree.hh"

//Constructor para arbol vacio

KDTree::KDTree() : root(nullptr) {
    // Implementación del constructor para un árbol KD vacío
}

KDTree::KDTree(std::vector<Point>& points) {
    root = createNode(points[0]);
    for(int i = 1; i < points.size(); ++i){
      insertPoint(root, points[i], 0);
    }
}

KDTree::KDTree(int N, int K) {
    // Generar numeros aleatorios en el intervalo [0, 1]
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0, 1);

    // Vector con N puntos de K dimensiones
    std::vector<Point> points(N, Point(K));
    for (int i=0; i < N; ++i) {
        for (int j = 0; j < K; ++j) points[i][j] = dist(mt);
    }

    // Llamar al constructor con vector de puntos aleatorios
    KDTree(points);
}

KDTreeNode* KDTree::createNode(Point p) {
    KDTreeNode* node = new KDTreeNode;
        node->point = p;
        node->left = node->right = nullptr;
    return node;
}

KDTreeNode* KDTree::insertPoint(KDTreeNode* r, Point p, int depth) {
    
    if (r == nullptr){       
        return createNode(p);
    } else {
        int k = p.size();
        int i = depth%k;
        if(p[i] < r->point[i]){
            r->left = insertPoint(r->left, p, depth + 1);
        } else {
             r->right = insertPoint(r->right, p, depth + 1);
        }
    }
    return r;
}

void KDTree::destroyTree(KDTreeNode* node) {
    if(node == nullptr) return;

    destroyTree(node->left);
    destroyTree(node->right);

    delete node;

}

~KDTree() {
    // Implementa la eliminación de nodos y liberación de memoria aquí.
    destroyTree(root);
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
