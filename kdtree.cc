#include "kdtree.hh"

//Constructor para arbol vacio

KDTree::KDTree() : root(nullptr) {
    // Implementación del constructor para un árbol KD vacío
}


KDTree::KDTree(std::vector<Point>& points) : root(nullptr){  
    for(int i = 0; i < points.size(); ++i){
      insertPoint(root, points[i], 0);
    }
} 

KDTreeNode* KDTree::createNode(Point p){
    KDTreeNode* node = new KDTreeNode;
        node->point = p;
        node->left = node->right = nullptr;
}

KDTreeNode* KDTree::insertPoint(KDTreeNode* r, Point p, int depth){
    
    KDTreeNode* node = createNode(p);
    
    if (root == nullptr){       
        return node;
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
