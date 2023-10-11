#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

    int soma = 0, valor = 0;

    do {
        system ("cls");

        cout << "Informe um numero diferente de 0 \nResposta: ";
        cin >> valor;

        system("cls");

        if (valor % 2 == 0) {
            soma += valor; // soma = soma + valor;
        }
        
    } while (valor != 0);
    
    cout << "\nA soma dos numeros pares e: " << soma;

    return 0;
}
