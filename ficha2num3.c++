#include <iostream>
#include <string>
using namespace std;

int main() {
    string nomeMaisLongo = "";
    int contador = 0;

    while (contador < 3) {
        string primeiroNome, apelido;
        cout << "Digite o " << contador + 1 << "º nome próprio: ";
        cin >> primeiroNome;
        cout << "Digite o " << contador + 1 << "º apelido: ";
        cin >> apelido;
        
        string nomeCompleto = primeiroNome + " " + apelido;
        
        if (nomeCompleto.length() > nomeMaisLongo.length()) {
            nomeMaisLongo = nomeCompleto;
        }
        
        contador++;
    }

    cout << "\nNome com mais caracteres: " << nomeMaisLongo << endl;
    return 0;
}
