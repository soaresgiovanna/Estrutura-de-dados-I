#include <iostream>
using namespace std;

const int n = 5;
void carrega(int M[n][n])
{
    for(int i=0; i<n; i++)
    {
        M[i][i]=i;
    }
}
int somatorio(int M[n][n])
{
    int s=0;
    for(int i=0; i< n; i++)
        s = s + M[i][i];
    return s;
}
int main()
{
        int M[n][n];
        carrega(M);
        cout << somatorio(M);

    return 0;
}
