#include <iostream>

using namespace std;

int main() {
    
    int num = 0, maior = 0, intermediario = 0, menor = 0, vezes = 0;
    char resposta;

    do {
        system ("cls");

        cout << "Informe a quantidade de numeros que deseja que sejam ordenados: \nResposta: ";
        cin >> vezes;

        cout << "\nDigite um numero: \nResposta: ";
        cin >> num;

        maior = intermediario = menor = num;

        for (int i = 1; i < vezes; i++) {
            cout << "Digite outro numero: ";
            cin >> num;

            if (num > maior) {
                intermediario = maior;
                maior = num;
            } else if (num < menor) {
                intermediario = menor;
                menor = num;
            } else {
                if (num > intermediario && num < maior) {
                    intermediario = num;
                }
            }
        }

        cout << "\nMaior: " << maior;
        cout << "\nIntermediario: " << intermediario;
        cout << "\nMenor: " << menor << '\n';

        system ("Pause");

        cout << "\nDeseja repetir o programa? (S/N) \nResposta: ";
        cin >> resposta;

    } while (resposta == 's' || resposta == 'S');

    return 0;
}