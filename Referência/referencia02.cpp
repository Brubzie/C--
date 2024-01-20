#include <iostream>
#include <locale>
#include <string>
#include "REFERENCIA_HEADER.h"
#include "CLIENTES_HEADER.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    Cliente* cabeca = new Cliente;
    inicializar(cabeca);

    int menu = 0;

    do {
        clean();

        cout << "====== Menu ======" << endl
             << "1 - Adicionar Cliente" << endl
             << "2 - Visualizar Clientes" << endl
             << "3 - Editar Cliente" << endl
             << "4 - Excluir Cliente" << endl
             << "5 - Sair" << endl
             << "Opção: ";
        cin >> menu;

        clean();

        switch (menu) {
            case 1: {
                Cliente* novoCliente = new Cliente;

                cout << "Informe o nome do Cliente: ";
                cin.ignore();
                getline(cin, novoCliente->nomeCliente);

                cout << "Informe o email do Cliente: ";
                cin >> novoCliente->emailCliente;

                cout << "Informe o número de contato do Cliente: ";
                cin >> novoCliente->numeroCliente;

                // O primeiro nó não tem um próximo nó
                novoCliente->prox = nullptr;

                cout << endl << "Cliente adicionado com sucesso!" << endl;

                break;
            }
            case 2: {
                cout << "Cliente cadastrados:" << endl;
                
                Cliente* atual = cabeca;

                while (atual != nullptr) {
                    cout << "Nome: " << atual->nomeCliente << endl
                         << "Email: " << atual->emailCliente << endl
                         << "Número: " << atual->numeroCliente << endl;

                    atual = atual->prox;
                }

                break;
            }
            case 3: {
                if (atual == nullptr) {
                    cout << "[ERRO] Adicione algum cliente antes!" << endl;
                } else {
                    while (atual != nullptr) {
                        cout << "Novo nome do Cliente: ";
                        cin.ignore();
                        getline(cin, novoCliente->nomeCliente);

                        cout << "Novo email do Cliente: ";
                        cin >> novoCliente->emailCliente;

                        cout << "Novo número do Cliente: ";
                        cin >> novoCliente->numeroCliente;

                        cout << endl << "Cliente editado com sucesso!" << endl;
                    }
                }

                break;
            }
            case 4: {
                break;
            }
            case 5:
            cout << "Saindo..." << endl;
            break;

            default:
            cout << "[ERRO] Opção inválida!" << endl
                 << "Selecione uma opção entre 1 - 5." << endl;
            break;
        }

        if (menu < 5 && menu > 0) pause();
    } while (menu != 5);

    // Liberando a memória alocada
    destruir(&ListaCompras);

    return 0;
}