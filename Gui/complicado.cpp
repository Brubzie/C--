// Introdução ao C++
#include <iostream> // Biblioteca padrão da linguagem C++ (C plus plus, anteriormente chamada de C com Classes)
#include <locale>
#include <math.h>

using namespace std; // Biblioteca standard(std)

void limpar() { // Funções (void) não necessitam que se tenha um valor retornado (Ex: return 0;)
    // Função que limpa o terminal, quando o sistema for windows (_WIN32)
    system("cls");

    /*
    Para outros sistemas como o Linux, se é utilizado o comando
    system("clear");
    */
}

void pausar() {
    // Função que pausa a execução do programa e pede para que seja pressionada alguma tecla para prosseguir
    system("Pause");
}

int soma(int x, int y) {
    return x + y;
}

int subtrair(int x, int y) {
    return x - y;
}

int multiplicar(int x, int y) {
    return x * y;
}

int divisao(int x, int y) {
    return x / y;
}

int potencializar(int x, int y) {
    return pow(x, y);
}

int main() {

    setlocale (LC_ALL, "Portuguese");

    int idade = 0; // Variável do tipo inteira(int), que receberá a idade do usuário
    string nome; // Variável para palavras(string), que receberá o nome do usuário
    string sobrenome;
    int menu = 0, calculadora = 0, x = 0, y = 0;

    float peso = 70.5;

    /*
     * Entradas e saídas (output, input)
     * o comando (cout <<) imprime algo na tela para o usuário
     *
     * Enquanto o comando (cin >>) pede para que algo seja escrito, e então
     * guarda algo dentro de uma variável
     */
    cout << "Menu:\n";
    cout << "1 - Cadastro basico de usuario\n";
    cout << "2 - Calculadora\n";
    cout << "3 - verificar se e numero impar ou par\n";
    cout << "4 - Sair\n";
    cout << "Opcao: ";
    cin >> menu;

    limpar();

    switch (menu) { // Alavanca/Menu
        case 1: // Opção 1
            cout << "Informe o seu nome: ";
            cin >> nome;

            limpar(); // Chama a função (limpar();), para que o terminal seja limpo

            cout << "Informe o seu sobrenome: ";
            cin >> sobrenome;

            limpar();

            cout << "Informe a sua idade: ";
            cin >> idade;

            limpar();

            cout << "Nome: " << nome << ' ' << sobrenome;
            cout << "\nIdade: " << idade << " anos";

            pausar(); // Chama a função (pausar();), para que a execução do código seja pausada

            break; // Encerra a execução da opção 1

        case 2:

            limpar();

            cout << "Calculadora:" << endl;
            cout << "1 - Soma" << endl;
            cout << "2 - Subtracao" << endl;
            cout << "3 - Multiplicacao" << endl;
            cout << "4 - Divisao" << endl;
            cout << "5 - Potencializacao" << endl;
            cout << "6 - Sair" << endl;
            cout << "Opcao: ";
            cin >> calculadora;

            switch (calculadora) {
                case 1:

                    cout << "Informe o primeiro numero: ";
                    cin >> x;
                    
                    cout << "\nInforme o segundo numero: ";
                    cin >> y;

                    limpar();

                    cout << x << " + " << y << " = " << soma(x, y);

                    pausar();
                    limpar();

                    break;

                case 2:

                    cout << "Informe o primeiro numero: ";
                    cin >> x;
                    
                    cout << "\nInforme o segundo numero: ";
                    cin >> y;

                    limpar();

                    cout << x << " - " << y << " = " << subtrair(x, y);

                    pausar();
                    limpar();

                    break;

                case 3:

                    cout << "Informe o primeiro numero: ";
                    cin >> x;
                    
                    cout << "\nInforme o segundo numero: ";
                    cin >> y;

                    limpar();

                    cout << x << " * " << y << " = " << multiplicar(x, y);

                    pausar();
                    limpar();

                    break;

                case 4:

                    cout << "Informe o primeiro numero: ";
                    cin >> x;
                    
                    cout << "\nInforme o segundo numero: ";
                    cin >> y;

                    limpar();

                    cout << x << " / " << y << " = " << divisao(x, y);

                    pausar();
                    limpar();

                    break;

                case 5:

                    cout << "Informe o primeiro numero: ";
                    cin >> x;
                    
                    cout << "\nInforme o segundo numero: ";
                    cin >> y;

                    limpar();

                    cout << x << " ^ " << y << " = " << soma(x, y);

                    pausar();
                    limpar();

                    break;

                case 6:
                    break;
            }

            break;

        case 4:
            break;
    }

    limpar();
    
    cout << "\nEncerrando...\n";

    return 0; /* Retorna o valor zero para a função principal (int main()), encerrando
    o programa quando o mesmo chega ao fim */
}