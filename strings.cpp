#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
    string texto;

    texto = "aleat_100000.txt\n\n";

    texto += "bubblesort\n";

    double tempo = 0.00124;

    texto += to_string(tempo);

    texto += " segundos\n";

    cout << texto;

    cout << endl;
    return 0;
}
