/*
 * Exemplo de fila
 *
 * Com uso de typedef.
 *
 * Criado por: Prof. Me. Orlando Saraiva Jr
 * Criado em : 18/10/2023
 */
#include <iostream>
#include <locale>
#include <conio.h>
#include <cstdlib>

using namespace std;

// Facilitadores simples em formas de função
#ifdef _WIN32 // Verifica se está em um sistema Windows
void limpar() {
    system ("cls");
}
#else
void limpar() {
    system ("clear");
}
#endif

void pausar() {
    cout << "\nPressione Enter para continuar...\n";
    cin.get();
}

typedef int ELEMENTO;

typedef struct NO {
    ELEMENTO valor;
    struct NO* prox;
} *FILA;

FILA novoElemento (ELEMENTO elem) {
    FILA aux = new NO;
    aux->valor = elem;
    aux->prox = nullptr;

    return aux;
}

void enqueue (ELEMENTO elem, FILA no) {
    if (no == nullptr) {
        cout << "Ponteiro nulo!\n";
        exit (-1);
    }

    FILA aux = no;

    while (aux->prox != nullptr) {
        aux = aux->prox;
    }

    FILA aux2 = novoElemento(elem);
    aux->prox = aux2;
}

void mostraFila (FILA no) {
    while (no->prox != nullptr) {
        cout << '[' << no->valor << "] -> ";
        no = no->prox;
    }

    cout << '[' << no->valor << "]\n";
}

FILA dequeue (FILA no, int* valor) {
    FILA proximoFila = no;
    no = proximoFila->prox;
    proximoFila->prox = nullptr;
    *valor = proximoFila->valor;

    delete proximoFila;

    return no;
}

int tamanhoFila (FILA no) {
    FILA filaLocal = no;
    int cont = 0;

    while (filaLocal != nullptr) {
        cont++;
        filaLocal = filaLocal->prox;
    }

    return cont;
}

void destruir (FILA no) {
    cout << "\n\n";
    FILA noProximo = no;

    while (noProximo->prox != nullptr) {
        no = noProximo;
        noProximo = no->prox;
        no->prox = nullptr;

        delete(no);
    }

    no = noProximo;
    no->prox = nullptr;

    delete(no);
}

int buscaFila (ELEMENTO elemento, FILA no) {
    FILA aux = no;
    int cont = 1;

    while (aux != nullptr) {
        if (elemento == aux->valor) {
            return cont;
        }

        aux = aux->prox;
        cont = cont + 1;
    }
    return cont;
}

void posicaoNaFila (ELEMENTO elemento, FILA no) {
    int tamanho = tamanhoFila(no);
    int posicao = buscaFila(elemento, no);

    if (tamanho == posicao - 1) {
        cout << "Não encontrado o elemento " << elemento << " na fila.\n";
    } else {
        cout << "Encontrado o elemento " << elemento << " na posição " << posicao << '\n';
    }
}

int main() {

    setlocale (LC_ALL, "Portuguese");
    
    const char esc = 27;
    char tecla;

    int valor;
    FILA fila = nullptr;
    fila = novoElemento(7);

    enqueue(5, fila);
    enqueue(8, fila);
    enqueue(1, fila);
    enqueue(3, fila);
    enqueue(12, fila);
    enqueue(4, fila);
    enqueue(2, fila);
    enqueue(10, fila);
    enqueue(34, fila);

    mostraFila(fila);

    cout << "Tamanho da fila: " << tamanhoFila(fila) << '\n';

    fila = dequeue(fila, &valor);
    cout << "Saiu da fila: " << valor << '\n';

    pausar();
    limpar();

    mostraFila(fila);
    cout << "Tamanho da fila: " << tamanhoFila(fila) << '\n';

    cout << "___________________________\n";
    posicaoNaFila(5, fila);
    posicaoNaFila(8, fila);
    posicaoNaFila(50, fila);
    posicaoNaFila(34, fila);
    cout << "___________________________\n";

    fila = dequeue(fila, &valor);
    cout << "Saiu da fila: " << tamanhoFila(fila) << '\n';

    pausar();
    limpar();

    cout << "___________________________\n";
    posicaoNaFila(5, fila);
    posicaoNaFila(8, fila);
    posicaoNaFila(50, fila);
    posicaoNaFila(34, fila);
    cout << "___________________________\n";

    mostraFila(fila);
    cout << "Tamanho da fila: " << tamanhoFila(fila) ;

    destruir(fila);


    return 0;
}