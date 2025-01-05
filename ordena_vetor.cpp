#include <iostream>
using namespace std;
void ordena(int v[], int n)
{
    int aux;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(v[i]<v[j])
            {
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
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
