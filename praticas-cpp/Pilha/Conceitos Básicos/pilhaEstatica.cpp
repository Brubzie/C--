// TAD - Tipo Abstrato de Dados
#include <iostream>

using namespace std;

#define tamPilha = 1000;

int pilha[tamPilha];
int topo;

void pilha_construtor() {
    topo = -1;
}

bool pilha_vazia() {
    if (topo == -1) {
        return true;
    } else {
        return false;
    }
}

int pilha_tamanho() {
    return topo +1;
}

bool pilha_cheia() {
    if (topo == tamPilha -1) {
        return true;
    } else {
        return false;
    }
}

bool pilha_push(int valor) { // push = empilhar
    if (pilha_cheia()) {
        return false;
    } else {
        topo++;
        pilha[topo] = valor;
        return true;
    }
}

bool pilha_pop(int &valor) { // pop = desempilhar
    if (pilha_vazia()) {
        return false;
    } else {
        valor = pilha[topo];
        topo--;
        return true;
    }
}

bool pilha_get(int &valor) { // consulta
    if (pilha_vazia()) {
        return false;
    } else {
        valor = pilha[topo];
        return true;
    }
}

int main() {

    int valor = 0;

    pilha_construtor();

    pilha_push(5);
    pilha_push(7);
    pilha_push(9);
    pilha_push(1);
    pilha_push(2);

    cout << "Quantidade de itens da pilha: " << pilha_tamanho() << endl;

    while (pilha_pop(valor)) {
        cout << "\nDesempilhando: " << valor;
    }

    cout << "\n\nQuantidade de itens da pilha: " << pilha_tamanho() << endl;

    pilha_push(2);
    pilha_get(valor);
    cout << "\nEmpilhando: " << valor << endl;

    cout << "\nQuantidade de itens da pilha: " << pilha_tamanho() << endl;

    return 0;
}