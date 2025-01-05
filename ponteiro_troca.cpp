#include <iostream>
using namespace std;
int troca(int *ap, int *bp)
{
    int aux;
    aux= *ap;
    *ap= *bp;
    *bp= aux;
}
int main()
{
   int a=1, b=2;
   troca(&a, &b);
   cout << a << " " << b << endl;

   return 0;
}
