#include <iostream> // Adiciona a biblioteca do C++, a iostream

using namespace std;

int main() {

    string nome, sobrenome;
    int idade;

    cout << "Informe o seu nome: ";
    cin >> nome;

    cout << "\nInforme o seu sobrenome: ";
    cin >> sobrenome;

    cout << "\nInforme a sua idade: ";
    cin >> idade;

    cout << "\nNome: " << nome << ' ' << sobrenome;
    cout << "\nIdade: " << idade << " anos\n";

    return 0;
}