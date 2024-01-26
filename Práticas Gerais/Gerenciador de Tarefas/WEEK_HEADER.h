#ifndef WEEK_HEADER
#define WEEK_HEADER

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>

//Estruturas
struct Node {
    Tarefa tarefa;
    Node* proximo;
    Node* anterior;
};

struct Tarefa {
    std::string descricao;
    std::string horario;
};

struct ListaDeTarefas {
    Node* primeiro;
    Node* ultimo;
    int tamanho;
};

// Funções
void limpar() {
    #ifdef _WIN32 // Identifica se o SO é Windows
        system("cls");
    #else
        system("clear"); // Caso for um SO Linux, MacOS ou demais
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

int geradorDeSenhas(int senha) {
    senha = 0;

    // Definindo a seed(semente) para a função rand()
    srand(time(NULL));

    // Gera a senha aleatória
    for (int i = 0; i < 8; i++) {
        int digito = rand() % 10;
        senha += digito;
    }

    // Imprime a senha gerada
    std::cout << "Senha gerada: " << senha << std::endl;

    return senha;
}

int senhaCriada(int senha) {
    senha = 0;

    // Definindo a senha
    std::cout << "Informe a senha: ";
    std::cin >> senha;

    return senha;
}

bool verificarFormatoHorario(string horario) {
    regex padrao("[0-9]{2}:[0-9]{2}");
    return regex_match(horario, padrao);
}

void adicionarTarefa(ListaDeTarefas* lista, Tarefa* tarefa) {
    Node* novo = new Node{ *tarefa, nullptr, nullptr };

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

    std::cout << "Informe a descrição da tarefa: ";
    std::getline(cin, lista->ultimo->tarefa.descricao);

    std::cout << "Informe o horário da tarefa (no formato HH:MM): ";
    std::getline(cin, lista->ultimo->tarefa.horario);

    if (verificarFormatoHorario(lista->ultimo->tarefa.horario)) {
        limpar();
        std::cout << "Tarefa adicionada com sucesso!" << std::endl;   
    } else {
        std::cout << std::endl << "O horário não está no formato correto." << std::endl;
    }
    pausar();
}

void listarTarefa(ListaDeTarefas* lista) {
    if (lista->tamanho = 0) {
        std::cout << "Nenhuma tarefa encontrada." << std::endl;
    } else {
        std::cout << "Lista de tarefas: " << std::endl;
        for (Node* aux = lista->primeiro; aux != nullptr; aux = aux->proximo) {
            std::cout << "- " << aux->tarefa.descricao << " (" << aux->tarefa.horario << ") " << std::endl;
        }
    }
    pausar();
}

#endif