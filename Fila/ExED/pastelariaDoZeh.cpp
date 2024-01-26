// Projeto: Pastelaria do seu Zé
#include <iostream>
#include <cstdlib>
#include <locale> // Para definir a linguagem pt-br
#include <fstream> // Para criar o relatório dentro de um arquivo .txt
#include <string> // Para guardar dentro de uma variável string elementos de uma linha completa
#include <limits>
#include <random>
#include "HEADER_PASTELARIA.h" // Puxando o arquivo de cabeçalho do arquivo

using namespace std;

int main() {
    setlocale(LC_ALL, "portuguese");

    int menu = 0;

    ListaPedidos listaPedidos;
    inicializar(&listaPedidos);

    cout << "Seja Bem-Vindo à Pastelaria do Zé!" << endl << endl
         << "__________________________________" << endl
         << "|      Cardápio dos Pastéis      |" << endl
         << "| Sabores:                       |" << endl
         << "|                                |" << endl
         << "| 1. Pizza:                      |" << endl
         << "| Massa, 30 gramas de queijo, 30 |" << endl
         << "| gramas de presunto, duas fatias|" << endl
         << "| de tomate e orégano.           |" << endl
         << "|                                |" << endl
         << "| 2. Queijo:                     |" << endl
         << "| Massa, 50 gramas de queijo.    |" << endl
         << "|                                |" << endl
         << "| 3. Frango:                     |" << endl
         << "| Massa, 50 gramas de frango.    |" << endl
         << "|                                |" << endl
         << "| Vento:                         |" << endl
         << "| Somente massa, sem recheio.    |" << endl
         << "|________________________________|" << endl;

    pausar();

    do {
        limpar();

        cout << "_____________________________" << endl
             << "| ========== Menu ========= |" << endl
             << "| 1 - Cadastrar Pedido      |" << endl
             << "| 2 - Editar Pedido         |" << endl
             << "| 3 - Mostrar Pedidos       |" << endl
             << "| 4 - Pedido Entregue       |" << endl
             << "| 5 - Sair                  |" << endl
             << "|___________________________|" << endl
             << "Opção: ";
        cin >> menu;

        limpar();

        switch (menu) {
            case 1: {
                Pedido novoPedido;

                criarSenha(novoPedido.senhaDoPedido);

                cin.ignore(numeric_limits<streamsize>::max(),'\n');

                cout << "Informe o nome do cliente: ";
                getline(cin, novoPedido.nomeDoCliente); // Pode ser informado o nome completo do cliente

                int quantidadePizza = 0;
                int quantidadeQueijo = 0;
                int quantidadeFrango = 0;
                int quantidadeVento = 0;

                cout << "Informe a quantidade de itens comprados a seguir" << endl;

                cout << "Pastéis de pizza: ";
                cin >> quantidadePizza;
                
                cout << "Pastéis de queijo: ";
                cin >> quantidadeQueijo;
                
                cout << "Pastéis de frango: ";
                cin >> quantidadeFrango;
                
                cout << "Pastéis de vento: ";
                cin >> quantidadeVento;

                if (verificarIngredientes(&listaPedidos, quantidadePizza * 30, quantidadeQueijo * 50, quantidadeFrango * 30 + quantidadeVento * 30)) {
                    usarIngredientes(&listaPedidos, quantidadePizza * 30, quantidadeQueijo * 50, quantidadeFrango * 30 + quantidadeVento * 30);
                    novoPedido.pasteisDePizza = quantidadePizza;
                    novoPedido.pasteisDeQueijo = quantidadeQueijo;
                    novoPedido.pasteisDeFrango = quantidadeFrango;
                    novoPedido.pasteisDeVento = quantidadeVento;
                } else {
                    cout << endl << "[ERRO] Ingredientes insuficientes para fazer os pastéis!" << endl;
                    pausar();
                }

                cout << "Coca-Cola: ";
                cin >> novoPedido.refriCoca;

                cout << "Pepsi: ";
                cin >> novoPedido.refriPepsi;

                cadastrarPedido(&listaPedidos, &novoPedido);
                break;
            }
            case 2: {
                int senha = 0;

                cout << "Informe a senha do pedido que deseja editar: ";
                cin >> senha;

                editarPedido(&listaPedidos, senha);
                break;
            }
            case 3: {
                mostrarPedidos(&listaPedidos);
                break;
            }
            case 4: {
                int senhaEntregue;

                cout << "Informe a senha do pedido entregue: ";
                cin >> senhaEntregue;
                
                removerPedido(&listaPedidos, senhaEntregue);
                break;
            }
            case 5: {
                cout << "Volte sempre á Pastelaria do Zé!" << endl;
                cout << "Saindo...";
                break;
            }
            default: {
                cout << "[ERRO] Informe uma opção válida!" << endl;
                cout << "Na tela 'menu', selecione uma opção entre 1 e 5." << endl;
                pausar();
                break;
            }
        }
    } while (menu != 5);

    destruir(&listaPedidos);

    return 0;
}