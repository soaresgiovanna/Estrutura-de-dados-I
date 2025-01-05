#include<iostream>
#include<cstring> // strlen
using namespace std;
int main()
{
    char *stringPtr, str[40];

    cout << "Entre com seu nome completo: ";
    cin.getline(str, 40);

    stringPtr = new (nothrow) char[strlen(str)+1]; // +1 para ‘\0’

    if(stringPtr)
    {
        int tam = strlen(str);
// copia caracteres de str para stringPtr,
// convertendo-os para maiúsculos
        for(int i=0; i<tam; i++)
            stringPtr[i] = toupper(str[i]);
        stringPtr[tam] = '\0';
        cout << "Nome completo: " << stringPtr;
        delete [] stringPtr;
    }
    else cout << "\nNão há memória suficiente para alocação!";
    return 0;
}
