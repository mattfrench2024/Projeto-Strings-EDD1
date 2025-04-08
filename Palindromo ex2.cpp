
#include <iostream>
#include <locale.h>
#include <string>
#include <algorithm>

using namespace std;

bool ehPalindromo(string texto)
{
    // Remover os espaços da string
    texto.erase(remove(texto.begin(), texto.end(), ' '), texto.end());
    
    // Converter para minúsculas para comparação case insensitive
    transform(texto.begin(), texto.end(), texto.begin(), ::tolower);

    // Verificar se a string é igual ao seu inverso
    string textoInvertido = texto;
    reverse(textoInvertido.begin(), textoInvertido.end());

    return texto == textoInvertido;
}

int main() 
{
    setlocale(LC_ALL, "");
    string mensagem;

    cout << "Digite uma mensagem: ";
    getline(cin, mensagem);  // Usar getline para permitir frases com espaços

    if (ehPalindromo(mensagem)) {
        cout << "A mensagem é um palíndromo!" << endl;
    } else {
        cout << "A mensagem NÃO é um palíndromo!" << endl;
    }
    
    return 0;
}
