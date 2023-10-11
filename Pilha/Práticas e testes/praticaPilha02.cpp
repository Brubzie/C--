#include <iostream>
#define PILHA 10 // Tamanho máximo da pilha

using namespace std;

struct Pilha {
    int arr[PILHA]; // Array para armazenar os elementos da pilha
    int topo;      // Índice do topo da pilha

    Pilha() : topo(-1) {}

    void push(int elemento) {
        if (topo == PILHA - 1) {
            cout << "[Erro] Pilha cheia!\n";

            return;
        }

        arr[++topo] = elemento; // Incrementa o topo e insere o elemento na posição correspondente
    }

    void pop() {
        if (topo == -1) {
            cout << "[Erro] Pilha vazia!\n";

            return;
        }

        --topo; // Apenas decrementa o topo (elemento será "removido" na próxima inserção)
    }

    int top() {
        if (topo == -1) {
            cout << "[Erro] Pilha vazia!\n";
            return -1; // Valor indicando erro
        }

        return arr[topo]; // Retorna o elemento no topo
    }

    bool isEmpty() {
        return topo == -1;
    }
};

int main() {
    Pilha pilha;

    pilha.push(5);
    pilha.push(10);
    pilha.push(7);

    cout << "Topo da pilha: " << pilha.top() << "\n";

    pilha.pop();

    cout << "Topo da pilha apos pop: " << pilha.top() << "\n";

    return 0;
}