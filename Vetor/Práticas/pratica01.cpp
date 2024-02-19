#include <iostream>
#include <locale>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "portuguese");

    int tam = 5;
    string nomes[tam];

    for(int i = 0; i < tam; i++) {
        bool entradaValida = false;
        while(!entradaValida) {
            cout << "Nome " << i+1 << ": ";
            getline(cin, nomes[i]);
            
            try {
                float num = stof(nomes[i]); // tenta converter para float
                cout << "Entrada inválida, digite um nome, não um número." << endl;
            } catch(const exception& e) { // Entrada é um nome válido
                entradaValida = true;
            }
        }
    }

    for(int i = 0; i < tam; i++) {
        cout << endl << "Nome " << i+1 << ": " << nomes[i];
    }

    return 0;
}