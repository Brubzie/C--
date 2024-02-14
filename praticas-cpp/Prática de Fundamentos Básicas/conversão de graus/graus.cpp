#include <iostream>
#include <conio.h>

using namespace std;

int main() {

    float temperatura = 0, conversaoFparaC = 0, conversaoCparaF = 0;
    int menu = 0;
    const char ESC = 27;

    do {
        system ("cls");

        cout << "=== Conversao de Temperatura ===\n" <<
                "1 - De Celsius para Fahrenheint\n" <<
                "2 - De Fahrenheint para Celsius\n" <<
                "3 - Sair\n";
        cin >> menu;

        switch (menu) {
            case 1:
                cout << "\nInforme a temperatura: ";
                cin >> temperatura;

                conversaoCparaF = (temperatura * 9/5) + 32;

                cout << "\nCelsius: " << temperatura << "C\n";
                cout << "Fahrenheint: " << conversaoCparaF << "F\n";
                break;
            case 2:
                cout << "\nInforme a temperatura: ";
                cin >> temperatura;

                conversaoFparaC = (temperatura - 32) * 5/9;

                cout << "\nFahrenheint: " << temperatura << "F\n";
                cout << "Celsius: " << conversaoFparaC << "C\n";
                break;
            case 3:
                cout << "\nEncerrando...";
                break;
            default:
                cout << "\n[ERRO] Digite um valor entre 1 e 3.";
                break;
        }
        cout << "\nPressione ESC para encerrar o programa...";
    } while (getch() != ESC || menu != 3);

    return 0;
}