#include <iostream>

using namespace std;

int main() {

    int menu = 0;

    int tam = 0, chances = 6, acertos = 0, i = 0;

    char palavra[30];
    char letra[1];
    char secreta[30];

    bool acerto = false;

    cout << "______________________\n" <<
            "|=*= Jogo da Forca =*=|\n" <<
            "| 1 - Iniciar         |\n" <<
            "| 2 - Sair            |\n" <<
            "|_____________________|\n" <<
            "\nOpcao: ";
    cin >> menu;

    system ("cls");

    switch (menu) {
        case 1:

            cout << "\nDiga para seu amigo fechar os olhos e digite a palavra secreta: ";
            cin >> palavra;

            system ("cls");

            while (palavra[i] != '\0') { // Caractér da tecla Enter
                i++;
                tam++;
            }

            for (i = 0; i < 30; i++) {
                secreta[i] = '_';
            }

            while ((chances > 0) && (acertos < tam)) {
                cout << "Chances restantes: " << chances << "\n\n" <<
                        "Palavra secreta: ";

                for (i = 0; i < tam; i++) {
                    cout << secreta[i];
                }

                cout << "\n\nDigite uma letra: ";
                cin >> letra[0];

                for (i = 0; i < tam; i++) {
                    if (palavra[i] == letra[0]) {
                        acerto = true;
                        secreta[i] = palavra[i];
                        acertos++;
                    }
                }

                if (!acerto) {
                    chances--;
                }

                acerto = false;
                system ("cls");
            }

            if (acertos == tam) {
                cout << "\nVoce venceu! Parabens!\n";
            } else {
                cout << "\nQue pena, voce perdeu!\n";
            }

            system ("Pause");

            break;

        case 2:

            cout << "\nEncerrando...";
            return 0;

        default:

            cout << "\n[ERRO] Selecione uma opcao valida!\n";
            break;
    }

    return 0;
}