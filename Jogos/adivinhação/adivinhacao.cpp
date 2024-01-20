#include <iostream>
#include <locale>
#include <random> 
#include "ADIVINHACAO_HEADER.h" // Arquivo de cabeçalho

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    int menu = 0, senha = 0, tentativas = 0, dificuldade = 0, senhaJogador = 0;
    bool respostaCerta = false;

    do {
        limpar();

        cout << "Número Secreto" << endl;
        cout << "Objetivo: Descubra o número secreto entre 10 e 99 e ganhe." << endl;

        cout << "==== Menu ====" << endl;
        cout << "1 - Jogar" << endl;
        cout << "2 - Sair" << endl;
        cout << "Opção: ";
        cin >> menu;

        switch (menu) {
            case 1: { // Início do Jogo
                do {
                    cout << "==== Dificuldade ====" << endl;
                    cout << "1 - Fácil (15 tentativas)" << endl;
                    cout << "2 - Médio (10 tentativas)" << endl;
                    cout << "3 - Difícil (5 tentativas)" << endl;
                    cout << "Opção: ";
                    cin >> dificuldade;

                    limpar();

                    randomPassword(senha);

                    switch (dificuldade) {
                        case 1: { // Fácil
                            tentativas = 15;

                            while (tentativas != 0 && respostaCerta == false) {
                                cout << "Senha: ";
                                cin >> senhaJogador;

                                if (senhaJogador == senha) {
                                    respostaCerta = true;
                                    cout << "Parabéns!" << endl;
                                    cout << "Você ganhou!" << endl;
                                } else {
                                    tentativas--;
                                    if (senhaJogador < senha) {
                                        cout << "Maior" << endl;
                                    } else {
                                        cout << "Menor" << endl;
                                    }
                                }

                                cout << "Tentativas: " << tentativas << endl;
                                pausar();
                            }

                            break;
                        }
                        case 2: { // Médio
                            tentativas = 10;
                            
                            while (tentativas != 0 && respostaCerta == false) {
                                
                            }

                            break;
                        }
                        case 3: { // Difícil
                            tentativas = 5;

                            while (tentativas != 0 && respostaCerta == false) {
                                
                            }

                            break;
                        }
                        default: { // Caso seja escolhida uma opção inválida
                            cout << "[ERRO] Opção inválida!" << endl;
                            break;
                        }
                    }
                } while (respostaCerta == false && tentativas != 0);
                break;
            }
            case 2: { // Encerrando
                cout << "Saindo..." << endl;
                break;
            }
            default: { // Caso seja escolhida uma opção inválida
                cout << "[ERRO] Opção inválida!" << endl;
                pausar();
                break;
            }
        }
    } while (menu != 2);

    return 0;
}