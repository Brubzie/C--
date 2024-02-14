#include <iostream>
#include <locale>

using namespace std;

void clean() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause() {
#ifdef _WIN32
    system("pause");
#else
    cout << "Pressione Enter para continuar..." << endl;
    cin.ignore(); // Limpa o buffer de entrada
#endif
}

struct tipoCelula {
    int item; // Armazena o valor
    tipoCelula *prox;
};

int pilha_contador;
tipoCelula *topo;

bool pilha_vazia() {
    if (topo == nullptr) {
        return true;
    } else {
        return false;
    }
}

bool pilha_construtor() {
    topo = nullptr;
    pilha_contador = 0;
}

bool pilha_destrutor() {
    int aux;
    tipoCelula *temp;
    if (pilha_vazia()) {
        return false;
    } else {
        while (topo != nullptr) {
            topo = topo->prox;
            temp->prox = nullptr;

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

    if (novaCelula == nullptr) { // Caso o SO não forneça memória RAM
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

        temp->prox = nullptr; // Medida de segurança para desligar a célula removida da pilha

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

int main() {

    setlocale(LC_ALL, "Portuguese");

    int menu = 0;

    do {

    } while (menu != 4);

    return 0;
}