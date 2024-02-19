#include <iostream>
#include <locale>
#include <limits>

using namespace std;

// Protótipo de Função
void clean();
void pause();

int main() {
    setlocale(LC_ALL, "portuguese");

    // int matriz[3][4] = {
    //     {0, 0, 0, 0},
    //     {1, 1, 1, 1},
    //     {2, 2, 2, 2}
    // };

    int matriz[3][4];
    int linhas, colunas;

    for(linhas = 0; linhas < 3; linhas++) {
        for(int colunas = 0; colunas < 4; colunas++) {
            cout << "Matriz[ " << linhas << " ][ " << colunas << " ]: ";
            cin >> matriz[linhas][colunas];
        }
        cout << endl;
    }

    for(linhas = 0; linhas < 3; linhas++) {
        for(int colunas = 0; colunas < 4; colunas++) {
            cout << matriz[linhas][colunas] << ' ';
        }
        cout << endl;
    }

    return 0;
}

// Funções
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
    cout << "Pressione Enter para continuar...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer de entrada
#endif
}