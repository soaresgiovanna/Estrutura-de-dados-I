#include <iostream>
using namespace std;
 /*void carrega(int M[][], int n)
{
    for(int i=0; i<n; i++)
    {
        M[i][i]=i;
    }
} */
int somatorio(int M[][], int n)
{
 int s=0;
 for(int i=0; i< n; i++)
 s = s + M[i][i];
 return s;
}
int main()
{
    int n;
    while(cin >> n)
    {
        int M[n][n];
        //carrega(M, n);
        cout << somatorio(M, n);
    }

    return 0;
}
