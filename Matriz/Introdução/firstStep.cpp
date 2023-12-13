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

    // int matriz[2][3] = {{1, 2, 3}, {4, 5, 6}};

    int menu = 0, linhas = 0, colunas = 0;

    cout << "Defina a quantidade de linhas da matriz: ";
    cin >> linhas;

    cout << "Defina a quantidade de colunas da matriz: ";
    cin >> colunas;

    int matriz[linhas][colunas];

    do {
        clean();

        cout << "=== Matriz ===" << endl
             << "1 - Adicionar valor para as " << colunas << " coluna(s)" << endl
             << "2 - Mostrar matriz" << endl
             << "3 - Sair" << endl
             << "Opção: ";
        cin >> menu;

        clean();

        switch (menu) {
            case 1: {
                for (int i = 0; i < linhas; ++i) {
                    for (int j = 0; j < colunas; ++j) {
                        cout << "Matriz[ " << i << " ][ " << j << " ]: ";
                        cin >> matriz[i][j];
                    }
                }
            } break;
            case 2: {
                for (int i = 0; i < 2; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        cout << matriz[i][j] << " | ";
                    }
                    cout << endl;
                }
                pause();
            } break;
            case 3: {
                cout << "Encerrando..." << endl;
            } break;
            default: {
                cout << "[ERRO] Opção inválida! Insira outro valor.";
                pause();
            } break;
        }
    } while (menu != 3);

    return 0;
}