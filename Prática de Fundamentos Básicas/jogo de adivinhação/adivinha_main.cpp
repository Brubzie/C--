#include <iostream>

using namespace std;

int main() {

    int numeroAleatorio = rand() % 100 + 1;
    int num, dificuldade;
    char resposta;

    do {
        cout << "=== Jogo de Adivinhacao ===\n";
        cout << "| Selecao de Dificuldade |\n";
        cout << "1 - Facil (30 tentativas)\n";
        cout << "2 - Medio (20 tentativas)\n";
        cout << "3 - Dificil (10 tentativas)\n";
        cin >> dificuldade;

        system ("cls");

        switch (dificuldade) {
            case 1:
                for (int i = 1; i < 30; i++) {
                    cout << "\nDigite um numero: ";
                    cin >> num;

                    if (num <= 0 || num >= 101) {
                        cout << "\n[ERRO] Tente um numero entre 1 e 100.\n";
                    } else if (num > numeroAleatorio) {
                        cout << "\nTente um numero menor.\n";
                    } else if (num < numeroAleatorio) {
                        cout << "\nTente um numero maior.\n";
                    } else if (num == numeroAleatorio) {
                        cout << "\nParabens, voce acertou o numero!";
                        break;
                    }
                }
                break;
            case 2:
                for (int i = 1; i < 20; i++) {
                    cout << "\nDigite um numero: ";
                    cin >> num;

                    if (num <= 0 || num >= 101) {
                        cout << "\n[ERRO] Tente um numero entre 1 e 100.\n";
                    } else if (num > numeroAleatorio) {
                        cout << "\nTente um numero menor.\n";
                    } else if (num < numeroAleatorio) {
                        cout << "\nTente um numero maior.\n";
                    } else if (num == numeroAleatorio) {
                        cout << "\nParabens, voce acertou o numero!";
                        break;
                    }
                }
                break;
            case 3:
                for (int i = 1; i < 10; i++) {
                    cout << "\nDigite um numero: ";
                    cin >> num;

                    if (num <= 0 || num >= 101) {
                        cout << "\n[ERRO] Tente um numero entre 1 e 100.\n";
                    } else if (num > numeroAleatorio) {
                        cout << "\nTente um numero menor.\n";
                    } else if (num < numeroAleatorio) {
                        cout << "\nTente um numero maior.\n";
                    } else if (num == numeroAleatorio) {
                        cout << "\nParabens, voce acertou o numero!";
                        break;
                    }
                }
                break;
            default:
                cout << "\n[ERRO] Numero invalido, digite um numero entre 1 e 3\n";
                break;

        }

        cout << "\nReiniciar jogo? (s/n)\n";
        cin >> resposta;
    } while (resposta == 's' || resposta == 'S');


    return 0;
}