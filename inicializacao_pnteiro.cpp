#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int *x = &a;

    int *y = new (nothrow) int();
    if(!y) cout << "Erro na alocação";
    else cout << "Alocou" << endl;

    int *z = new (nothrow) int[10];
    if(!z) cout << "Erro na alocação";
    else cout << "Alocou";

    return 0;
}
