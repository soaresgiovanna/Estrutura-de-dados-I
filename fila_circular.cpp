#include <iostream>
using namespace std;
const int MAX=3;
class Fila
{
private:
    int inicio;
    int fim;
    int vet[MAX];//new??
    // int tamanho_fila;
public:
    Fila();//inicio=fim=-1
    bool enfilheira(int x);
    int desenfilheira();
    bool vazia();
    bool cheia();
    int tamanho();
    int primeiro();
};
Fila::Fila()
{
    inicio = fim = -1;
}
bool Fila::vazia()
{
    return inicio == -1;
}
bool Fila::cheia()
{
    return ((fim + 1) % MAX) == inicio;
}
bool Fila::enfilheira(int x)
{
    if(cheia()) return false;
    int nova_posicao = (fim+1)%MAX;
    //if(nova_posicao == inicio) vet[0]=x;
    fim = nova_posicao;
    vet[fim]=x;
    if(inicio == -1) inicio=0;
    return true;

}
int Fila:: desenfilheira()
{
    if(vazia()) return -1;
    else
    {
        int posicao_remover = inicio;
        if(inicio == fim)
        {
            inicio= -1;
            fim = -1;
        }
        else inicio = (inicio+1)%MAX;
        return vet[posicao_remover];
    }
}
int main()
{
    Fila f;
    int numero;
    cout << "Informe os " << MAX << " numeros: ";
    for(int i=0; i<MAX; i++)
    {
        cin >> numero;
        f.enfilheira(numero);
    }
    //imprimir lista
    cout << "Desenfileirando: " << f.desenfilheira() << endl;
    //imprimir lista
    return 0;
}

