#include <iostream>
#include <conio.h>

using namespace std;

int main() {

    const char ESC = 27;
    char resposta = NULL;
    int pontos = 0, erros = 4;

    do {
        system("cls");

        cout << "=== Quiz - One Piece ===\n" <<
                "1) De quem era o chapeu de palha antes de Shanks, o Ruivo?\n" <<
                "a. Monkey D. Garp\n" <<
                "b. Dandan\n" <<
                "c. Gol D. Roger\n";
        cin >> resposta;

        if (resposta == 'c' || resposta == 'C') {
            pontos = pontos + 1;
            erros = erros - 1;
            cout << "\nCerta resposta!\n";
        } else cout << "\nResposta errada!\n";

        cout << "\n2) Os novos golpes de Luffy apos o time skip, são baseados em:\n" <<
                "a. Tipos de comida\n" <<
                "b. Animais\n" <<
                "c. Armas de fogo\n";
        cin >> resposta;

        if (resposta == 'b' || resposta == 'B') {
            pontos = pontos + 1;
            erros = erros - 1;
            cout << "\nCerta resposta!\n";
        } else cout << "\nResposta errada!\n";

        cout << "\n3) Como se chama a akuma no mi de Barba Negra?\n" <<
                "a. Yami yami no mi\n" <<
                "b. Gura gura no mi\n" <<
                "c. Gomu gomu no mi\n";
        cin >> resposta;

        if (resposta == 'a' || resposta == 'A') {
            pontos = pontos + 1;
            erros = erros - 1;
            cout << "\nCerta resposta!\n";
        } else cout << "\nResposta errada!\n";

        cout << "\n4) Qual a comida favorita de Franky?\n" <<
                "a. Hamburguer\n" <<
                "b. Macarrao\n" <<
                "c. Bolinhos de arroz\n";
        cin >> resposta;

        if (resposta == 'a' || resposta == 'A') {
            pontos = pontos + 1;
            erros = erros - 1;
            cout << "\nCerta resposta!\n";
        } else cout << "\nResposta errada!\n";

        cout << "\nAcertos: " << pontos <<
                "\nErros..: " << erros << '\n';

        system ("Pause");

        cout << "\nPressione ESC para encerrar...\nAperte qualquer tecla para continuar...\n";
    } while (getchar() != ESC);

    return 0;
}