#include <iostream>

using namespace std;

int main() {
    int vetor[5] = {10, 20, 30, 40, 50};

    // Dividi-se o tamanho de vetor por 4, pois cada valor dentro de uma
    // vari�vel do tipo int, ocupa o espa�o de 4 bytes
    for(int i = 0; i < sizeof(vetor) / 4; i++) {
        cout << "Vetor " << i+1 << ": " << vetor[i] << endl;
    }

    return 0;
}