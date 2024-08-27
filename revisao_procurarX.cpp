#include <iostream>
using namespace std;
const int N=100;
void adiciona(int v[N])
{
    for(int i=0; i<N; i++)
    {
        v[i]= 1+i;
    }
}
int busca(int x , int v[N])
{
    for(int i=0; i<100; i++)
    {
        if(v[i]==x)
            return i;
    }
    return -1;
}
int main()
{
    int x;
    int v[N];
    adiciona(v);
    cout << "Informe o x: ";
    cin >> x;
    cout << busca(x,v);

    return 0;
}
