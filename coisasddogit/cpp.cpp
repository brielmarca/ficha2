#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const int TAMANHO = 5;
const int DIAS_SEMANA = 5;  // Número de dias para as vendas semanais

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausar() {
    cout << "\nPressione Enter para continuar...";
    cin.ignore();
    cin.get();
}

int main() {
    int codigos[TAMANHO] = {101, 102, 103, 111, 112};
    string artigos[TAMANHO] = {"processador", "processador", "disco", "disco", "monitor"};
    string modelos[TAMANHO] = {"P1", "P2", "D1", "D2", "M1"};
    float precos[TAMANHO] = {20, 30, 60, 15, 20};
    int stock[TAMANHO] = {21, 10, 5, 15, 20};
    int vendas[TAMANHO][DIAS_SEMANA] = {
        {5, 4, 3, 2, 6},  // Vendas semanais do produto 1
        {3, 2, 5, 1, 4},  // Vendas semanais do produto 2
        {1, 0, 2, 1, 0},  // Vendas semanais do produto 3
        {8, 7, 6, 8, 5},  // Vendas semanais do produto 4
        {4, 3, 2, 3, 4}   // Vendas semanais do produto 5
    };

    int opcao;
    int codigoValidado = -1;  // Usando um inteiro para controle

    while (true) {
        limparTela();

        cout << "\n======================================\n";
        cout << "|          OPÇÕES DISPONÍVEIS        |\n";
        cout << "======================================\n";
        
        if (codigoValidado == -1) {
            cout << "| 1  - Listar                        |\n";
            cout << "| 2  - Validar Código                |\n";
            cout << "| 3  - Quantidade em Stock           |\n";
            cout << "| 4  - Valor da Semana               |\n";
        } else {
            cout << "| 5  - Valor em Stock                |\n";
            cout << "| 6  - Mais Barato                   |\n";
            cout << "| 7  - Voltar ao Menu Principal      |\n";
        }
        
        cout << "| 0  - Sair                          |\n";
        cout << "======================================\n";
        cout << " Escolha uma opção: ";
        
        cin >> opcao;
        cin.ignore();

        if (codigoValidado == -1) {
            if (opcao == 1) {  
                cout << "\nListagem de Artigos:\n";
                for (int i = 0; i < TAMANHO; i++) {
                    cout << "Código: " << codigos[i] 
                        << " - Artigo: " << artigos[i] 
                        << " - Modelo: " << modelos[i] 
                        << " - Preço: " << precos[i] << "€\n";
                }
                pausar();
            } 
            else if (opcao == 2) {  
                int codigo;
                while (true) {
                    cout << "Introduza o código do produto: ";
                    cin >> codigo;

                    for (int i = 0; i < TAMANHO; i++) {
                        if (codigos[i] == codigo) {
                            codigoValidado = i;  // Salvando o índice do produto válido
                            cout << "Código válido!\n";
                            break;
                        }
                    }

                    if (codigoValidado != -1) break;
                    cout << "Código inválido. Tente novamente.\n";
                }
            } 
            else if (opcao == 3) {  
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
            } 
            else if (opcao == 4) {  
                cout << "\nValor da Semana:\n";
                for (int i = 0; i < TAMANHO; i++) {
                    int totalVendas = 0;
                    float valorTotal = 0;
                    cout << "Produto: " << artigos[i] << " (" << modelos[i] << ")\n";
                    for (int j = 0; j < DIAS_SEMANA; j++) {
                        totalVendas += vendas[i][j];
                    }
                    valorTotal = totalVendas * precos[i];
                    cout << "Vendas totais: " << totalVendas << " unidades\n";
                    cout << "Valor gerado: " << valorTotal << "€\n\n";
                }
                pausar();
            } 
            else if (opcao == 0) {  
                cout << "A sair...\n";
                limparTela();
                break;
            }
        } 
        else {  
            if (opcao == 5) {  
                float totalValorStock = 0;
                for (int i = 0; i < TAMANHO; i++) {
                    totalValorStock += precos[i] * stock[i];
                }
                cout << "Valor total em stock: " << totalValorStock << "€\n";
                pausar();
            } 
            else if (opcao == 6) {  
                int indiceMaisBarato = 0;
                for (int i = 1; i < TAMANHO; i++) {
                    if (precos[i] < precos[indiceMaisBarato]) {
                        indiceMaisBarato = i;
                    }
                }
                cout << "Produto mais barato: " << artigos[indiceMaisBarato] << " (" << modelos[indiceMaisBarato] << ") - " << precos[indiceMaisBarato] << "€\n";
                pausar();
            } 
            else if (opcao == 7) {  
                codigoValidado = -1;  // Redefine o código validado
                cout << "Retornando ao menu principal...\n";
                pausar();
            }
            else if (opcao == 0) {  
                cout << "A sair...\n";
                limparTela();
                break;
            }
        }
    }

    return 0;
}
