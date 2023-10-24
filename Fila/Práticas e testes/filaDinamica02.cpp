#include <iostream>

using namespace std;

// fila = queue
typedef int tipoItem;
const int tamanho_max = 100;

struct fila {
    int primeiro;
    int ultimo;
    tipoItem* estrutura;

    // protótipo de função
    fila(); // construtor
    ~fila(); // destrutor
    bool taVazio(); //isEmpty
    bool taCheio(); //ifFull
    void inserir(tipoItem item); // push // enqueue
    tipoItem remover(); // pop // dequeue
    void imprimir(); // print
};

fila::fila() { // construtor
    primeiro = 0;
    ultimo = 0;
    estrutura = new tipoItem[tamanho_max];
}

fila::~fila() { // destrutor
    delete [] estrutura;
}

bool fila::taVazio() { // isEmpty
    return (primeiro == ultimo);
}

bool fila::taCheio() { // isFull
    return (ultimo - primeiro == tamanho_max);
}

void fila::inserir(tipoItem item) { // push // enqueue
    if (taCheio()) {
        cout << "\nA fila esta cheia!\n" <<
                "Esse elemento nao pode ser inserido.\n";
    } else {
        estrutura[ultimo % tamanho_max] = item;
        ultimo++;
    }
}

tipoItem fila::remover() { // pop // dequeue
    if (taVazio()) {
        cout << "\nA fila esta vazia!\n" <<
                "Nenhum elemento foi removido.\n";

                return 0;
    } else {
        primeiro++;
        return estrutura[(primeiro - 1) % tamanho_max];
    }
}

void fila::imprimir() { // print
    cout << "\nFila: [ ";
    for (int i = primeiro; i < ultimo; i++) {
        cout << estrutura[i % tamanho_max] << ' ';
    }
    cout << "]\n";
}

void pausar() {
    system ("Pause");
}

void limpar() {
    system ("cls");
}

int main() {
    
    fila fila1;
    int menu = 0;
    tipoItem item;

    cout << "Programa gerador de filas:\n";

    do {
        limpar();

        cout << "       Menu\n" <<
                "1 - Inserir um elemento\n" <<
                "2 - Remover um elemento\n" <<
                "3 - Imprimir fila\n" <<
                "4 - Sair\n";
        cin >> menu;

        switch (menu) {
            case 1:
                cout << "Informe o elemento a ser inserido na fila: ";
                cin >> item;
                fila1.inserir(item);

                pausar();

                break;
            case 2:
                item = fila1.remover();
                cout << "O elemento foi removido: " << item << '\n';

                pausar();

                break;
            case 3:
                fila1.imprimir();

                pausar();

                break;
            case 4:
                cout << "Encerrando...";

                return 0;
            default:
                cout << "[ERRO] Insira uma opcao valida!\n";

                pausar();

                break;
        }
    } while (menu != 4);

    return 0;
}