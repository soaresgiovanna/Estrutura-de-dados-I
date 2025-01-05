#include <iostream>
using namespace std;
void entrada(int v[], int n)
{
    cout << "Informe os " << n << " elementos que serão organizados em ordem crescente: ";
    for(int i=0; i<n; i++)
    {
        cin >> v[i];
    }
}
void qs(int *v, int left, int right)
{
    int pivo= v[(left+right)/2]; //pivo = meio
    int i=left; // primeiro termo
    int j=right; // ultimo termo
    int aux;

    do{
            while(v[i]<pivo) i++; //enqunto o vetor da esquerda for menor que o meio mostre o proximo
            while(v[j]>pivo) j--; //enqunto o vetor da direita for maior que o meio mostre o proximo

           if(i<=j)
           {
            int aux=v[i]; //troca o i pelo j, pois eles estão no lado errado
            v[i]=v[j];
            v[j]=aux;
            i++; //para comparar o proximo i;
            j--; // para comparar o proximo j;
           }

    }while(i<=j);
    if(left<j) qs(v, left, j); // se o j n chegou ate o inicio chame a funcao dnv e a direita sera o novo valor j
    if(i< right) qs(v, i, right); //mesmo raciocínio só que o contrario
}
int main()
{
    int n;
    cout << "Informe o tamanho do vetor: ";
    cin >> n;
    int* v = new int[n];
    entrada(v, n);
    int left=0;
    int right=(n-1);
    qs(v, left, right);
    for(int i=0; i<n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}
