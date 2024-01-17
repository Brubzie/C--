#include <iostream>

using namespace std;

int main() {

    int x = 10;
    
    // Referência para o valor de x
    int& ref = x;

    cout << "x = " << x << endl;
    cout << "ref = " << ref << endl;

    // Alterando o valor de ref, o valor de x se é alterado também
    ref = 20;

    cout << "x = " << x << endl;
    cout << "ref = " << ref << endl;

    return 0;
}