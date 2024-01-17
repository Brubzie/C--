#ifndef CLIENTES_HEADER
#define CLIENTES_HEADER

#include <iostream>
#include <string>

using namespace std;

// Estruturas
struct Cliente {
    string nomeCliente;
    string emailCliente;
    long long numeroCliente;
    Cliente *prox;
};

// Funções
void inicializar(Cliente* cliente) {
    cliente->emailCliente = "";
    cliente->nomeCliente = "";
    cliente->numeroCliente = 0;
    cliente->prox = nullptr;
}

#endif