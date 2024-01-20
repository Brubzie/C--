#ifndef CLIENTES_HEADER
#define CLIENTES_HEADER

#include <iostream>
#include <string>
#include <random>

using namespace std;

// Estruturas
struct Cliente {
    string nomeCliente;
    string emailCliente;
    long long numeroCliente;
};

struct Node {
    Cliente cliente;
    Node* anterior;
    Node* prox;
};

struct ListaCompras {
    Node* primeiro;
    Node* ultimo;
    int tamanho;
};

// Funções
void inicializar(Cliente* cliente, ListaCompras* lista) {
    cliente->emailCliente = "";
    cliente->nomeCliente = "";
    cliente->numeroCliente = 0;
    lista->tamanho = 0;
    lista->primeiro = nullptr;
    lista->ultimo = nullptr;
}

void destruir(ListaCompras* lista) {
    if (lista->primeiro != nullptr) {
        while (lista->primeiro != nullptr) {
            Node* aux = lista->primeiro;
            lista->primeiro = lista->primeiro->prox;
            delete aux;
        }
    } else {
        cout << "[ERRO] Lista de Compras está vazia!" << endl;
    }
}

void criarSenha(int senha) {
    senha = 0;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1000, 9999);

    senha = dis(gen);

    cout << "Senha: " << senha << endl;
}

#endif