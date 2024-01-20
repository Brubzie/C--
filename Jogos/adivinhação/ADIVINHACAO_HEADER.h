#ifndef ADIVINHACAO_HEADER
#define ADIVINHACAO_HEADER

#include <iostream>
#include <random>

using namespace std;

// Funções
void limpar() {
    #ifdef _WIN32 // <= Identifica se o SO é Windows
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar() {
    #ifdef _WIN32
        system("pause");
    #else
        cout << "Pressione ENTER para continuar..." << endl;
        cin.ignore();
    #endif
}

void randomPassword(int senha) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(10, 99);

    senha = dis(gen);

    cout << "Senha: " << senha << endl;
}

#endif