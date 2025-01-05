#include <iostream>
using namespace std;

int main()
{
    int v[]= {10, 20, 30, 40, 50}; // v é um vetor de inteiros
    int *vPtr; // vPtr é um ponteiro para inteiro

    vPtr = &v[0]; // ou vPtr = v, pois o nome do vetor é o endereço do primeiro elemento

    cout << "O valor de *vPtr é o mesmo que v[0], que é: " << *vPtr << "\n\n";
    cout << "Operação vPtr++..." << endl;

    vPtr++; // incrementa o ponteiro de 1 unidade (tamanho de um inteiro)
    cout << "O valor de *vPtr é o mesmo que v[1], que é: " << *vPtr <<"\n\n";

    cout << "Operação vPtr = vPtr + 2..." << endl;
    vPtr = vPtr + 2; // incrementa o ponteiro de 2 unidades (tamanho de 2 inteiros)
    cout << "O valor de *vPtr é o mesmo que v[3], que é: " << *vPtr <<"\n\n";

    cout << "Operação vPtr--" << endl;
    vPtr--; // decrementa em uma unidade o valor do ponteiro (tamanho de um inteiro)
    cout << "O valor de *vPtr é o mesmo que v[2], que é: " << *vPtr <<"\n\n";

    int *v2Ptr = &v[3];
    int q;
    q = v2Ptr - vPtr;
    cout << "Subtração entre dois ponteiros: v2Ptr - vPtr = " << q;
    return 0;
}
