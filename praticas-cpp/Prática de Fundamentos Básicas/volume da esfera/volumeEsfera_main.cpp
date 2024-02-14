#include <iostream>
#include <cmath>

using namespace std;

const double pi = 3.14159;

int main() {

    double volume = 0, raio = 0;
    char resposta;

    do {
        system ("cls");

        cout << "Informe o raio da esfera: ";
        cin >> raio;

        volume = (4 / 3) * pi * pow(raio, 3);

        cout << "\nO volume da esfera e " << volume << '\n';

        system ("Pause");

        system ("cls");

        cout << "Deseja reiniciar o programa? (S/N) \nResposta: ";
        cin >> resposta;

    } while (resposta == 's' && resposta == 'S');
    return 0;
}