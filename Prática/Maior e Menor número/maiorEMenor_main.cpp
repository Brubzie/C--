#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

    int maior = 0, menor = 0, aux = 0, i = 0;

    do {
       cout << "\nDigite um numero: ";
       cin >> aux;

       if (i == 0)
       {
        maior = aux;
        menor = aux;
        i++;
       } else if (aux == -1) {
        break;
       } else if (aux > maior) {
        maior = aux;
       } else if (aux < menor) {
        menor = aux;
       }
    } while (true);

    cout << "\nMaior numero: " << maior << '\n';
    cout << "\nMenor numero: " << menor << '\n';
    

    return 0;
}