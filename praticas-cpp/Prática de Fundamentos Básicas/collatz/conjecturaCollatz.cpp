#include <iostream>
#include <locale>

using namespace std;

// Função chamada conjecturaCollatz 
void conjecturaCollatz(int n) {
    while (n != 1) { // <= Enquanto o inteiro n for diferente de 1, a função será executada
        
        cout << n << ' ';
        
        if (n % 2 == 0) { // <= Se o resto de n dividido (/) por 2 for igual a 0, ou seja, é um número inteiro positivo, o cálculo será efetuado da primeira forma
            n = n / 2;
        } else { // <= Se não...
            n = 3 * n + 1;
        }
    }
    cout << 1 << '\n';  // <= Inclui o 1 final na saída
}

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

int main() {

    setlocale (LC_ALL, "Portuguese"); // Possibilita ser mostrado no terminal caractéres especiais, como letras acentuadas (á, à, ê, etc) e Ç

    int n = 0;
    char resposta;

    do {

        cout << "Vamos calcular a sequência de Collatz para um número inteiro positivo maior que 1.\n" <<
                "Digite um número inteiro positivo: ";
        cin >> n;

        if (n <= 1) {
            cout << "\n[ERRO] Insira um número inteiro positivo maior que 1.\n";
        } else {
            conjecturaCollatz(n);
            pausar();
        }

        limpar();

        cout << "Deseja refazer o cálculo da sequência de Collatz? (s/n)\nOpção: ";
        cin >> resposta;

    } while (resposta == 's' || resposta == 'S'); // <= Caso a resposta seja diferente de s ou S, o looping (do while) será encerrado

    limpar();

    cout << "Encerrando...";

    return 0;
}
