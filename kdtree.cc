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

    // Construir el árbol con vector de puntos aleatorios
    root = createNode(points[0]);
    for(int i = 1; i < points.size(); ++i){
        insertPoint(root, points[i], 0);
    }
}

KDTreeNode* KDTree::createNode(const Point& p) {
    KDTreeNode* node = new KDTreeNode;
        node->point = p;
        node->left = node->right = nullptr;
    return node;
}

KDTreeNode* KDTree::insertPoint(KDTreeNode* r, const Point& p, int depth) {
    
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

void KDTree::insert(const Point& p) {
    insertPoint(root,p,0);
}

void KDTree::printNode(const Point& p){
        int k = p.size();
        std::cout << '(';
        for (int i = 0; i < k; ++i) {
            if (i != 0) std::cout << ", ";
            std::cout << p[i];
        }
        std::cout << ")" << std::endl;
}

void KDTree::printTree(KDTreeNode* node){
    if (node != nullptr) {
        printTree(node -> left);
        printNode(node -> point);
        printTree(node -> right);
        
}

void KDTree::print() {
        printTree(root);
        std::cout << std::endl;
}

void KDTree::destroyTree(KDTreeNode* node) {
    if(node == nullptr) return;

    destroyTree(node->left);
    destroyTree(node->right);

    delete node;

}

KDTree::~KDTree() {
    // Implementa la eliminación de nodos y liberación de memoria aquí.
    destroyTree(root);
}

/*
int main() {
    // Ejemplo de uso:
    // Generar árbol aleatorio
    int N,K;
    std::cin >> N >> K;
    KDTree t(N,K);

    // Imprimir árbol
    t.print();

    // Insertar un punto k-dimensional
    Point p;
    float x;
    for (int i = 0; i < K; ++i) {
        std::cin >> x;
        p.push_back(x);
    }
    t.insert(p);
    
    // Imprimir árbol
    t.print();

    // Realiza operaciones de búsqueda, inserción, eliminación, etc., según sea necesario.
    
    return 0;
}
*/
