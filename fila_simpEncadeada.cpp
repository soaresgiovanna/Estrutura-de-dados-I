#include <iostream>
using namespace std;
class Fila
{
private:
    No* inicio;
    No* fim;
    int tamanho_fila;
public:
    Fila();//inicio=fim=-1
    ~Fila();
    bool vazia();
    void enfilheira(int x);
    int desenfilheira();
    int tamanho();
    int primeiro();

bool Fila::vazia()
{
    if(inicio == -1 && fim == -1)
        return true;
}
void Fila::enfilheira(int x)
{
      int nova_posicao = (fim+1)%MAX;
    if(nova_posicao == inicio) return true;
    else
    {
        fim = nova_posicao;
        vet[fim]=x;
        if(inicio == -1) inicio=0;
        return true;
    }
}
int Fila::desenfilheira()
{
 if(vazia()) return true;
    else
    {
        int posicao_remover = inicio;
        if(inicio == fim)
        {
            inicio= -1;
            fim = -1;
        }
        else inicio = (inicio+1)%MAX;
        return posicao_remover;
    }
}
int Fila::tamanho()
{

}
int Fila::primeiro()
{
    return inicio;
}

};
