#include <iostream>
#define tamanho 5

using namespace std;

typedef struct Pilha {
    int topo = 0;
    int item [tamanho];
};

bool pilhaVazia (Pilha p) {
    if (p.topo == 0) {
        return true;
    } else {
        return false;
    }
}

bool pilhaCheia (Pilha p) {
    int tam = (int)p.item;

    if (p.topo < tam) {
        return false;
    } else {
        return true;
    }
}

void empilha (Pilha &p, int x) {
    p.item[p.topo++] = x;
}

int desempilha (Pilha &p) {
    return (p.item[--p.topo]);
}

int mostraPilha (Pilha p) {
    cout << "Valores da pilha: ";
    for (int i = 0; i < p.topo; i++) {
        cout << p.item[i] << ' ';
    }
    cout << '\n';
}

int main() {

    Pilha duracell;

    if (pilhaVazia(duracell)) {
        cout << "A pilha esta vazia.\n";
    } else {
        cout << "A pilha nao esta vazia.\n";
    }

    empilha(duracell, 10);
    if (pilhaVazia(duracell)) {
        cout << "A pilha esta vazia.\n";
    } else {
        cout << "A pilha nao esta vazia.\n";
    }

    empilha(duracell, 20);
    empilha(duracell, 30);
    empilha(duracell, 40);

    mostraPilha(duracell);

    if (pilhaCheia(duracell)) {
        cout << "A pilha esta cheia.\n";
    } else {
        cout << "A pilha nao esta cheia.\n";
    }

    cout << "Valor desempilhado: " << desempilha(duracell) << '\n';

    mostraPilha(duracell);

    return 0;
}