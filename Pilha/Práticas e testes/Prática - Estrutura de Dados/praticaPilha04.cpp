#include <iostream>
#include <string>
#define tam_max 10

using namespace std;

// Pilha Dinâmica | Prática 02
struct Pilha {
    int topo = 0;
    int capa = 0;
    float *elementoPilha;
};

void criarPilha (Pilha *minhaPilha, int x) {
    minhaPilha->topo = -1;
    minhaPilha->capa = x;
    minhaPilha->elementoPilha = new float[x];
}

bool taVazio (Pilha *minhaPilha) {
    return (minhaPilha->topo == -1);
}

bool taCheio (Pilha *minhaPilha) {
    return (minhaPilha->topo == minhaPilha->capa - 1);
}

void empilhar (Pilha *minhaPilha, float y) {
    minhaPilha->topo++;
    minhaPilha->elementoPilha[minhaPilha->topo] = y;
}

float desempilhar (Pilha *minhaPilha) {
    float aux = minhaPilha->elementoPilha[minhaPilha->topo];
    minhaPilha->topo--;

    return aux;
}

float retornaTopo (Pilha *minhaPilha) {
    return minhaPilha->elementoPilha[minhaPilha->topo];
}

void mostraPilha (Pilha &minhaPilha) {
    cout << "\nValores da Pilha: ";

    for (int i = 0; i < minhaPilha.topo; i++) {
        cout << minhaPilha.elementoPilha[i] << ' ';
    }
    cout << '\n';
}

int main(int argc, char const *argv[]) {

    Pilha minhaPilha;

    int capacidade = 0;
    int menu = 0;

    float valor = 0;

    cout << "Informe a capacidade maxima da pilha: ";
    cin >> capacidade;

    criarPilha(&minhaPilha, capacidade);

    while (true) {
        system ("cls");

        cout << " _______________________" <<
              "\n|      Menu Pilha       |" <<
              "\n| ===================== |" <<
              "\n| 1 - Empilhar (push)   |" <<
              "\n| 2 - Desempilhar (pop) |" <<
              "\n| 3 - Mostrar o topo    |" <<
              "\n| 4 - Mostrar a pilha   |" <<
              "\n| 5 - Sair              |" <<
              "\n|_______________________|\n";
        cin >> menu;

        switch (menu) {
            case 1: // push
                if (taCheio(&minhaPilha)) cout << "\nPilha cheia!\n";
                else {
                    cout << "\nInforme o valor: ";
                    cin >> valor;

                    empilhar(&minhaPilha, valor);
                }

                system ("Pause");

                break;
            case 2: // pop
                if(taVazio(&minhaPilha)) cout << "\nPilha vazia!\n";
                else {
                    valor = desempilhar(&minhaPilha);
                    cout << "\nValor desempilhado: " << valor << '\n';
                }

                system ("Pause");

                break;
            case 3: // mostra o topo
                if (taVazio(&minhaPilha)) cout << "\nPilha vazia!\n";
                else {
                    valor = retornaTopo(&minhaPilha);
                    cout << "\nValor do topo da pilha: " << valor << '\n';
                }

                system ("Pause");

                break;
            case 4:
                mostraPilha(minhaPilha);

                system ("Pause");

                break;
            case 5: // encerrando
                system ("cls");
                cout << "Encerrando...";
                
                return 0;
            default: // usuário informa opção inválida
                system ("cls");

                cout << "[ERRO] Escolha uma opcao valida!\n";

                break;
        }
    }

    return 0;
}