#ifndef HEADER_PASTELARIA
#define HEADER_PASTELARIA

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <limits>
#include <random>

using namespace std;

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
        cout << "Pressione ENTER para continuar..." << endl;
        cin.ignore();
    #endif
}


struct Ingredientes {
    int massa;
    int queijo;
    int presunto;
    int tomate;
    int frango;
};

struct Pedido {
    string nomeDoCliente;
    int senhaDoPedido;
    int pasteisDePizza;
    int pasteisDeQueijo;
    int pasteisDeFrango;
    int pasteisDeVento;
    int refriCoca;
    int refriPepsi;
};

struct Node {
    Pedido pedido;
    Node* proximo;
    Node* anterior;
};

struct ListaPedidos {
    Node* primeiro;
    Node* ultimo;
    int tamanho;
    Ingredientes ingredientesDisponiveis;
};

void inicializar(ListaPedidos* lista) {
    lista->primeiro = nullptr;
    lista->ultimo = nullptr;
    lista->tamanho = 0;

    // Ingredientes dos Pastéis
    lista->ingredientesDisponiveis.queijo = 50000; // 50kg
    lista->ingredientesDisponiveis.presunto = 20000; // 20kg
    lista->ingredientesDisponiveis.frango = 10000; // 10kg
}

void destruir(ListaPedidos* lista) {
    while (lista->primeiro != nullptr) {
        Node* aux = lista->primeiro;
        lista->primeiro = lista->primeiro->proximo;
        delete aux;
    }

    lista->ultimo = nullptr;
    lista->tamanho = 0;
}

bool verificarIngredientes(ListaPedidos* lista, int queijo, int presunto, int frango) {
    // Verifica se há ingredientes o suficiente
    return (lista->ingredientesDisponiveis.queijo >= queijo &&
            lista->ingredientesDisponiveis.presunto >= presunto &&
            lista->ingredientesDisponiveis.frango >= frango);
}

void usarIngredientes(ListaPedidos* lista, int queijo, int presunto, int frango) {
    // Subtrair os ingredientes utilizados
    lista->ingredientesDisponiveis.queijo -= queijo;
    lista->ingredientesDisponiveis.presunto -= presunto;
    lista->ingredientesDisponiveis.frango -= frango;
}

void cadastrarPedido(ListaPedidos* lista, Pedido* pedido) {
    Node* novo = new Node{ *pedido, nullptr, nullptr };

    if (lista->primeiro == nullptr) {
        lista->primeiro = novo;
        lista->ultimo = novo;
    } else {
        lista->ultimo->proximo = novo;
        novo->anterior = lista->ultimo;
        lista->ultimo = novo;
    }

    lista->tamanho++;

    cout << endl << "Pedido cadastrado com sucesso!" << endl;

    pausar();
}

void editarPedido(ListaPedidos* lista, int senha) {
    Node* atual = lista->primeiro;

    while (atual != nullptr && atual->pedido.senhaDoPedido != senha) {
        atual = atual->proximo;
    }

    if (atual == nullptr) {
        cout << endl << "[ERRO] Pedido não encontrado!" << endl;
        pausar();
        return; // Retorna se 'atual' é nulo
    }

    lista->ingredientesDisponiveis.massa += (atual->pedido.pasteisDePizza + atual->pedido.pasteisDeQueijo + atual->pedido.pasteisDeFrango + atual->pedido.pasteisDeVento) * 30;
    lista->ingredientesDisponiveis.queijo += atual->pedido.pasteisDeQueijo * 50;

    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "==== Edição do Pedido ====" << endl;
    cout << "Informe o novo nome do cliente: ";
    getline(cin, atual->pedido.nomeDoCliente);

    int quantidadePizza, quantidadeQueijo, quantidadeFrango, quantidadeVento;

    cout << "Pastéis de pizza comprados: ";
    cin >> quantidadePizza;
    
    cout << "Pastéis de queijo comprados: ";
    cin >> quantidadeQueijo;
    
    cout << "Pastéis de frango comprados: ";
    cin >> quantidadeFrango;
    
    cout << "Pastéis de vento comprados: ";
    cin >> quantidadeVento;

    // Calcular a quantidade total de cada ingrediente
    int totalMassa = quantidadePizza * 30 + quantidadeQueijo * 50;
    int totalQueijo = quantidadeQueijo * 50;
    int totalFrango = quantidadeFrango * 30 + quantidadeVento * 30;

    if (verificarIngredientes(lista, totalMassa, totalQueijo, totalFrango)) {
        usarIngredientes(lista, totalMassa, totalQueijo, totalFrango);
    } else {
        cout << "\n[ERRO] Ingredientes insuficientes!\n";
    }

    cout << "Informe a nova quantidade de Coca-Cola comprada: ";
    cin >> atual->pedido.refriCoca;

    cout << "Informe a nova quantidade de Pepsi comprada: ";
    cin >> atual->pedido.refriPepsi;

    cout << "\nPedido editado com sucesso!\n";

    pausar();
}

void removerPedido(ListaPedidos* lista, int senha) {
    Node* atual = lista->primeiro;

    while (atual != nullptr && atual->pedido.senhaDoPedido != senha) {
        atual = atual->proximo;
    }

    if (atual == nullptr) {
        cout << "[ERRO] Pedido não encontrado!" << endl;
        return; // Retorna se 'atual' é nulo
    }

    // Adicionar os ingredientes utilizados de volta
    lista->ingredientesDisponiveis.massa += (atual->pedido.pasteisDePizza + atual->pedido.pasteisDeQueijo + atual->pedido.pasteisDeFrango + atual->pedido.pasteisDeVento) * 30;
    lista->ingredientesDisponiveis.queijo += atual->pedido.pasteisDeQueijo * 50;

    // Remover o pedido da lista
    if (atual->anterior != nullptr) {
        atual->anterior->proximo = atual->proximo;
    } else {
        lista->primeiro = atual->proximo;
    }

    if (atual->proximo != nullptr) {
        atual->proximo->anterior = atual->anterior;
    } else {
        lista->ultimo = atual->anterior;
    }

    delete atual;
    lista->tamanho--;

    cout << endl << "Pedido entregue removido com sucesso!" << endl;

    pausar();
}

void mostrarPedidos(ListaPedidos* lista) {
    Node* atual = lista->primeiro;

    ofstream arquivo("pedidos.txt");
    if (!arquivo) {
        cout << "Não foi possível abrir o arquivo." << endl;
        return;
    }

    arquivo << "==== Pedidos ====\n";

    if (atual != nullptr) {
        while (atual != nullptr) {
            arquivo << "Senha do Pedido: " << atual->pedido.senhaDoPedido << endl;
            arquivo << "Cliente: " << atual->pedido.nomeDoCliente << endl;
            arquivo << "Quantidade de Pastéis de Pizza: " << atual->pedido.pasteisDePizza << endl;
            arquivo << "Quantidade de Pastéis de Queijo: " << atual->pedido.pasteisDeQueijo << endl;
            arquivo << "Quantidade de Pastéis de Frango: " << atual->pedido.pasteisDeFrango << endl;
            arquivo << "Quantidade de Pastéis de Vento: " << atual->pedido.pasteisDeVento << endl;
            arquivo << "Quantidade de Coca-Cola: " << atual->pedido.refriCoca << endl;
            arquivo << "Quantidade de Pepsi: " << atual->pedido.refriPepsi << endl << endl;

            atual = atual->proximo;  
        }
    } else {
        arquivo << "[ERRO] A lista de pedidos está vazia!\n";
        arquivo << "Selecione a opção 1 no menu, para cadastrar seu pedido.\n";
    }

    arquivo.close();

    // Redefinir 'atual' para o início da lista
    atual = lista->primeiro;

    cout << "==== Pedidos ====\n";

    if (atual != nullptr) {
        while (atual != nullptr) {
            cout << "Cliente: " << atual->pedido.nomeDoCliente << endl;
            cout << "Quantidade de Pastéis de Pizza: " << atual->pedido.pasteisDePizza << endl;
            cout << "Quantidade de Pastéis de Queijo: " << atual->pedido.pasteisDeQueijo << endl;
            cout << "Quantidade de Pastéis de Frango: " << atual->pedido.pasteisDeFrango << endl;
            cout << "Quantidade de Pastéis de Vento: " << atual->pedido.pasteisDeVento << endl;
            cout << "Quantidade de Coca-Cola: " << atual->pedido.refriCoca << endl;
            cout << "Quantidade de Pepsi: " << atual->pedido.refriPepsi << endl << endl;

            atual = atual->proximo;  
        }
    } else {
        cout << "[ERRO] A lista de pedidos está vazia!\n";
        cout << "Selecione a opção 1 no menu, para cadastrar seu pedido.\n";
    }

    if (atual != nullptr) cout << "Relatório de pedidos criado com sucesso!" << endl;

    pausar();
}

void criarSenha(int senhaAleatoria) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1000, 9999);

    senhaAleatoria = dis(gen);

    cout << "Senha: " << senha << endl;
}

#endif