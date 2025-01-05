#include <fstream> // inclus�o da biblioteca fstream - para entrada de arquivo
#include <iostream>
using namespace std;
const int N=100000;
bool verificaCrescAleat(valores v[N]) //verifica se esta crescente o aleat�rio
{
    for(int i=0; i<(N-1); i++)
    {
       if(v[i].aleatorio > v[i+1].aleatorio)
        return false;
    }
    return true;
}
bool verificaDecresAleat(valores v[N]) //verifica se esta decrescente o aleat�rio
{
    for(int i=0; i<(N-1); i++)
    {
       if(v[i].aleatorio< v[i+1].aleatorio)
        return false;
    }
    return true;
}
bool verificaDecresOCrescent(valores v[N])//verifica se est� decrescnte o crescente
{
    for(int i=0; i<(N-1); i++)
    {
       if(v[i].crescente < v[i+1].crescente)
        return false;
    }
    return true;
}
bool verificaCrescODecrescent(valores v[N]) //verifica se esta crescente o decrescente
{
    for(int i=0; i<(N-1); i++)
    {
       if(v[i].decrescente > v[i+1].decrescente)
        return false;
    }
    return true;
}
void bubblesort()
{
    for(int i = 0; i < n - 1; i++)
       for( int j = 0; j < n-i-1; j++)
        if( v[j] > v[j+1])
        {
            int  aux = v[j];
            v[j] = v[j+1];
            v[j+1] = aux;
        }
}
void bubblesortmelhorado()// o m�todo bubble sort melhorado possui duas funionalidades diferenciais
{  bool swapped;
for(int i = 0; i < n - 1; i++)
    {
    swapped = false; // swapped = false garante que os valores permane�am inalterados
    for( int j = 0; j < n-i-1; j++)
        {
        if( v[j] > v[j+1])
        {
            swap(v[j], v[j+1]); // reduz o tamanho do c�digo facilitando a leitura
           swapped = true;
        }
        }
    }
}
void selectionsort()
{
int menor;
bool swapped;
// utilizaremos da tecnica swap para:
// reduzir o tamanhp do c�digo e aumentar efici�ncia
for ( int i = 0; i < n; i ++)
{
    menor = i;
    swapped = false;
    for( int j = i + 1; j < n; j++)
    {
        menor = j;
        if (v[j] < v[menor])
        {
            swap(v[j],v[menor]);
            swapped = true;
        }
    }
}
}
void insertionsort()
{
int menor;
for ( int i = 0; i < n; i++){
    menor = v[i];
    j = i - 1;
    while( j >= 0 && v[j]> menor){


        v[j+1] = v[j];
        j = j - 1;
                }
v [j+1] = menor;
}
}
void quicksort()
{
}
int funcoesdisponiveis(int n)
{
cout << " 1 - bubble sort: " << endl;
cout << "2 - bubble sort melhorado: " << endl;
cout << "3 - selecion sort: " << endl;
cout << " insertion sort: " << endl;
cout << " 5 - quick sort: " << endl;
cin >> n;
return n;
}

bool carregarquivo2 (ifstream& arquivo2, valores& c) //passa do arquivo para o registro
{
    char linha[7];
    if (arquivo2.getline(linha, 7))//l� a linha de no max 7 caracteres
    {
        int i = 0;
        char aux[7];

        escrevelinha(linha, aux, i);
        c.crescente = atoi(aux);

        return true; //confere se deu certo
    }
    return false; //ou n�o
}
bool carregarquivo1 (ifstream& arquivo1, valores& a) //passa do arquivo para o registro
{
    char linha[7];
    if (arquivo1.getline(linha, 7))//l� a linha de no max 7 caracteres
    {
        int i = 0;
        char aux[7];

        escrevelinha(linha, aux, i);
        a.aleatorio = atoi(aux);

        return true; //confere se deu certo
    }
    return false; //ou n�o
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    valores aleat[N];
    valores cresc[N];
    valores decresc[N];
    int n;

    if(aleatorio.is_open() && crescente.is_open() && decrescente.is_open())//verifica se os arquivos faram abertos
    {
        for(int i=0; i<N; i++)
        {
            if(carregarquivo1(aleatorio, aleat[i])) continue;
            else cout << "N�o carregou o registro da linha " << i << " do arq. aleat�rio ";
        }
        aleatorio.close();

        for(int i=0; i<N; i++)
        {
            if(carregarquivo2(crescente, cresc[i])) continue;
            else cout << "N�o carregou o registro da linha " << i << " do arq. crescente ";
        }
        crescente.close();
        for(int i=0; i<N; i++)
        {
            if(carregarquivo3(decrescente, decresc[i])) continue;
            else cout << "N�o carregou o registro da linha " << i << " do arq. decrescente ";
        }
        decrescente.close();

        cout << "escolha uma op��o de ordena��o; "; // mostrar para usu�rio op��es de ordena��o dos dados

        switch(funcoesdisponiveis(n))  // estrtura condional para execu��o das fun��es
        {
        case 1:
            cout << " a op��o escolhida � bubble sort";
                 bubblesort(); // chama fun��o bubble sort
            break;

        case 2:
            cout << " a op��o escolhida � bubble sort melhorado";
                 bubblesortmelhorado();  // chama fun��o bubble sort melhorado
            break;

        case 3:
            cout << " a op��o escolhida � selection sort";
                 selectionsort(); // chama fun��o selection sort
            break;

        case 4:
            cout << " a op��o escolhida � insertion sort";
                 insertionsort(); // chama fun��o insertion sort
            break;

        case 5:
            cout << " a op��o escolhida � quick sort";
                 quicksort();  // chama fun��o quick   sort
           break;

        default:
            cout << " ERRO! digite um n�mero inv�lido";
                 break;
        }

// ofstream retirada de dados



    }
    else cout << "N�o foi poss�vel abrir o arquivo de entrada" << endl;

    return 0;
}
