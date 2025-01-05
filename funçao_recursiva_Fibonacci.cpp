#include <iostream>
#include <ctime>
using namespace std;
unsigned long long Fibonacci(int n)
{
    if(n<2) return n;
    return Fibonacci(n-2) + Fibonacci(n-1);

    clock_t begin, end;
    begin=clock();
    f(n);
    end = clock();
    t = double(end-begin)/CLOCKS_PER_SEC;
    cout << "Gastou " << t << " segundos" << endl
}
int main()
{
   int n;
   cin >> n;
   Fibonacci(n);

   return 0;
}
