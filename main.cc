#include "kdtree.hh"


int main() {
    // Elegir tamaño 
    std::cout << "Elige Número de nodos y número de variables:" << std::endl;
    int N;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0, 1);
    Point p;
    float media = 0.0;
    int nodeExpanded = 0;
    while(cin >> N){
         for(int i = 2; i <= 6; ++i){
            cout << "Creamos arbol con k = " << i << endl;
            KDTree t(N, i);
            media = 0;
            for(int k = 0; k < 30; ++k){
                nodeExpanded = 0;
                Point p(i);
                for(int j = 0; j < i ; ++j){
                    p[j] =   dist(mt);
                }
                cout << "Resultado " << k+1 << " ";
                t.nearestNode(p, nodeExpanded);
                media += nodeExpanded;
            }
            media /= 30.0;
            cout << "Media para k= " << i << " : " << media << endl;
            cout << endl;

         }
    }
 


    return 0;

}
