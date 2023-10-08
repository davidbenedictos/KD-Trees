#include "kdtree.hh"

//Constructor para arbol vacio

KDTree::KDTree() : root(nullptr) {
    // Implementación del constructor para un árbol KD vacío
}

KDTree::KDTree(const std::vector<Point>& points) {
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

void KDTree::printNode(const Point& p, int n) {
        int k = p.size();
        std::cout <<'('<< n << "| ";
        for (int i = 0; i < k; ++i) {
            if (i != 0) std::cout << ", ";
            std::cout << std::fixed << std::setprecision(2) << p[i];
        }
        std::cout << ")";
}

void KDTree::print() {
        std::queue<std::pair<KDTreeNode*, int>> q;

        if (root != nullptr) q.push(std::make_pair(root, 1));
        int lvl = 1;
        KDTreeNode* node;

        while (not q.empty()) {
            node = q.front().first;
            if (std::log2(q.front().second) >= lvl) {
                std::cout << std::endl;
                lvl = lvl+1;
            }
            if (node != nullptr){
                q.push(std::make_pair(node->left, q.front().second*2));
                q.push(std::make_pair(node->right, q.front().second*2+1));
                printNode(node->point, q.front().second);
            } 
            q.pop();
        }
        std::cout << std::endl;
}

void KDTree::destroyTree(KDTreeNode* node) {
    if (node == nullptr) return;

    destroyTree(node->left);
    destroyTree(node->right);

    delete node;
}

float KDTree::dist(const Point& a, const Point& b) {
    float d = 0.;
    for (int i = 0; i < a.size(); ++i) {
        float dif = a[i] - b[i];
        d += dif*dif;
    }
    return sqrt(d);
}


KDTreeNode* KDTree::closest(const Point& n, KDTreeNode* temp, KDTreeNode* r) {
    if (temp == nullptr) return r;

    float distanceRoot = dist(n, r -> point);
    float distanceTemp = dist(n, temp -> point);

    if (distanceTemp <= distanceRoot) return temp;
    return r;
}

KDTreeNode* KDTree::nearestNode(const Point& p) {
    return nearestNode(root, p, 0);
}


KDTreeNode* KDTree::nearestNode(KDTreeNode* r, const Point& n, int depth) {
    if (r == nullptr) return nullptr;

    int d = depth%n.size();
    KDTreeNode* next;
    KDTreeNode* other;

    if (n[d] < r -> point[d]) {
        next = r -> left;
        other = r -> right;
    } else {
        next = r -> right;
        other = r -> left;
    }

    KDTreeNode* temp = nearestNode(next, n, depth + 1);
    KDTreeNode* best = closest(n, temp, r);


    int bestRadius = dist(n, best -> point); 
    int distD = std::abs(n[d] - (r -> point[d]));

    if (bestRadius >= distD) {
        temp = nearestNode(other, n, depth + 1);
        best = closest(n, temp, r);
    }

    return best;
}

KDTree::~KDTree() {
    // Implementa la eliminación de nodos y liberación de memoria aquí.
    destroyTree(root);
}


int main() {
    // Ejemplo de uso:
    

    // Elegir tamaño 
    std::cout << "Elige Número de nodos y número de variables:" << std::endl;
    int N,K;
    std::cin >> N >> K;

    // Elegir modo de creacion
    std::cout << "Elige modo de creación (0 es aleatorio y 1 es a mano):" << std::endl; 
    bool modo;
    std::cin >> modo;

    if (modo) {
        // Elegir nodos del arbol
        std::vector<Point> v(N, Point(K));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < K; ++j) std::cin >> v[i][j];
        }
        KDTree t(v);

        t.print();

        // Insertar un punto k-dimensional
        Point p;
        float x;
        for (int i = 0; i < K; ++i) {
            std::cin >> x;
            p.push_back(x);
            t.insert(p);
        }

        // Imprimir árbol
        t.print();
    }
    else {
        // Generar árbol aleatorio
        KDTree t(N,K);

        t.print();

        // Insertar un punto k-dimensional
        Point p;
        float x;
        for (int i = 0; i < K; ++i) {
            std::cin >> x;
            p.push_back(x);
            t.insert(p);
        }

        // Imprimir árbol
        t.print();
    }
    
    return 0;
}

/*
7 2 1
0.03
0.06
0.02
0.07
0.17
0.15
0.06
0.12
0.09
0.01
0.13
0.15
0.1
0.19
*/