#include <iostream>

using namespace std;

// Tamanho Máximo da Pilha
#define TAM_MAX 10

struct carro {
    string placa;
    int ano;
};

struct pilha {
    carro data[TAM_MAX];
    int contador;
};

// Protótipo de função
void inicializar(pilha *);

int main() {


    return 0;
}