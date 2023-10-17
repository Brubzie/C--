#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Produto {
    string nome;
    float preco;
    int quantidadeEstoque;

    Produto(const string& _nome, float _preco, int _quantidadeEstoque)
        : nome(_nome), preco(_preco), quantidadeEstoque(_quantidadeEstoque) {}
};

vector<Produto> produtos;

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausar() {
#ifdef _WIN32
    system("pause");
#else
    system("read -n1 -r -p \"Pressione qualquer tecla para continuar...\"");
#endif
}

void exibirMenu() {
    cout << "Menu:\n";
    cout << "1. Adicionar produto\n";
    cout << "2. Vender produto\n";
    cout << "3. Calcular total dos boletos\n";
    cout << "4. Receber pagamento\n";
    cout << "5. Exibir estoque\n";
    cout << "6. Sair\n";
}

void adicionarProduto() {
    limparTela();

    string nome;
    float preco;
    int quantidadeEstoque;

    cout << "Digite o nome do produto: ";
    cin.ignore();
    getline(cin, nome);

    cout << "Digite o preco do produto: ";
    cin >> preco;

    cout << "Digite a quantidade em estoque: ";
    cin >> quantidadeEstoque;

    Produto novoProduto(nome, preco, quantidadeEstoque);
    produtos.push_back(novoProduto);
    cout << "Produto adicionado com sucesso.\n";

    pausar();
}

void venderProduto() {
    limparTela();

    cout << "Produtos disponiveis:\n";
    for (size_t i = 0; i < produtos.size(); ++i) {
        cout << i + 1 << ". " << produtos[i].nome << " (R$" << produtos[i].preco << ") - Estoque: " << produtos[i].quantidadeEstoque << "\n";
    }

    int escolha;
    cout << "Escolha o produto a vender (0 para cancelar): ";
    cin >> escolha;

    if (escolha >= 1 && escolha <= static_cast<int>(produtos.size())) {
        int quantidade;
        cout << "Digite a quantidade a vender: ";
        cin >> quantidade;

        if (quantidade > 0 && quantidade <= produtos[escolha - 1].quantidadeEstoque) {
            float valorTotal = quantidade * produtos[escolha - 1].preco;
            produtos[escolha - 1].quantidadeEstoque -= quantidade;
            cout << "Venda realizada com sucesso. Valor total: R$" << valorTotal << "\n";
        } else {
            cout << "Quantidade inválida ou insuficiente em estoque.\n";
        }
    } else if (escolha != 0) {
        cout << "Opcao invalida.\n";
    }

    pausar();
}

float calcularTotalBoletos(int numBoletos) {
    float total = 0.0;
    for (int i = 0; i < numBoletos; ++i) {
        float valorBoleto;
        cout << "Digite o valor do boleto " << i + 1 << ": ";
        cin >> valorBoleto;
        total += valorBoleto;
    }
    return total;
}

void exibirEstoque() {
    limparTela();

    cout << "Estoque:\n";
    for (const auto& produto : produtos) {
        cout << produto.nome << " - Estoque: " << produto.quantidadeEstoque << "\n";
    }

    pausar();
}

int main() {
    int opcao;
    while (true) {
        limparTela();
        exibirMenu();
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                adicionarProduto();
                break;
            case 2:
                venderProduto();
                break;
            case 3: {
                int numBoletos;
                cout << "Digite o numero de boletos a cadastrar: ";
                cin >> numBoletos;
                cout << "Total dos boletos: R$" << calcularTotalBoletos(numBoletos) << "\n";
                pausar();
                break;
            }
            case 4:
                cout << "Pagamento recebido.\n";
                pausar();
                break;
            case 5:
                exibirEstoque();
                break;
            case 6:
                cout << "Saindo do programa.\n";
                return 0;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
                pausar();
                break;
        }
    }

    return 0;
}