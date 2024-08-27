#include <iostream>
using namespace std;
int MDC(int a, int b, int x)
{
    if(a%x ==0 && b%x ==0)
        {
            return x;
        }
    else
        MDC(a,b,x-1);
}
int main()
{
    int a, b, aux, x;
    cout << "Informe os dois valores: ";
    cin >> a >> b;
    x=a;
    if(a > b)
    {
        aux=a;
        a=b;
        b=aux;
    }
    cout << MDC(a, b, x);

    return 0;
}
