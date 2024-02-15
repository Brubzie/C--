// Validação de Dados Avançada
#include <iostream>
#include <limits>
#include <climits>
#include <locale>
#include <locale.h>

using namespace std;

// Diretiva de Compilação para o Linux
#ifdef __linux__
    const int INT_MAX = numeric_limits<int32_t>::max();
    const int INT_MIN = numeric_limits<int32_t>::min();
#endif

void read_input_int_val(int& var, string str) {
    bool valid = false;
    while(!valid) {
        cout << str;
        cin >> var;
        if(cin.fail()) {
            cout << "Entrada inválida!" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        } else {
            valid = true;
        }
    }
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int idade = 0;

    do {
        read_input_int_val(idade, "\nInforme a sua idade: ");
    } while(idade <= 0 || idade >= 120);

    cout << endl << "Validado com sucesso!" << endl
         << "Você tem " << idade << " anos" << endl;

    return 0;
}