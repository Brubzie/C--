#include <iostream>
#include <locale>
#include <string>
#define tamanho_maximo 10

using namespace std;

struct Pilha {
    int topo = 0;
    int elemento [tamanho_maximo];
};

bool estaVazia (Pilha &duracell) {
    if (duracell.topo == 0) {
        return true;
    } else {
        return false;
    }
}

bool estaCheia (Pilha &duracell) {
    int tamanhoMaximo = (int)duracell.elemento;

    if (duracell.topo > tamanhoMaximo) {
        return true; 
    } else {
        return false;
    }
}

void empilha (Pilha &duracell, int elementoEmpilhado) {
    if (!estaCheia(duracell)) {
        duracell.elemento[duracell.topo++] = elementoEmpilhado;
    } else {
        cout << "\nA pilha está cheia.\n";
    }
}

int desempilha (Pilha &duracell) {
    return (duracell.elemento[--duracell.topo]);
}

void mostraPilha (Pilha &duracell) {
    cout << "\nValores da Pilha: ";

    for (int i = 0; i < duracell.topo; i++) {
        cout << duracell.elemento[i] << ' ';
    }
    cout << '\n';
}

int main(int argc, char const *argv[]) {
    
    setlocale (LC_ALL, "Portuguese");

    Pilha duracell;
    string nomePilha;
    int menu = 0, valor = 0;

    duracell.topo = 0;

    cout << "Defina o nome da pilha: ";
    cin >> nomePilha;

    system ("Pause");

    while (true) {
        system ("cls");

        cout << "________________________________________\n" <<
                "| ============ Menu Pilha ============ |\n" <<
                "| 1 - Adicionar valor á pilha          |\n" <<
                "| 2 - Retirar valor da pilha           |\n" <<
                "| 3 - Mostrar valores da pilha         |\n" <<
                "| 4 - Alterar o nome da pilha          |\n"
                "| 5 - Sair                             |\n" <<
                "|______________________________________|\n" <<
                "Opcao: ";
        cin >> menu;

        switch (menu) {
            case 1:
                cout << "\nDigite um valor: ";
                cin >> valor;

                empilha(duracell, valor);

                break;
            case 2:
                valor = desempilha(duracell);
                if (valor != -1) {
                    cout << "\nValor desempilhado: " << valor << '\n';
                }

                system ("Pause");

                break;
            case 3:
                mostraPilha(duracell);

                system ("Pause");

                break;
            case 4:
                cout << "\nNome atual da pilha: " << nomePilha <<
                        "\nInforme o novo nome da pilha: ";
                cin >> nomePilha;

                system ("cls");

                cout << "\n\nNome atual da pilha: " << nomePilha << '\n';

                system ("Pause");

                break;
            case 5:
                system ("cls");
                cout << "Encerrando...";

                return 0;
            default:
                cout << "[ERRO] Opção inválida. Tente novamente.\n";
                system ("Pause");

                break;
        }
    }

    return 0;
}