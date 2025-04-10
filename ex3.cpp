#include <iostream>
#include <fstream>
#include <locale.h>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    ifstream arquivo("nomes.txt");
    string nome;

    if (arquivo.is_open())
    {
        while (getline(arquivo, nome))
        {
            int posUltimoEspaco = nome.rfind(' ');

            if (posUltimoEspaco != string::npos)
            {
                string ultimoSobrenome = nome.substr(posUltimoEspaco + 1);
                string restoDoNome = nome.substr(0, posUltimoEspaco);
                cout << ultimoSobrenome << ", " << restoDoNome << endl;
            }
            else
            {
                // Caso só tenha um nome (sem espaços)
                cout << nome << endl;
            }
        }

        arquivo.close();
    }
    else
    {
        cout << "O arquivo nomes.txt não existe na pasta atual." << endl;
    }

    return 0;
}
