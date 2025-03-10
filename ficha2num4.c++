#include <iostream>
using namespace std;

int main() {
    int numeros[12];
    int positivos = 0, negativos = 0;
    int contador = 0;

    // Leitura dos 12 valores com do-while
    do {
        cout << "Digite o " << contador + 1 << "º valor: ";
        cin >> numeros[contador];
        
        if (numeros[contador] < 0) {
            negativos++;
        } else if (numeros[contador] > 0) {
            positivos++;
        }
        
        contador++;
    } while (contador < 12);

    // Menu de visualização com do-while
    int opcao;
    do {
        cout << "\nOpções de visualização:\n";
        cout << "1 - Quantidade de valores positivos/negativos\n";
        cout << "2 - Lista completa dos valores inseridos\n";
        cout << "Escolha uma opção (1 ou 2): ";
        cin >> opcao;

        if (opcao == 1) {
            cout << "\nPositivos: " << positivos << endl;
            cout << "Negativos: " << negativos << endl;
        } else if (opcao == 2) {
            cout << "\nValores inseridos:\n";
            for (int i = 0; i < 12; i++) {
                cout << numeros[i] << " ";
            }
            cout << endl;
        } else {
            cout << "Opção inválida! Tente novamente.\n";
        }
    } while (opcao != 1 && opcao != 2);

    return 0;
}
