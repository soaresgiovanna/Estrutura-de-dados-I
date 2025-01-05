#include <iostream>
using namespace std;
void imprime(int v[], int n)
{
     for(int i=0; i<n; i++)
        cout << v[i] << " ";
}
void carrega(int v[], int n)
{
    cout<< "Informe os " << n << " valores: ";
    for(int i=0; i<n; i++)
        cin >> v[i];
}
int main()
{
    int n, aux;

    cout << "Informe o tamanho vetor: ";
    while(cin >> n)
    {
        int v[n];
        carrega(v, n);
        for(int i=0; i<n-1; i++)
            if(v[i] >v[i+1])
             {
               aux= v[i];
               v[i] = v[i+1];
               v[i+1] = aux;
             }
        imprime(v, n);
    }
    return 0;
}
