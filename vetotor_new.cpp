#include <iostream>
using namespace std;

int main()
{
    int *arrayPtr, i, n;

    cout << "Entre com a quantidade de elementos do array: ";
    cin >> n;

    arrayPtr = new (nothrow) int[n];
    if(arrayPtr)
    {
        for(i=0; i<n; i++)
            arrayPtr[i] = 10*(i+1);
        cout << "\n";

        for(i=0; i<n; i++)
            cout << arrayPtr[i] << " ";
        delete [] arrayPtr;
    }
    else
        cout << "\nN�o h� mem�ria suficiente para aloca��o!";
    return 0;
}
