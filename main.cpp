#include <iostream>
#include <fstream>
using namespace std;
/*dou um núymero e ele me devolve o número do número no ASCII*/

int main()
{
    string nomeArqIn, nomeArqOut;
    cout << "Qual o nome do arquivo de entrada?\n";
    cin >> nomeArqIn;
    cout << "Qual o nome do arquivo de saída?\n";
    cin >> nomeArqOut;
    cout << "Qual o número da chave";
    int chave;

    cin >> chave;
    string linha;

    ifstream arq(nomeArqIn + ".txt");
    ofstream arq2;
    arq2.open(nomeArqOut + ".txt");
    if (arq.is_open())
    {
        while (getline(arq, linha))
        {
            cout << linha << endl;
            for (auto i : linha)
            {
                if ((i <= 'Z' && i >= 'A') || (i <= 'z' && i >= 'a'))
                {
                    if ((((i + chave) <= 'Z' && (i + chave) >= 'A') || ((i + chave) <= 'z' && (i + chave) >= 'a')))
                    {
                        /*se não precisar rotacionar*/
                        arq2 << char(i + chave);
                    }
                    else if (i + chave > 'Z')
                    { /*rotacionando nos maiúsculos*/
                        arq2 << char('A' + chave - 1);
                    }
                    else if (i + chave > 'z')
                    { /*rotacionando nos minúsculos*/
                        arq2 << char('a' + chave - 1);
                    }
                }
                else
                {
                    arq2 << i;
                }
            }
        }
    }

    return 0;
}
