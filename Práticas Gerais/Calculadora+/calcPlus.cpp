#include <iostream>
#include <string>
#include <sstream> // Para utilizar stringstream
#include <locale>

using namespace std;

int main() {

    setlocale (LC_ALL, "Portuguese");

    do {
        
        // Solicitação da expressão matemática
        cout << ": ";
        string expressao;
        getline(cin, expressao);

        // Avaliação da expressão usando stringstream
        stringstream ss(expressao);
        double resultado = 0.0;
        char operador = '+';
        double numero;

        // Loop para avaliar a expressão
        while (ss >> numero) {

            // Realiza a operação correspondente
            if (operador == '+') {

                resultado += numero;

            } else if (operador == '-') {

                resultado -= numero;

            } else if (operador == '*') {

                resultado *= numero;

            } else if (operador == '/') {

                // Evita divisão por zero
                if (numero != 0) {

                    resultado /= numero;

                } else {

                    cout << "[Erro] Divisão por zero!\n";

                    return 1;  // Saída com erro

                }
            }

            // Lê o próximo operador (se houver)
            ss >> operador;
        
        }

        // Imprime o resultado
        cout << "= " << resultado << "\n\n";
    
    } while (true);

    return 0;
}