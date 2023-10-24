#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;

struct Ponto {
    int x, y;
};

double calcularDistancia(const Ponto& ponto1, const Ponto& ponto2) {
    // Calculando a distância usando a fórmula da distância entre dois pontos no plano cartesiano
    return sqrt(pow(ponto2.x - ponto1.x, 2) + pow(ponto2.y - ponto1.y, 2));
}

int main() {

    const char ESC = 27;
    Ponto ponto1, ponto2;

    do {
        system("cls");

        cout << "Coordenadas do Ponto 1 (x y): ";
        cin >> ponto1.x >> ponto1.y;

        cout << "Coordenadas do Ponto 2 (x y): ";
        cin >> ponto2.x >> ponto2.y;

        double distancia = calcularDistancia(ponto1, ponto2);

        cout << "\nA distancia entre os pontos (" << ponto1.x << "," << ponto1.y << ") e (" << ponto2.x << "," << ponto2.y << ") e: " << distancia << "\n";

        cout << "\nPressione a tecla ESC para encerrar...\n";
    } while (getch() != ESC);

    return 0;
}