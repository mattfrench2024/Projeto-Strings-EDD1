#include <iostream>
#include <locale.h>
#include <windows.h>

using namespace std;

void posicionarCursor(short x, short y)
{
    COORD coord = {x, y};
    SetConsoleCursorPosition( 
       GetStdHandle(STD_OUTPUT_HANDLE), coord 
    );
}

int main(int argc, char** argv) 
{
    setlocale(LC_ALL, "");
    string texto;
    
    cout << "Digite o texto a ser exibido: ";
    cin >> texto;
    cout << endl;
    
    int posicaoCentral = (80 - texto.size()) / 2;
    
    // Imprimir a mensagem na linha 5
    posicionarCursor(posicaoCentral, 5);
    cout << texto;
    
    // Exibir o efeito de cascata
    for (int j = 0; j < texto.size(); ++j) {
        for (int i = 5; i < 20; ++i) {
            // Criar o efeito de cascata para cada caractere
            posicionarCursor(posicaoCentral + j, i);
            cout << texto[j];
            Sleep(100);
            posicionarCursor(posicaoCentral + j, i);
            cout << ' ';  // Apagar o caractere após a impressão
        }
    }

    // Finalizar com o caractere na linha 20
    for (int i = 0; i < texto.size(); ++i) {
        posicionarCursor(posicaoCentral + i, 20);
        cout << texto[i];
    }
    cout << endl;

    cout << "Cascata" << endl; 
    
    return 0;
}
