#include <iostream>
#include <cmath>
using namespace std;
int eleva(int X, int n)
{
    if(n==0)
    {
      return 1;
    }
    else if(n > 0)
    {
       return pow(X, n)*eleva(X, n-1);
    }
    else
        cout << "Informe um expoente positivo";

}
int main ()
{setlocale (LC_ALL, "Portuguese");
  int X, n;
  cout << "Informe o n�mero e em seguida o expoente: ";
  cin >> X >> n;
  cout << eleva(X, n);

  return 0;
}
