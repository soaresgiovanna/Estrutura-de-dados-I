#include <iostream>
using namespace std;
void ordena(int v[], int n)
{
    int indice;
    int menor,aux;
    for(int i=0; i<n; i++)
    {
        indice = i;
        menor = v[i];
        for(int j=i+1; j<n; j++)
        {
            if (menor > v[j])
            {
                menor=v[j];
                indice=j;
            }
        }
                aux=v[i];
                v[i]=v[indice];
                v[indice]=aux;
    }
}
void carrega(int v[], int n)
{
    cout << "Informe os " << n << " valores: ";
    for(int i=0; i<n; i++)
    {
        cin >> v[i];
    }
}
void imprime(int v[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Tamanho do vetor: ";
    while(cin>>n)
    {
        int v[n];
        carrega(v,n);
        ordena(v,n);
        imprime(v, n);
    }
    return 0;
}
