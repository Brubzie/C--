#include <iostream>
#include <string>

using namespace std;

int main() {

    string nome;
    int idade;

    cout << "Informe seu nome completo: ";
    getline(cin, nome);

    cout << "Minha idade e: ";
    cin >> idade;

    cout << "\nNome: " << nome;
    cout << "\nIdade: " << idade << " anos";

    return 0;
}