#include <iostream>

using namespace std;


// Exemplo de Pilha Dinâmica
struct Pilha {
    int topo; // Posição do elemento topo
    int capa;
    float *pElemento;
};

void criarPilha(Pilha *p, int c) {
    p->topo = -1;
    p->capa = c;
    p->pElemento = new float[c];
}

bool estaVazia(Pilha *p) {
    return (p->topo == -1);
}

bool estaCheia(Pilha *p) {
    return (p->topo == p->capa - 1);
}

void empilhar(Pilha *p, float v) {
    p->topo++;
    p->pElemento[p->topo] = v;
}

float desempilhar(Pilha *p) {
    float aux = p->pElemento[p->topo];
    p->topo--;
    return aux;
}

float retornaTopo(Pilha *p) {
    return p->pElemento[p->topo];
}

int main() {

    Pilha duracell;
    int capacidade = 0, menu = 0;
    float valor = 0;

    cout << "Informe a capacidade maxima da pilha\nResposta: ";
    cin >> capacidade;

    criarPilha(&duracell, capacidade);

    while (true) {
        system ("cls");

        cout << "=== Menu Pilha ===" <<
             "\n1 - Empilhar (push)" <<
             "\n2 - Desempilhar (pop)" <<
             "\n3 - Mostrar o topo" <<
             "\n4 - Sair" <<
             "\nOpcao: ";
        cin >> menu;

        switch (menu) {
            case 1: // push
                system("cls");

                if (estaCheia(&duracell)) {
                    cout << "\nPilha cheia!\n";
                } else {
                    cout << "\nInforme o valor: \n";
                    cin >> valor;

                    empilhar(&duracell, valor);
                }

                system ("Pause");

                break;
            case 2: // pop
                system("cls");

                if (estaVazia(&duracell)) {
                    cout << "\nPilha vazia!\n";
                } else {
                    valor = desempilhar(&duracell);
                    cout << "\nDesempilhado!\n" << valor << '\n';
                }

                system ("Pause");

                break;
            case 3: // Mostra o topo
                if (estaVazia(&duracell)) {
                    cout << "\nPilha vazia!\n";
                } else {
                    valor = retornaTopo(&duracell);
                    cout << "\nTopo: " << valor << '\n';
                }

                system ("Pause");

                break;
            case 4: // Encerrando o programa

                cout << "\nSaindo...";
                return 0;
            default: // Caso seja informando um valor inválido
                system("cls");

                cout << "\n[ERRO] Escolha uma opcao valida!\n";

                system("Pause");

                break;
        }
    }

    return 0;
}