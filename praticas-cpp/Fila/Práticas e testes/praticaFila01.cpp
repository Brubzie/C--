/*
 * Exemplo de fila criado pelo Chat GPT v5.3
 *
 * Com algumas pequenas mudanças
 */
#include <iostream>
#include <string>

using namespace std;

struct Pessoa {
    string nome;
    int idade;
};

void limpar() {
    system ("cls");
}

void pausar() {
    system ("Pause");
}

int main() {
    Pessoa pessoa1;
    // pessoa1.nome = "João";
    // pessoa1.idade = 30;

    Pessoa pessoa2;
    // pessoa2.nome = "Maria";
    // pessoa2.idade = 25;

    cout << "Informe o nome da primeira pessoa: \nResposta: ";
    cin >> pessoa1.nome;

    cout << "\nInforme a idade da primeira pessoa: \nResposta: ";
    cin >> pessoa1.idade;

    limpar();

    cout << "Informe o nome da segunda pessoa: \nResposta: ";
    cin >> pessoa2.nome;

    cout << "\nInforme a idade da segunda pessoa: \nResposta: ";
    cin >> pessoa2.idade;

    limpar();

    cout << "\nInformacoes cadastradas" <<
            "\nPessoa 01" <<
            "\n* Nome: " << pessoa1.nome <<
            "\n* Idade: " << pessoa1.idade <<
            "\n\nPessoa 02" <<
            "\n* Nome: " << pessoa2.nome <<
            "\n* Idade: " << pessoa2.idade << " anos\n";

    pausar();

    return 0;
}