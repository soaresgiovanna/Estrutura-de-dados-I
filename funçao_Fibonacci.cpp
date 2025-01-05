#include <iostream>
#include <ctime>
using namespace std;
unsigned long long Fibonacci(int n)
{
    if(n<2) return n;
    return Fibonacci(n-2) + Fibonacci(n-1);

}
int main()
{
    int n;
    double t;
    while (cin >> n)
{
    clock_t begin, end;
    begin=clock();
    Fibonacci(n);
    end = clock();
    t = double(end-begin)/CLOCKS_PER_SEC;
    cout << "Gastou " << t << " segundos" << endl;
}

    return 0;
}
