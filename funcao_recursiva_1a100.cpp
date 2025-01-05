#include <iostream>
using namespace std;
void imprime(int n)
{
    if(n > 0)
    {
        cout << n << " ";
        imprime(n-1);
    }
}
int main()
{
    int n=100;
    imprime(n);
    return 0;
}
