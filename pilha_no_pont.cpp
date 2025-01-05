#include<iostream>
using namespace std;
class No
{
private:
    int chave;
    No* prox;
public:
    No();
    No(int _chave);
    int getChave();
    No* getProx();
    void setChave(int _chave);
    void setProx(No* _prox);
};
class Pilha
{
private:
    No* topo;
    int tamanhoPilha;
public:
    Pilha();
    ~Pilha();
    void empilha(int chave)
    int desempilha();
    bool vazia();
    int tamanho();
    int consultaTopo();
};
