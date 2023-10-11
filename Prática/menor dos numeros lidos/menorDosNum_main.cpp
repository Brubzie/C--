#include <iostream>

using namespace std;

const int tamLinhas = 3; // Tamanho da matriz (3x3)

int main() {
    int l1[tamLinhas], l2[tamLinhas], l3[tamLinhas];

    // Preenchendo as matrizes l1, l2 e l3
    for (int i = 0; i < tamLinhas; ++i) {
        cout << "Digite um numero para a linha 1: ";
        cin >> l1[i];

        cout << "Digite um numero para a linha 2: ";
        cin >> l2[i];

        cout << "Digite um numero para a linha 3: ";
        cin >> l3[i];

        system ("cls");
    }

    // Inicializando a matriz linhas
    int linhas[tamLinhas][tamLinhas] = {
        {l1[0], l1[1], l1[2]},
        {l2[0], l2[1], l2[2]},
        {l3[0], l3[1], l3[2]}
    };

    // Exibindo a matriz
    for (int i = 0; i < tamLinhas; ++i) {
        for (int j = 0; j < tamLinhas; ++j) {
            cout << linhas[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}