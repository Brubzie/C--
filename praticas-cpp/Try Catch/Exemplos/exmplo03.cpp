#include <iostream>
#include <locale>

using namespace std;

// Protótipo de função
float dividir(float, float);

int main() {
    setlocale(LC_ALL, "Portuguese");

    float x = 0, y = 0;

    cout << "Divisão" << endl
         << "Informe o numerador: ";
    cin >> x;

    cout << "Informe o denominador: ";
    cin >> y;

    try {
        float z = dividir(x, y);
        cout << z << endl;
    } catch(const char* e) {
        cerr << "ERRO: " << e << endl;
    }

    return 0;
}

// Função
float dividir(float x, float y) {
    if(y == 0) {
        throw "Divisão por zero.";
    }
    return (x/y);
}