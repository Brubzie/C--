/*
** Prática de fila dinâmica com base em vídeo aula
** Link: https://www.youtube.com/watch?v=uQjeh1-KXrc
*/

#include <iostream>
#include <string>
#include <locale>
#include <cstdlib>
#include <conio.h>

using namespace std;

struct NO {
    int dado;
    struct NO *prox;
};

struct FILA {
    NO *inicio;
    NO *fim;
};

void enfileirar(int dado, FILA *f) {
    NO *ptr = new NO;

    if (ptr == nullptr) {
        cout << "\nErro de alocação!\n";
        return;
    } else {
        ptr->dado = dado;
        ptr->prox = nullptr;

        if (f->inicio == nullptr) {
            f->inicio = ptr;
        } else {
            f->fim->prox = ptr;
        }

        f->fim = ptr;
    }

    return;
}

int desenfileirar(FILA *f) {
    NO *ptr = f->inicio;
    int dado;

    if (ptr != nullptr) {
        f->inicio = ptr->prox;
        ptr->prox = nullptr;
        dado = ptr->dado;

        delete ptr;

        if (f->inicio == nullptr) {
            f->fim = nullptr;
        }
    } else {
        cout << "\nFila vazia.\n";
        return -1; // Retorna um valor padrão (por exemplo, -1) quando a fila está vazia.
    }

    return dado;
}

void imprimeFila(FILA *f) {
    NO *ptr = f->inicio;

    if (ptr != nullptr) {
        while (ptr != nullptr) {
            cout << '\n' << ptr->dado;
            ptr = ptr->prox;
        }
    } else {
        cout << "\nFila vazia.\n";
        return;
    }
}

void inicializaFila(FILA *f) {
    f->inicio = nullptr;
    f->fim = nullptr;
}

void limpar() {
    system("cls");
}

void pausar() {
    system("Pause");
}

int main() {

    setlocale(LC_ALL, "Portuguese");

    const char esc = 27;
    char tecla;

    FILA *f1 = new FILA;

    do {
        limpar();

        if (f1 == nullptr) {
            cout << "Erro de alocação!\n";
            exit(-1);
        } else {
            inicializaFila(f1);

            enfileirar(10, f1);
            enfileirar(20, f1);
            enfileirar(30, f1);

            imprimeFila(f1);
        }

        cout << '\n';

        // Fim do loop
        pausar();
        limpar();

        cout << "Pressione ESC para encerrar o programa...\n";
        tecla = _getch(); // Lê a tecla pressionada sem a necessidade de pressionar ENTER

        if (tecla == esc) {
            break;
        }

    } while (true);

    limpar();

    cout << "\nEncerrando...";

    return 0;
}