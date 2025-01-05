#include <iostream>
using namespace std;

int main()
{
    int v[]= {10, 20, 30, 40, 50}; // v � um vetor de inteiros
    int *vPtr; // vPtr � um ponteiro para inteiro

    vPtr = &v[0]; // ou vPtr = v, pois o nome do vetor � o endere�o do primeiro elemento

    cout << "O valor de *vPtr � o mesmo que v[0], que �: " << *vPtr << "\n\n";
    cout << "Opera��o vPtr++..." << endl;

    vPtr++; // incrementa o ponteiro de 1 unidade (tamanho de um inteiro)
    cout << "O valor de *vPtr � o mesmo que v[1], que �: " << *vPtr <<"\n\n";

    cout << "Opera��o vPtr = vPtr + 2..." << endl;
    vPtr = vPtr + 2; // incrementa o ponteiro de 2 unidades (tamanho de 2 inteiros)
    cout << "O valor de *vPtr � o mesmo que v[3], que �: " << *vPtr <<"\n\n";

    cout << "Opera��o vPtr--" << endl;
    vPtr--; // decrementa em uma unidade o valor do ponteiro (tamanho de um inteiro)
    cout << "O valor de *vPtr � o mesmo que v[2], que �: " << *vPtr <<"\n\n";

    int *v2Ptr = &v[3];
    int q;
    q = v2Ptr - vPtr;
    cout << "Subtra��o entre dois ponteiros: v2Ptr - vPtr = " << q;
    return 0;
}
