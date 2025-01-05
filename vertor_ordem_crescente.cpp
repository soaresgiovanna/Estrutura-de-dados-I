#include <iostream>
using namespace std;
void Ordena(int v[], int n)
{
    int aux, x;
    cout << "Informe os " << n << " valores: ";
    for(int i=0; i<n; i++)
    {
        aux=v[i]; //armazena o valor para n perder
        x=i;//valor a ser comparado
       while(x > 0 && v[x-1] > aux)//enqunto o indice existir e o indice abaixo dele ser maior que o valor comparado
       {
            v[x] = v[x-1];//passa o maior para traz
            x--;//diminui dm um o indice da proxima comparação
       }
      v[x] = aux;//ao final v[x], x é o indice do valor ordenado
    }
}
void imprime(int v[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << v[i] << " ";
    }
}
void carrega(int v[], int n)
{
    for(int i=0; i<n; i++)
        cin >> v[i];
}
int main()
{
    int n;
    cout << "Tamanho do vetor: ";
    while(cin>>n)
    {
        int* v = new int[n];
        carrega(v, n);
        Ordena(v, n);
        imprime(v, n);
    }
    return 0;
}
