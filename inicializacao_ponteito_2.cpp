#include <iostream>
using namespace std;
int main()
{
    float x; // x � uma vari�vel do tipo float
    float *xPtr; // xPtr � um ponteiro para um float

    x = 10.0;
    xPtr = &x; // xPtr recebe o endere�o de x

    cout << "O valor de x �: " << x << endl;
    cout << "O endere�o de x �: " << &x << endl;
    cout << "O valor de xPtr �: " << xPtr << " que � o mesmo endere�o de x" << endl;
    cout << "O valor de *xPtr � " << *xPtr << " que � o mesmo valor de x" << endl;
    cout << "O endere�o de xPtr �: " << &xPtr;
    return 0;
}
