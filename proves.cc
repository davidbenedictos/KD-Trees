#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<float> Point;

void printNode(const Point& p) {
    int k = p.size();
    for (int j = 0; j < k; ++j) {
            std::cout << p[j];
            if (j != k - 1) std::cout << ", ";
    }
}

void printNodes(const std::vector<Point>& nodes) {
    int n;
    n = nodes.size();
    
    for (int i = 0; i < n; ++i) {
        std::cout << "Node " << i << " (";
        printNode(nodes[i]);
        std::cout << ")" << std::endl;
    }
    
}

void readNode(Point& p) {
    int k = p.size();
    for (int j = 0; j < k; ++j) std::cin >> p[j];
}

void readNodes(std::vector<Point>& nodes) {
    int n = nodes.size();
    int k = nodes[0].size();
    std::cout << "Entra les k coordenades dels n punts " << std::endl;
    for (int i = 0; i < n; ++i) {
        readNode(nodes[i]);
    }
}

float dist(const Point& a, const Point& b) {
    float d = 0.;
    for (int i = 0; i < a.size(); ++i) {
        float dif = a[i] - b[i];
        d += dif*dif;
    }
    return sqrt(d);
}

//Retorna la distancia a la que esta cada nodo del punto objetivo
std::vector<float> distancias(const std::vector<Point>& nodes, const Point& objetivo) {
    int n = nodes.size();
    int k = nodes[0].size();

    std::vector<float> d(n);

    for (int i = 0; i < n; ++i) {
        d[i] = dist(objetivo, nodes[i]);
    }

    return d;
}

int main() {
    int n, k;
    std::cout << "N nodes de K dimensions: " << std::endl;
    std::cin >> n >> k;

    std::vector<Point> nodes(n, Point(k));
    
    readNodes(nodes);
    printNodes(nodes);

    Point objetivo(k);


    while (true) {
        std::cout << "Entra el nodo objetivo" << std::endl;
        readNode(objetivo);

        std::cout << "Distancia de cada nodo al nodo objetivo" << std::endl;
        printNode(distancias(nodes, objetivo));
        std::cout << std::endl;
    }


}