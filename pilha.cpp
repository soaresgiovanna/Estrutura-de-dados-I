#include <iostream>
using namespace std;
const int MAX=3;
class Pilha
{
private:
    int v[MAX];
    int topo;
public:
    Pilha();//topo=-1
    bool empilha(int chave);
    int desempilha();
    int consultaTopo();
    bool cheia();
    bool vazia();
};
bool empilha(int chave)
{
  int nova_posicao = (fim+1)%MAX;
    if(nova_posicao == inicio)
        vet[0]=chave;
    else
    {
        fim = nova_posicao;
        vet[fim]= chave;
        if(inicio == -1) inicio=0;
        return true;
    }
}
int Pilha::desempilha()
{
    //remove fim
    if(vazia()) return 0;
    else
    {
        return fim;
        fim = v[]

    }
}
int Pilha::consultaTopo()
{
    if(vazia()) cout << "Lista vazia" << endl;
    else
    {
        return topo;
    }
}
bool Pilha::cheia()
{
  return fim == v[MAX-1];
}
bool Pilha::vazia()
{
    return inicio == -1 && fim == -1;
}
int main()
{

    return 0;
}
