#include <iostream>

using namespace std;

struct tipoCelula {
    int item; // Armazena o valor
    tipoCelula *prox;
};

int pilha_contador;
tipoCelula *topo;

bool pilha_construtor() {
    topo = NULL;
    pilha_contador = 0;
}

bool pilha_destrutor() {
    int aux;
    tipoCelula *temp;
    if (pilha_vazia()) {
        return false;
    } else {
        while (topo != NULL) {
            topo = topo->prox;
            temp->prox = NULL;

            topo = topo->prox;

            free(temp);
        }
        pilha_contador = 0;

        return true;
    }
}

int pilha_tamanho() {
    return pilha_contador;
}

bool pilha_push(int valor) { // Empilhar
    tipoCelula *novaCelula = (tipoCelula *)malloc(sizeof(tipoCelula));

    if (novaCelula == NULL) { // Caso o SO não forneça memória RAM
        return false;
    } else {
        novaCelula->item = valor;
        novaCelula->prox = topo;

        topo = novaCelula;

        pilha_contador++;

        return true;
    }
}

bool pilha_pop(int &valor) { // Desempilhar
    tipoCelula *temp;
    if (pilha_vazia()) {
        return false;
    } else {
        valor = topo->item;
        topo = topo->prox;

        temp->prox = NULL; // Medida de segurança para desligar a célula removida da pilha

        free(temp); // Livrando a memória
        pilha_contador--;

        return true;
    }
}

bool pilha_get(int &valor) { // Obtém o elemento no topo da pilha
    if (pilha_vazia()) {
        return false;
    } else {
        valor = topo->item;

        return true;
    }
}

/*
Pilha cheia é desnecessário
*/

bool pilha_vazia() {
    if (topo == NULL) {
        return true;
    } else {
        return false;
    }
}

int main() {

    /*
    int *p;

    p = (int*)malloc(sizeof(int));
    */

    return 0;
}