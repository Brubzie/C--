#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char const *argv[]) {

    float velMedia = 0, s = 0, t = 0;
    int menu = 0;

    do {

        cout << "\n=== Menu ===" <<
                "\n1 - Calculo da Velocidade Media" <<
                "\n2 - Tempo" <<
                "\n3 - Sair\n";
        cin >> menu;

        system("cls");

        switch (menu) {
            case 1:
                cout << "Digite o espaco: ";
                cin >> s;

                cout << "Digite o tempo: ";
                cin >> t;

                cout << "\nA velocidade media e: " << (s / t);
                break;
            case 2:
                cout << "\nDigite a velocidade media: ";
                cin >> velMedia;

                cout << "Digite o tempo: ";
                cin >> t;

                cout << "\nO espaco e: " << (velMedia * t);
                break;
            case 3:
                cout << "\nEncerrando...";
                break;
            default:
                cout << "\n[ERRO] Digite um numero valido!\n";
                break;
        }

    } while (menu != 3);

    return 0;
}
