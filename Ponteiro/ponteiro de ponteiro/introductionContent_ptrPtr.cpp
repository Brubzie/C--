#include <iostream>

using namespace std;

int main() {
    // Criar um ponteiro para um ponteiro para um inteiro
    int** matriz;

    // Alocar memória para um vetor de 3 ponteiros
    matriz = new int*[3];

    // Para cada ponteiro, alocar memória para um vetor de 4 inteiros
    for(int i = 0; i < 3; i++) {
        matriz[i] = new int[4];
    }

    // Preencher a matriz com valores de 1 a 12
    int valor = 1;
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            matriz[i][j] = valor;
            valor++;
        }
    }

    // Imprimir a matriz na tela
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            cout << matriz[i][j] << ' ';
        }
        cout << endl;
    }

    // Liberar a memória alocada
    for(int i = 0; i < 3; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}