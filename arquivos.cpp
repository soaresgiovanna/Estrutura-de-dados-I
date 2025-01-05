#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("aleat_100000.txt");

    if (fin.is_open())
    {
        char linha[10];
        int vet[100000], i=0;
        while(fin.getline(linha, 10))
        {
            //cout << linha << endl;
            //system("pause");
            vet[i] = atoi(linha);
            i++;
        }
        fin.close();

        ofstream fout("resultados.txt");
        if(fout.is_open())
        {
            fout << "Resultados" << endl;
            for(int j=0; j<10; j++)
                fout << vet[j] << endl;
            fout.close();
        }
        else
            cout << "Não conseguiu abrir o arquivo de saída!";

    }
    else
        cout << "Não conseguiu abrir o arquivo de entrada!";
    return 0;
}
