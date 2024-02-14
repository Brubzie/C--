#include <iostream>

using namespace std;

int const filaMax = 1000;

int frente, tras;
int fila[filaMax];

void fila_construtor() {
    frente = 0;
    tras = -1;
}

bool fila_vazia() {
    if (frente > tras) {
        return true;
    } else {
        return false;
    }

    // return frente > tras;
}

bool fila_cheia() {
    if (tras == filaMax -1) {
        return true;
    } else {
        return false;
    }
}

bool fila_enfileirar(int valor) {
    if (fila_cheia()) {
        return false;
    } else {
        tras++;
        fila[tras] = valor;

        return true;
    }
}

bool fila_desenfileirar(int &valor) {
    if (fila_vazia()) {
        return false;
    } else {
        valor = fila[frente];
        frente++;

        return true;
    }
}

bool fila_get(int &valor) {
    if (fila_vazia()) {
        return false;
    } else {
        valor = fila[frente];

        return true;
    }
}

int fila_tamanho() {
    return (tras - frente) +1;
}

int main() {

    int valor;
    fila_construtor();
    
    fila_enfileirar(5);
    fila_enfileirar(2);
    fila_enfileirar(7);

    cout << "Tamanho da fila: " << fila_tamanho << '\n';

    while (fila_desenfileirar(valor)) {
        cout << "\nValor: " << valor;
    }

    /*
    if (fila_desenfileirar(valor)) {
        cout << "\nValor: " << valor << '\n';
    } else {
        cout << "\nFila vazia\n";
    }
    */

    cout << "\nTamanho da fila: " << fila_tamanho;

    return 0;
}