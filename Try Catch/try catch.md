# O que é?

1. Bloco `try`:
   * O bloco `try` envolve um conjunto de instruções que podem lançar exceções.
   * Se ocorrer uma exceção dentro do bloco `try`, o programa procura o bloco catch correspondente.
   * Você pode colocar um bloco `try` em qualquer lugar onde uma instrução seja permitida (por exemplo, dentro do corpo de uma função ou de um bloco composto).

2. Bloco `catch`:
   * O bloco `catch` trata exceções específicas.
   * Cada bloco `catch` especifica o tipo de exceção que ele pode manipular.
   * Recomenda-se capturar exceções por referência constante (`const`) para evitar cópias desnecessárias.
   * Você pode ter vários blocos `catch` para diferentes tipos de exceções.

3. Bloco `throw`:
* A expressão `throw` sinaliza que ocorreu uma condição excepcional (geralmente um erro) dentro do bloco `try`.
* Você pode lançar exceções de qualquer tipo, mas é recomendado usar a classe `std::exception` ou derivadas da biblioteca padrão (`std`).

4. Exemplo:
~~~cpp
#include <iostream>

using namespace std;

int main() {
    try {
        int numerador = 10;
        int denominador = 0;
        int resultado = numerador / denominador; // Lança uma exceção
        cout << "Resultado: " << resultado << endl;
    } catch (const char* mensagemErro) {
        cout << "Exceção capturada: " << mensagemErro << endl;
    }

    return 0;
}
~~~

Neste exemplo, a divisão por zero lança uma exceção, que é capturada pelo bloco catch. O programa exibe uma mensagem de erro apropriada.

***

# Diferenças entre if-else e try-catch em C++

`if-else` e `try-catch` são ambos mecanismos de controle de fluxo em C++, mas eles são usados em diferentes contextos e para diferentes propósitos.

## if-else

O `if-else` é usado para tomar decisões com base em condições. Se a condição especificada no `if` for verdadeira, o bloco de código dentro do `if` será executado. Caso contrário, o bloco de código dentro do `else` será executado (se houver um).

Exemplo:

~~~cpp
#include <iostream>

using namespace std;

int main() {
    int x = 0;

    cout << "Informe o valor de X: ";
    cin >> x;
    
    if (x > 5) {
        cout << "x é maior que 5";
    } else {
        cout << "x é menor ou igual a 5";
    }

    return 0;
}
~~~
## try-catch

O `try-catch` é usado para lidar com exceções. O bloco de código dentro do `try` é executado e, se ocorrer uma exceção, o fluxo de controle é passado para o bloco `catch` correspondente.

Exemplo:

~~~cpp
#include <iostream>

using namespace std;

int main() { 
    try {
        int x = 0;
        int y = 10 / x; // Isso lançará uma exceção
    } catch (const exception& e) {
        cerr << "Uma exceção ocorreu: " << e.what();
    }

    return 0;
}
~~~

Neste exemplo, como estamos tentando dividir por zero, uma exceção é lançada. O bloco `catch` captura a exceção e imprime uma mensagem de erro.

Em resumo, `if-else` é usado para controle de fluxo com base em condições, enquanto `try-catch` é usado para manipulação de exceções. Ambos são ferramentas importantes para escrever código robusto e seguro.