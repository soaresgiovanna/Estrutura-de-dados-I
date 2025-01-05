#include <iostream>
using namespace std;
int main()
{
    float x; // x é uma variável do tipo float
    float *xPtr; // xPtr é um ponteiro para um float

    x = 10.0;
    xPtr = &x; // xPtr recebe o endereço de x

    cout << "O valor de x é: " << x << endl;
    cout << "O endereço de x é: " << &x << endl;
    cout << "O valor de xPtr é: " << xPtr << " que é o mesmo endereço de x" << endl;
    cout << "O valor de *xPtr é " << *xPtr << " que é o mesmo valor de x" << endl;
    cout << "O endereço de xPtr é: " << &xPtr;
    return 0;
}
