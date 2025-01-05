#include <iostream>
using namespace std;

int main()
{
    int *intPtr;

// tenta alocar memória para 1 inteiro e retorna
// o endereço inicial da memória alocada
    intPtr = new (nothrow) int();
    if(intPtr)  // se alocou
    {
        *intPtr = 10;
        cout << *intPtr;
        delete intPtr; // liberando a memória alocada
    }
    else cout << "Não há memória suficiente para alocação!";
    return 0;
}
