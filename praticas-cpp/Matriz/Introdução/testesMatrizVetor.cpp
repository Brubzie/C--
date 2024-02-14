#include <iostream>
#include <locale>

using namespace std;

void clean() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause() {
#ifdef _WIN32
    system("pause");
#else
    cout << "Pressione Enter para continuar..." << endl;
    cin.ignore(); // Limpa o buffer de entrada
#endif
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int menu = 0, vetorDeMatrizes = 0, numeroDeMatriz = 0;

    cout << "Informe o número de Matriz a serem criadas: ";
    cin >> numeroDeMatriz;

    clean();

    cout <<

    return 0;
}