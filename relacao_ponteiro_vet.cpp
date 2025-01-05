
#include <iostream>
using namespace std;

int main()
{
    int v[]= {10, 20, 30, 40, 50}, i, offset;
    int *vPtr; // vPtr é um ponteiro para inteiro

    vPtr = &v[0]; // ou vPtr = v, pois o nome do vetor é o endereço do primeiro elemento

    cout << "Array v impresso com:\n" << endl;
    cout << "\nNotação de subscrito com array\n";
    for(i=0; i<5; i++)
        cout << "v[" << i << "]: " << v[i] << endl;

    cout << "\nNotação de ponteiro/deslocamento com\n" << "o nome do array como ponteiro\n";
    for(offset=0; offset<5; offset++)
        cout << "*(v+" << offset << "): " << *(v+offset) << endl;

    cout << "\nNotação de subscrito com ponteiro\n";
    for(i=0; i<5; i++)
        cout << "vPtr[" << i << "]: " << vPtr[i] << endl;

    cout << "\nNotação de ponteiro/deslocamento com um ponteiro\n";
    for(offset=0; offset<5; offset++)
        cout << "*(vPtr+" << offset << "): " << *(vPtr+offset) << endl;
    return 0;
}
