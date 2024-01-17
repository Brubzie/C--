#include <iostream>
#include <locale>
#include <string>
#include "POINTER_HEADER.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    string nomes;

    // Criando um ponteiro para um ponteiro de string
    string** vetor;

    // Alocando memória para um vetor de 3 ponteiros
    vetor = new string*[3];

    // Looping para a inscrição dos valores no vetor
    for(int i = 0; i < 3; i++) {
        vetor[i] = new string;
    }

    // Preenchendo o vetor
    int numeroDeNomes = 1;
    for(int i = 0; i < 3; i++) {
        cout << "Informe o nome 0" << numeroDeNomes << " :" << endl;
        getline(cin, nomes);
        *vetor[i] = nomes;
        numeroDeNomes++;
        clean();
    }

    // Imprimir o vetor na tela
    for(int i = 0; i < 3; i++) {
        cout << "Nome 0" << i + 1 << ": " << *vetor[i] << endl;
    }

    // Liberar a memória alocada

    for(int i = 0; i < 3; i++) {
        delete[] vetor[i];
    }
    delete[] vetor;

    return 0;
}