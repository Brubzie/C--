#include <iostream>
#include <vector>
#include <locale>
#include <stdexcept>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    vector<int>num(5); // Índice de num: [0], [1], [2], [3], [4]

    try {
        num.at(4) = 10; // Está na posição: num[4]
        cout << num[0] << endl;
    } catch(exception& e) {
        cout << "ERRO: " << e.what() << endl;
    }

    return 0;
}