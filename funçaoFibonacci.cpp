#include <iostream>
#include <ctime>
using namespace std;
unsigned long long Fibonacci(int n)
{
    int x1=0, x2= 1, x3=1;
    for(int i=2; i<n ; i++)
     {
         x3=x1+x2;
         x1=x2;
         x2=x3;
     }
     return x3;
}
int main()
{
    int n;
    double t;
    while (cin >> n)
{
    clock_t begin, end;
    begin=clock();
    cout << Fibonacci(n) << endl;
    end = clock();
    t = double(end-begin)/CLOCKS_PER_SEC;
    cout << "Gastou " << t << " segundos" << endl;
}
    return 0;
}
