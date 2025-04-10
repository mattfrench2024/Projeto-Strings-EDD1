/*
  EXERCÍCIO 4: A partir de uma lista de nomes disponível em um arquivo TXT, transformá-los em nomes no formato de citação bibliográfica.
  Exemplo: José Antonio Santos Silva => SILVA, José A. S.
*/

#include <iostream>
#include <fstream>
#include <locale.h>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    ifstream arquivo("nomes.txt");
    string linha;

    if (arquivo.is_open())
    {
        while (getline(arquivo, linha))
        {
            vector<string> partes;
            stringstream ss(linha);
            string palavra;

            // Separar o nome completo em partes (nomes/sobrenome)
            while (ss >> palavra)
                partes.push_back(palavra);

            if (partes.size() == 0)
                continue;

            string sobrenome = partes.back();
            partes.pop_back(); // Remove o sobrenome da lista

            // Montar a string da referência
            string referencia = "";

            // Colocar o sobrenome em maiúsculas
            for (char& c : sobrenome)
                referencia += toupper(c);

            referencia += ", ";

            // Primeiro nome por extenso
            if (!partes.empty()) {
                referencia += partes[0] + " ";
            }

            // Demais nomes apenas com a inicial e ponto
            for (size_t i = 1; i < partes.size(); ++i) {
                referencia += toupper(partes[i][0]);
                referencia += ". ";
            }

            cout << referencia << endl;
        }

        arquivo.close();
    }
    else
    {
        cout << "O arquivo nomes.txt não existe na pasta atual." << endl;
    }

    return 0;
}
