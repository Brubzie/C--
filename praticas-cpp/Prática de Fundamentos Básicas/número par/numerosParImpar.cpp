#include <iostream>
#include <conio.h>

using namespace std;

// Facilitadores simples em formas de função
#ifdef _WIN32 // Verifica se está em um sistema Windows
void limpar() {
    system ("cls"); // <= Limpa o terminal (Sistema Windows)
}
#else
void limpar() {
    system ("clear"); // <= Limpa o terminal (Sistema MacOS ou Linux)
}
#endif

void pausar() {
    system ("Pause"); // <= Pausa a execução do código e pede para que seja pressionado qualquer tecla para que o código prossiga sua execução
}

void identificarNum() {
    if (num % 2 == 0) {
        cout << '\n' << num << " e um numero par.\n";
    } else {
        cout << '\n' << num << " e um numero impar.\n";
    }
}

int main() {

    const char esc = 27;
    char key, resposta;

    do {

        int num = 0;

        limpar();

        cout << "\nIdentificador de Numero ===\n" <<
                "Informe um numero: ";
        cin >> num;

        identificarNum();

        pausar();
        limpar();

        cout << "Deseja refazer o sistema? (s/n)\nOpcao: ";
        cin >> resposta;

    } while (resposta == 's' || resposta 'S');

    limpar();

    cout << "Encerrando...";

    return 0;
}