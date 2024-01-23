#ifndef WEEK_HEADER
#define WEEK_HEADER

#include <iostream>
#include <string>
#include <fstream>

//Estruturas
struct Usuario {
    std::string nomeDeUsuario;
};

struct Node {
    Usuario usuario;
    Node* proximo;
    Node* anterior;
};

struct ListaDeTarefas {
    Node* primeiro;
    Node* ultimo;
    int tamanho;
};

// Funções
void limpar() {
    #ifdef _WIN32 // <= Identifica se o SO é Windows
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar() {
    #ifdef _WIN32
        system("pause");
    #else
        std::cout << "Pressione ENTER para continuar..." << std::endl;
        std::cin.ignore();
    #endif
}

void inicializar(ListaDeTarefas* lista) {
    lista->primeiro = nullptr;
    lista->ultimo = nullptr;
    lista->tamanho = 0;
}

void destruir(ListaDeTarefas* lista) {
    if (lista->primeiro != nullptr) {
        while (lista->primeiro != nullptr) {
            Node* aux = lista->primeiro;
            lista->primeiro = lista->primeiro->proximo;
            delete aux;
        }
        lista->ultimo = nullptr;
        lista->tamanho = 0;
    } else {
        std::cout << "[ERRO] Lista vazia." << std::endl;
    }
}

void cadastroDeTarefa(ListaDeTarefas* lista, Usuario* usuario) {
    Node* novo = new Node{ *usuario, nullptr, nullptr };

    if (lista->primeiro == nullptr) {
        lista->primeiro = novo;
        lista->ultimo = novo;
    } else {
        lista->ultimo->proximo = novo;
        novo->anterior = lista->ultimo;
        lista->ultimo = novo;
    }

    lista->tamanho++;

    std::cin.ignore(numeric_limits<streamsize>::max(),'\n');

    std::cout << "Informe sua tarefa: ";
    std::getline(cin, tarefas);

    arquivo << tarefas << std::endl;
}

#endif