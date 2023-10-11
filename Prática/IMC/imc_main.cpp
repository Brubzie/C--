#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {

    float altura = 0, imc = 0, peso = 0;
    char resposta;
    
    do {

        system("cls");

        cout << "Calculo do IMC\n\n";

        cout << "Informe o seu peso (Kg): ";
        cin >> peso;

        cout << "\nInforme seu tamanho: ";
        cin >> altura;

        imc = peso / (altura * altura);

        system ("cls");

        if (imc < 18.5) {

            cout << "Voce esta abaixo do peso." <<
                    "\nSeu IMC e: " << imc << '\n';

        } else if (imc >= 18.5 && imc <= 24.9) {

            cout << "Voce esta no intervalo normal." <<
                    "\nSeu IMC e: " << (int)imc << '\n';

        } else if (imc >= 25 && imc <= 29.9) {

            cout << "Voce esta sobrepeso." <<
                    "\nSeu IMC e: " << (int)imc << '\n';

        } else if (imc >= 30 && imc <= 39.9) {

            cout << "Voce esta com obesidade classe I." <<
                    "\nSeu IMC e: " << (int)imc << '\n';

        } else if (imc >= 35 && imc <= 39.9) {

            cout << "Voce esta com obesidade classe II." <<
                    "\nSeu IMC e: " << (int)imc << '\n';

        } else {

            cout << "Voce esta com obesidade classe III." <<
                    "\nSeu IMC e: " << (int)imc << '\n';

        }

        system ("Pause");

        cout << "\nDeseja encerrar o programa? (S/N)\nResposta: ";
        cin >> resposta;

    } while (resposta == 'n' || resposta == 'N');

    return 0;
}
