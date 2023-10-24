#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    // Definindo as variaveis
    int menu, x, y, resultado;
    menu = 0;
    x = 0;
    y = 0;
    resultado = 0;

    // Fazendo um codigo em looping
    do {

        // Pedindo dois numeros (inteiros) para o usuário
        cout << "Informe dois valores\nValor 1: ";
        cin >> x;

        cout << "Valor 2: ";
        cin >> y;

        // Menu da calculadora
        cout << "\n1 - Adicao\n" <<
                "2 - Subtracao\n" <<
                "3 - Multiplicacao\n" <<
                "4 - Divisao\n" <<
                "5 - Sair\n";
        cin >> menu;

        // Codando a calculadora
        switch (menu) {

        case 1:

            resultado = x + y;
            cout << "\nResultado: " << resultado << '\n';

            break;

        case 2:

            resultado = x - y;
            cout << "\nResultado: " << resultado << '\n';

            break;

        case 3:

            resultado = x * y;
            cout << "\nResultado: " << resultado << '\n';

            break;

        case 4:

            resultado = x / y;
            cout << "\nResultado: " << resultado << '\n';

            break;

        case 5:

            cout << "\nSaindo...";

            break;
        
        default:

            cout << "\n[ERRO] Escolha um numero valido, entre 1 e 5!\n";

            break;
        }
    // Enquanto a resposta nao for 5 (sair), o codigo ira rodar em looping 
    } while (menu != 5);

    // Fim do codigo
    return 0;
}
