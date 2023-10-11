#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

// Declarando a função
int somar(int a, int b) {
    return a + b;
}

int subtrair(int a, int b) {
    return a - b;
}

int multiplicar(int a, int b) {
    return a * b;
}

int dividir(int a = 0, int b = 1) {
    if (b != 0) {
        return a / b;
    } else {
        cout << "\n[ERRO] Divisao por zero!\n";
        return 0;
    }
}

int potencia(int a, int b) {
    return pow(a, b);
}

int main() {

    int resultado = 0, x = 0, y = 0, menu = 0;
    const char ESC = 27;

    do {
        system("cls");

        cout << "Primeiro numero: ";
        cin >> x;

        cout << "Segundo numero: ";
        cin >> y;

        cout << "\n=== Calculadora ===" <<
                "\n1 - Somar" <<
                "\n2 - Subtrair" <<
                "\n3 - Multiplicar" <<
                "\n4 - Dividir" <<
                "\n5 - Potencializar" <<
                "\n6 - Sair\n";
        cin >> menu;

        switch (menu) {
            case 1:
                resultado = somar(x, y);
                cout << "\nO resultado da soma de " << x << " + " << y << " e igual a " << resultado << '\n';
                break;
            case 2:
                resultado = subtrair(x, y);
                cout << "\nO resultado da subtracao de " << x << " - " << y << " e igual a " << resultado << '\n';
                break;
            case 3:
                resultado = multiplicar(x, y);
                cout << "\nO resultado da multiplicacao de " << x << " * " << y << " e igual a " << resultado << '\n';
                break;
            case 4:
                resultado = dividir(x, y);
                cout << "\nO resultado da divisao de " << x << " / " << y << " e igual a " << resultado << '\n';
                break;
            case 5:
                resultado = potencia(x, y);
                cout << "\nO resultado da potencializacao de " << x << " ^ " << y << " e igual a " << resultado << '\n';
                break;
            case 6:
                cout << "\nEncerrando...";
                break;
            default:
                cout << "\n[ERRO] Escolha uma opcao valida!\n";
                break;
        }
        cout << "\nPressione a tecla ESC para encerrar o programa ou aperte qualquer outra para continuar...\n";
    } while (getch() != ESC || menu != 6);

    return 0;
}