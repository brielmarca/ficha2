#include <iostream>
#include <string>
using namespace std;

int main() {
    string localidades[5];
    int i;

    // Leitura das 5 localidades usando for
    for (i = 0; i < 5; i++) {
        cout << "Digite a " << i + 1 << "ª localidade: ";
        cin >> localidades[i];
    }

    // Menu principal com do-while
    char opcao;
    do {
        cout << "\n=== MENU ===\n";
        cout << "a) Listar todas as localidades\n";
        cout << "b) Consultar uma localidade\n";
        cout << "c) Alterar uma localidade\n";
        cout << "Escolha uma opção (a/b/c): ";
        cin >> opcao;

        if (opcao == 'a') {
            // Listar todas (usando for)
            cout << "\nLista de localidades:\n";
            for (i = 0; i < 5; i++) {
                cout << i + 1 << " - " << localidades[i] << endl;
            }
        }
        else if (opcao == 'b') {
            // Consultar (usando while)
            string busca;
            cout << "\nDigite a localidade a consultar: ";
            cin >> busca;
            
            int indice = -1;
            i = 0;
            while (i < 5) {
                if (localidades[i] == busca) {
                    indice = i;
                    break;
                }
                i++;
            }
            
            if (indice != -1) {
                cout << "Localidade encontrada na posição " << indice + 1 << endl;
            }
            else {
                cout << "Localidade não encontrada!" << endl;
            }
        }
        else if (opcao == 'c') {
            // Alterar (usando while para buscar e for para listar)
            string busca;
            cout << "\nDigite a localidade a alterar: ";
            cin >> busca;
            
            int indice = -1;
            i = 0;
            while (i < 5) {
                if (localidades[i] == busca) {
                    indice = i;
                    break;
                }
                i++;
            }
            
            if (indice != -1) {
                cout << "Digite o novo nome: ";
                cin >> localidades[indice];
                cout << "Localidade alterada com sucesso!\n";
                
                // Nova listagem para confirmar
                cout << "\nLista atualizada:\n";
                for (i = 0; i < 5; i++) {
                    cout << i + 1 << " - " << localidades[i] << endl;
                }
            }
            else {
                cout << "Localidade não encontrada!" << endl;
            }
        }
        else {
            cout << "Opção inválida!" << endl;
        }

    } while (opcao == 'a' || opcao == 'b' || opcao == 'c');

    return 0;
}
