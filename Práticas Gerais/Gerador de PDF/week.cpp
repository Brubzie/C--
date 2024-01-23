#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include "WEEK_HEADER.h" // Arquivo de cabeçalho

int main() {
    setlocale(LC_ALL, "Portuguese");

    std::string tarefas;
    std::ofstream arquivo;

    int menu;

    arquivo.open("tarefas.txt", ios::app);

    if (!arquivo) {
        std::cout << "[Erro] Impossibilitado de abrir o arquivo." << std::endl;
        return 1;
    }

    do {
        limpar();

        std::cout << "=== Menu de Tarefas ===" << std::endl
                  << "1 - Adicionar Tarefa" << std::endl
                  << "2 - Remover Tarefa" << std::endl
                  << "3 - Editar Tarefa" << std::endl
                  << "4 - Definir dia como 'livre'" << std::endl
                  << "5 - Sair" << std::endl
                  << "Opção: ";
        std::cin >> menu;

        limpar();

        switch (menu) {
            case 1: {
                int dia;

                std::cout << "1 - Segunda" << std::endl
                          << "2 - Terça" << std::endl
                          << "3 - Quarta" << std::endl
                          << "4 - Quinta" << std::endl
                          << "5 - Sexta" << std::endl
                          << "6 - Sábado" << std::endl
                          << "7 - Domingo" << std::endl << std::endl;
                          << "Informe o dia da semana para a tarefa: ";
                std::cin >> dia;

                limpar();

                switch (dia) {
                    case 1: { // Segunda
                        cadastroDeTarefa();

                        break;
                    }
                    case 2: { // Terça
                        break;
                    }
                    case 3: { // Quarta
                        break;
                    }
                    case 4: { // Quinta
                        break;
                    }
                    case 5: { // Sexta
                        break;
                    }
                    case 6: { // Sábado
                        break;
                    }
                    case 7: { // Domingo
                        break;
                    }
                    default: { // Opção inválida
                        std::cout << "[ERRO] Informe um número de 1 a 7, correspondente ao dia da semana que queira adicionar sua tarefa." << std::endl;
                        pausar();
                        break;
                    }
                }

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
                std::cout << "[ERRO] Insira um número entre 1 e 5." << std::endl;
                pausar();
                break;
            }
        }
    } while (menu != 4);

    // std::cout << "Digite sua tarefa: ";
    // std::getline(cin, tarefas);

    // arquivo << tarefas << std::endl;

    // arquivo.close();

    // cout << "Tarefa salva com sucesso!" << std::endl;

    return 0;
}