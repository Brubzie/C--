#include <iostream>

#define tamanho_max 100

using namespace std;

struct Fila {
    int elementos[tamanho_max];
    int frente;
    int tras;
    int tamanho;

    Fila() {
        frente = -1;
        tras = -1;
        tamanho = 0;
    }
};

bool estaVazia(const Fila& fila) {
    return fila.tamanho == 0;
}

bool estaCheia(const Fila& fila) {
    return fila.tamanho == tamanho_max;
}

void enfileirar(Fila& fila, int valor) {
    if (estaCheia(fila)) {
        cout << "Fila cheia. Nao foi possivel enfileirar.\n";
        return;
    }

    if (fila.frente == -1) {
        fila.frente = 0;
    }

    fila.tras = (fila.tras + 1) % tamanho_max;
    fila.elementos[fila.tras] = valor;
    fila.tamanho++;
}

void desenfileirar(Fila& fila) {
    if (estaVazia(fila)) {
        cout << "Fila vazia. Nao foi possivel desenfileirar.\n";
        return;
    }

    if (fila.frente == fila.tras) {
        fila.frente = -1;
        fila.tras = -1;
    } else {
        fila.frente = (fila.frente + 1) % tamanho_max;
    }

    fila.tamanho--;
}

int frente(const Fila& fila) {
    if (estaVazia(fila)) {
        cout << "Fila vazia. Nao ha elementos na frente da fila.\n";
        return -1; // Retornando um valor indicando erro
    }

    return fila.elementos[fila.frente];
}

int main() {

    Fila fila;

    enfileirar(fila, 10);
    enfileirar(fila, 20);
    enfileirar(fila, 30);

    cout << "Frente da fila: " << frente(fila) << '\n';

    desenfileirar(fila);

    cout << "Frente da fila depois de desenfileirar: " << frente(fila) << '\n';

    return 0;
}