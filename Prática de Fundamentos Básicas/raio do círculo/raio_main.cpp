#include <iostream>
#include <cmath>

using namespace std;

int main() {

    float raio = 0, perimetro = 0, area = 0, pi = 3.14;

    cout << "Informe o raio do circulo: ";
    cin >> raio;

    perimetro = (2 * pi * raio);

    cout << "\nO perimetro do circulo e = " << perimetro;

    area = pi * pow(raio, 2);

    cout << "\nA area do circulo e = " << area;

    return 0;
}