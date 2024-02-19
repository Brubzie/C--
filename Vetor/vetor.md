# Vetor

Vetores (também conhecidos como arrays) em C++ são estruturas de dados que permitem armazenar elementos do mesmo tipo de forma sequencial. Eles são ideais para representar listas ou sequências simples de dados. Vamos entender melhor com alguns exemplos:

1. Declaração e Uso Básico:
   * Um vetor é um bloco de memória reservado para guardar vários elementos do mesmo tipo.
   * Por exemplo, podemos declarar um vetor de inteiros com 5 elementos da seguinte forma:

~~~cpp
#include <iostream>

using namespace std;

int main() {
    int meuVetor[5]; // Declaração de um vetor de inteiros com 5 elementos

    // Inicializando os elementos do vetor
    meuVetor[0] = 10;
    meuVetor[1] = 20;
    meuVetor[2] = 30;
    meuVetor[3] = 40;
    meuVetor[4] = 50;

    // Acessando e imprimindo os elementos
    cout << "Elemento 3: " << meuVetor[2] << endl; // Saída: 30

    return 0;
}
~~~

2. Interação com Vetores:
   * Podemos usar loops para percorrer os elementos de um vetor:

~~~cpp
// Imprimindo todos os elementos do vetor
for (int i = 0; i < 5; ++i) {
    cout << "Elemento " << i << ": " << meuVetor[i] << endl;
}
~~~

3. Tamanho do Vetor:
   * O tamanho do vetor é fixo durante a execução e deve ser especificado na declaração.
   * Se precisarmos de mais elementos, devemos redimensionar manualmente.

4. Vetores e Média:
   * Imagine calcular a média de notas de uma turma com 30 alunos.
   * Em vez de declarar 30 variáveis, podemos usar um vetor:

~~~cpp
float notas[30]; // Vetor de floats para armazenar as notas
// Preencha as notas...
// Calcule a média...
~~~

5. Vetores na STL (Standard Template Library):
   * Além dos vetores básicos, a STL oferece a classe vector, que é mais versátil e dinâmica.
   * Os vetores da STL podem crescer automaticamente conforme necessário.

Em resumo, vetores em C++ são ferramentas poderosas para trabalhar com coleções de dados do mesmo tipo, permitindo acesso rápido e manipulação eficiente. 🚀