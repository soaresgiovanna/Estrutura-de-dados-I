//Realize o rastreio, 14/10/2024
#include<iostream>
#include<cstring>
using namespace std;
void Lista::insere_ordena(int _chave)
{
    No* novoNo = new No(_chave);
    if (vazia())
        inicio = novoNo;
    else
    {
        No *ant =0;
        No *proxNovo =inicio;
        while(proxNovo && proxNovo-> getChave()<_chave)
        {
            ant = proxNovo;
            proxNovo =
        }
    }
}
