#include <iostream>

using namespace std;

int main() {

    double num = 0, porcentagemValor = 0, porcentagemConta = 0, porcentagemValor2 = 0;
    char resposta;

    do {
        system ("cls");

        cout << "Informe um numero \nResposta: ";
        cin >> num;

        cout << "\nInforme a fracao \nResposta: ";
        cin >> porcentagemValor;

        porcentagemValor2 = porcentagemValor;

        // Cálculo da porcentagem
        porcentagemConta = (num * porcentagemValor) / 100;

        system ("cls");

        cout << '\n' << porcentagemValor2 << "% de " << num << " = " << (float)porcentagemConta << '\n';

        cout << "\nDeseja continuar?(S/N) \nResposta: ";
        cin >> resposta;

    } while (resposta == 's' && resposta == 'S');

    return 0;
}