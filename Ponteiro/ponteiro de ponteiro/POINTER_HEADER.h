#ifndef POINTER_HEADER
#define POINTER_HEADER

#include <iostream>
#include <string>

using namespace std;

// Funções
void clean() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pause() {
    #ifdef _WIN32
        system("pause");
    #else
        cout << "Pressione a tecla ENTER para continuar..." << endl;
        cin.ignore();
    #endif
}

#endif