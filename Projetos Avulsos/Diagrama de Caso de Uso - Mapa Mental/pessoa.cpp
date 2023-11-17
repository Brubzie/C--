#include <iostream>
#include <conio.h>
#include <string>
#include <locale>

using namespace std;

struct PESSOA {
    int idade;
    int id; // RG / CPF
    string nome;
};

struct ATENDENTE {
    
    PESSOA atendente; // Estrutura PESSOA
};

struct TECNICO {
    PESSOA tecnico; // Estrutura PESSOA
};

void limpar() {
    system("cls");
}

void pausar() {
    system("Pause");
}

int main() {

    setlocale (LC_ALL, "Portuguese");

    while (true) {
        
        limpar();

        int x = 0, opcao = 0;

        cout << "Quantas pessoas deseja registrar?\nResposta: ";
        cin >> x;

        for (int i = 0; i < x; i++) {
            cout << "1 - Cliente\n" <<
                    "2 - Atendente\n" <<
                    "3 - Técnico\n" <<
                    "Opção: ";
            cin >> opcao;

            limpar();

            switch (opcao) {
                case 1:

                    break;
                case 2:

                    break;
                case 3:

                    break;
                default:
                    cout << "[ERRO] Insira um número entre 1 e 3\n";
                    pausar();
                    break;
            }
        }
        limpar();
        cout << "Encerrando...\n";
    }

    return 0;
}