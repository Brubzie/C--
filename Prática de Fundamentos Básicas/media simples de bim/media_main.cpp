#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {

    int nota1, nota2, nota3, presenca, media;
    string nomeAluno;
    char resposta;

    do {

        cout << "Nome do aluno: ";
        cin >> nomeAluno;

        cout << "\nNota da primeira prova: ";
        cin >> nota1;

        cout << "\nNota da segunda prova: ";
        cin >> nota2;

        cout << "\nNota da terceira prova: ";
        cin >> nota3;

        cout << "\nPresenca nas aulas do bimestre: ";
        cin >> presenca;

        media = (nota1 + nota2 + nota3) / 3;

        if (media >= 6 && presenca >= 75) {

            cout << "\nAluno: " << nomeAluno <<
                    "\nMedia: " << media <<
                    "\nPresenca: " << presenca << "%\n" <<
                    nomeAluno << " foi aprovado(a).";

        } else {

            cout << "\nAluno: " << nomeAluno <<
                    "\nMedia: " << media <<
                    "\nPresenca: " << presenca << "%\n" <<
                    nomeAluno << " voce foi reprovado.";

        }

        cout << "\nDeseja fazer o requerimento da media de outro aluno? (s/n)\n";
        cin >> resposta;
        
    } while (resposta == 's' || resposta == 'S');

    return 0;
}
