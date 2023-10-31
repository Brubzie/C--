#include <iostream>

using namespace std;

void limpar() {
    system ("cls");
}

void pausar() {
    system ("Pause");
}

void sair() {
    limpar();
    cout << "Saindo...\n";
}

int soma(int x, int y) {
    return x + y;
}

int subtrair(int x, int y) {
    return x - y;
}

int multiplicar(int x, int y) {
    return x * y;
}

int main() {
    
    int menu, x, y;

    do {

        limpar();

        cout << "__________________\n" <<
                "|===== Menu =====|\n" <<
                "| 1 - Soma       |\n" <<
                "| 2 - Subtrair   |\n" <<
                "| 3 - Multiplicar|\n" <<
                "| 4 - Sair       |\n"
                "|________________|\n" <<
                "Opcao: ";
        cin >> menu;

        limpar();

        switch (menu) {
            case 1:

                cout << "Primeiro numero: ";
                cin >> x;

                cout << "\nSegundo numero: ";
                cin >> y;

                cout << "Resultado: " << soma(x, y) << '\n';

                pausar();

                break;

            case 2:
    
                cout << "Primeiro numero: ";
                cin >> x;

                cout << "\nSegundo numero: ";
                cin >> y;

                cout << "Resultado: " << subtrair(x, y) << '\n';

                pausar();

                break;

            case 3:


                cout << "Primeiro numero: ";
                cin >> x;

                cout << "\nSegundo numero: ";
                cin >> y;

                cout << "Resultado: " << multiplicar(x, y) << '\n';

                pausar();

                break;

            case 4:

                sair();

                return 0;

            default:

                cout << "[ERRO] Informe uma opcao valida!";

                pausar();

                break;
        }

    } while (menu != 4);

    return 0;
}