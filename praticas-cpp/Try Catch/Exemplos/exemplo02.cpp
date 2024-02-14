#include <iostream>
#include <locale>

using namespace std;

// Protótipo de Função
double divide(double ,double);

int main() {
    setlocale(LC_ALL, "Portuguese");

    double n1, n2;

    cout << "Primeiro valor: ";
    cin >> n1;

    cout << "Segundo valor: ";
    cin >> n2;

    try {
        cout << divide(n1, n2);
    } catch(const char* msg) {
        cout << "ERRO: " << msg << endl;
    }

    return 0;
}

// Função
double divide(double n1, double n2) {
    if(n2 <= 0) {
        throw "Erro de divisão por ZERO.";
    }
    
    if(n1 >= 10) {
        throw "O primeiro valor deve ser menor que 10.";
    }

    return n1 / n2;
}