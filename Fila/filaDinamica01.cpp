/*
Aula 07 Estrutura de Dados - Implementação Fila Dinâmica (com Lista Encadeada)
Link: https://www.youtube.com/watch?v=q25A0b3yHKA

First in, First out (FIFO)
*/
#include <iostream>
#include <cstddef>
#include <new>

using namespace std;

// Fila Dinâmica = Dynamic Queue
typedef int tipoItem;

class no {
    public:
    tipoItem valor;
    no* proximo;
};

class filaDinamica {
    private:
    no* primeiro; // front
    no* ultimo; // rear

    public:
    filaDinamica(); // Constructor
    ~filaDinamica(); // Destructor
    bool estaVazio(); // is empty
    bool estaCheio(); // is full
    void inserir(tipoItem item); // enqueue // push
    tipoItem remover(); // dequeue // pop
    void imprimir(); // print
};

filaDinamica::filaDinamica() { // Constructor
    primeiro = NULL;
    ultimo = NULL;
}

filaDinamica::~filaDinamica() { // Destructor
    no* temp;
    while (primeiro != NULL) {
        temp = primeiro;
        primeiro = primeiro->proximo;

        delete temp;
    }
    ultimo = NULL;
}

bool filaDinamica::estaVazio() { // is empty
    return (primeiro == NULL);
}

bool filaDinamica::estaCheio() { // is full
    no* temp;
    try {
        temp = new no; // Procura um espaço na memória (RAM)
        delete temp;

        return false;
    } catch (bad_alloc exception) {
        return true;
    }
}

void filaDinamica::inserir(tipoItem item) { // enqueue // push
    if (estaCheio()) {
        cout << "\nA fila esta cheia\n" <<
                "Nao foi possivel inserir este elemento!\n";
    } else {
        no* noNovo = new no;
        noNovo->valor = item;
        noNovo->proximo = NULL;

        if (primeiro == NULL) {
            primeiro = noNovo;
        } else {
            ultimo->proximo = noNovo;
        }

        ultimo = noNovo; 
    }
}

tipoItem filaDinamica::remover() { // dequeue // pop
    if (estaVazio()) {
        cout << "\nA fila esta vazia!\n" <<
                "Nao tem elemento a ser removido!\n";

        return 0;
    } else {
        no* temp = primeiro;
        tipoItem item = primeiro->valor;
        primeiro = primeiro->proximo;

        if (primeiro == NULL) {
            ultimo = NULL;
        }

        delete temp;

        return item;
    }
}

void filaDinamica::imprimir() { // print
    no* temp = primeiro;
    cout << "\nFila = [ ";
    while (temp != NULL) {
        cout << temp->valor << ' ';
        temp = temp->proximo;
    }
    cout << " ]\n";
}

int main() {
    
    filaDinamica fila1;
    int menu;
    tipoItem item;

    cout << "Programa gerador de filas: \n";
    
    while (menu != 4) {
        cout << "1 - Inserir um elemento\n" <<
                "2 - Remover um elemento\n" <<
                "3 - Imprimir a fila\n" <<
                "4 - Sair\n";
        cin >> menu;

        system ("cls");

        switch (menu) {
            case 1:
                cout << "\nInforme o elemento a ser inserido na fila: ";
                cin >> item;

                fila1.inserir(item);
                break;
            case 2:
                item = fila1.remover();
                cout << "Elemento removido: " << item << '\n';
                break;
            case 3:
                fila1.imprimir();
                break;
            case 4:
                cout << "\nEncerrando...";
                break;
            default:
                cout << "\n[ERRO] Insira uma opcao valida!\n";
                break;
        }
    }

    return 0;
}