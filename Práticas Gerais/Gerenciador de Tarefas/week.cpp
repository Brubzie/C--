#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "WEEK_HEADER.h" // Arquivo de cabeçalho

int main() {
    setlocale(LC_ALL, "Portuguese");

    ListaDeTarefas lista;
    inicializar(&lista);

    std::ofstream arquivo;

    arquivo.open("tarefas.txt", ios::app);

    if (!arquivo) {
        std::cout << "[Erro] Impossibilitado de abrir o arquivo." << std::endl;
        return 1;
    }

    int menu = 0;

    do {
        limpar();

        std::cout << "=== Menu de Tarefas ===" << std::endl
                  << "1 - Adicionar Tarefa" << std::endl
                  << "2 - Remover Tarefa" << std::endl
                  << "3 - Editar Tarefa" << std::endl
                  << "4 - Sair" << std::endl
                  << "Opção: ";
        std::cin >> menu;

        limpar();

        switch (menu) {
            case 1: {
                adicionarTarefa(&lista, &lista.ultimo->tarefa);

                break;
            }
            case 2: {
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
            case 5: {
                std::cout << "Saindo..." << std::endl;
                break;
            }
            default: {
                std::cout << "[ERRO] Insira um número entre 1 e 4." << std::endl;
                pausar();
                break;
            }
        }
    } while (menu != 4);

    destruir(&lista);

    return 0;
}