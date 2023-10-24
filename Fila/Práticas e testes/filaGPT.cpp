// Exemplo de fila criado pelo Chat GPT v5.3
#include <iostream>
#include <string>

using namespace std;

struct Pessoa {
    string nome;
    int idade;
};

int main() {
    Pessoa pessoa1;
    pessoa1.nome = "João";
    pessoa1.idade = 30;

    Pessoa pessoa2;
    pessoa2.nome = "Maria";
    pessoa2.idade = 25;

    cout << "Pessoa 1: " << pessoa1.nome << ", " << pessoa1.idade << " anos\n";
    cout << "Pessoa 2: " << pessoa2.nome << ", " << pessoa2.idade << " anos\n";

    return 0;
}