#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const int TAMANHO = 5;
const int DIAS_SEMANA = 5;

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausar() {
    cout << "\nPressione Enter para continuar...";
    cin.get();  // Espera somente uma vez por Enter
}

int main() {
    int codigos[TAMANHO] = {101, 102, 103, 111, 112};
    string artigos[TAMANHO] = {"processador", "processador", "disco", "disco", "monitor"};
    string modelos[TAMANHO] = {"P1", "P2", "D1", "D2", "M1"};
    float precos[TAMANHO] = {20, 30, 60, 15, 20};
    int stock[TAMANHO] = {21, 10, 5, 15, 20};
    int vendas[TAMANHO][DIAS_SEMANA] = {
        {5, 4, 3, 2, 6},
        {3, 2, 5, 1, 4},
        {1, 0, 2, 1, 0},
        {8, 7, 6, 8, 5},
        {4, 3, 2, 3, 4}
    };

    int opcao;
    int indiceValidado = -1;

    while (true) {
        limparTela();
        cout << "\n======================================\n";
        cout << "|          OPÇÕES DISPONÍVEIS        |\n";
        cout << "======================================\n";
        
        if (indiceValidado == -1) {
            cout << "| 1  - Listar                        |\n";
            cout << "| 2  - Validar Código                |\n";
            cout << "| 3  - Quantidade em Stock           |\n";
            cout << "| 4  - Valor da Semana               |\n";
        } else {
            cout << "| 5  - Valor em Stock                |\n";
            cout << "| 6  - Mais Barato na Categoria      |\n";  // Alterado para refletir a lógica do código
            cout << "| 7  - Voltar ao Menu Principal      |\n";
        }
        
        cout << "| 0  - Sair                          |\n";
        cout << "======================================\n";
        cout << " Escolha uma opção: ";
        cin >> opcao;
        cin.ignore();

        if (indiceValidado == -1) {
            if (opcao == 1) {
                cout << "\nListagem de Artigos:\n";
                for (int i = 0; i < TAMANHO; i++) {
                    cout << "Código: " << codigos[i] 
                        << " - Artigo: " << artigos[i] 
                        << " - Modelo: " << modelos[i] 
                        << " - Preço: " << precos[i] << "€\n";
                }
                pausar();
            } else if (opcao == 2) {
                int codigo;
                cout << "Introduza o código do produto: ";
                cin >> codigo;
                for (int i = 0; i < TAMANHO; i++) {
                    if (codigos[i] == codigo) {
                        indiceValidado = i;
                        cout << "Código válido! Produto: " << artigos[indiceValidado] << " (" << modelos[indiceValidado] << ")\n";
                        break;
                    }
                }
                if (indiceValidado == -1) {
                    cout << "Código inválido. Tente novamente.\n";
                }
                pausar();
            } else if (opcao == 3) {
                int codigo;
                cout << "Introduza o código do produto: ";
                cin >> codigo;
                for (int i = 0; i < TAMANHO; i++) {
                    if (codigos[i] == codigo) {
                        cout << "Stock do produto " << artigos[i] << " (" << modelos[i] << ") : " << stock[i] << " unidades\n";
                        break;
                    }
                }
                pausar();
            } else if (opcao == 4) {
                cout << "\nValor da Semana:\n";
                for (int i = 0; i < TAMANHO; i++) {
                    int totalVendas = 0;
                    for (int j = 0; j < DIAS_SEMANA; j++) {
                        totalVendas += vendas[i][j];
                    }
                    float valorTotal = totalVendas * precos[i];
                    cout << "Produto: " << artigos[i] << " (" << modelos[i] << ")\n";
                    cout << "Vendas totais: " << totalVendas << " unidades\n";
                    cout << "Valor gerado: " << valorTotal << "€\n\n";
                }
                pausar();
            } else if (opcao == 0) {
                cout << "A sair...\n";
                limparTela();
                break;
            }
        } else {
            if (opcao == 5) {
                float totalValorStock = 0;
                for (int i = 0; i < TAMANHO; i++) {
                    totalValorStock += precos[i] * stock[i];
                }
                cout << "Valor total em stock: " << totalValorStock << "€\n";
                pausar();
            } else if (opcao == 6) {
                // Aqui, automaticamente, o programa vai verificar a categoria do produto validado
                string categoria = artigos[indiceValidado];  // Usa a categoria do produto validado
                cout << "Categoria do produto validado: " << categoria << "\n";

                int indiceMaisBarato = -1;
                float precoMaisBarato = 999999;  // Um valor alto para garantir que qualquer produto será mais barato que isso

                for (int i = 0; i < TAMANHO; i++) {
                    // Filtra pela categoria do produto validado
                    if (artigos[i] == categoria) {
                        if (precos[i] < precoMaisBarato) {
                            precoMaisBarato = precos[i];
                            indiceMaisBarato = i;
                        }
                    }
                }

                if (indiceMaisBarato != -1) {
                    cout << "Produto mais barato na categoria '" << categoria << "': " 
                         << artigos[indiceMaisBarato] << " (" << modelos[indiceMaisBarato] << ") - "
                         << precos[indiceMaisBarato] << "€\n";
                } else {
                    cout << "Nenhum produto encontrado para a categoria '" << categoria << "'.\n";
                }
                pausar();
            } else if (opcao == 7) {
                indiceValidado = -1;
                cout << "Retornando ao menu principal...\n";
                pausar();
            } else if (opcao == 0) {
                cout << "A sair...\n";
                limparTela();
                break;
            }
        }
    }
    return 0;
}