#include <iostream>
using namespace std;

int main()
{
    int *intPtr;

// tenta alocar mem�ria para 1 inteiro e retorna
// o endere�o inicial da mem�ria alocada
    intPtr = new (nothrow) int();
    if(intPtr)  // se alocou
    {
        *intPtr = 10;
        cout << *intPtr;
        delete intPtr; // liberando a mem�ria alocada
    }
    else cout << "N�o h� mem�ria suficiente para aloca��o!";
    return 0;
}
