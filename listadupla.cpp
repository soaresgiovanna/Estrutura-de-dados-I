// Lista simplesmente encadeada com ponteiro apenas para o início da lista
// Claudia Akemi Izeki
// 02/10/2023

//copiar

#include<iostream>
using namespace std;
class No
{
private:
    int chave;
    No* prox;
    No* ant;
public:
    No();
    No(int _chave);
    int getChave();
    No* getProx();
    No* getAnt();
    void setChave(int _chave);
    void setProx(No* _prox);
    void setAnt(No* _ant);
};

class Lista
{
private:
    No* inicio;
    No* fim;
public:
    Lista();
    void insere_inicio(int _chave);
    void insere_ordenado(int _chave);
    void insere_fim(int _chave);
    void remove_inicio();
    void remove_fim();
    void remove_qq(int _chave);
    void imprime();
    bool vazia();
    ~Lista();
};
// Métodos da classe No
No::No()
{
    chave = 0;
    prox = 0; // NULL
    ant = 0;
}
No::No(int _chave)//O(1)
{
    chave = _chave;
    prox = 0;
    ant = 0;
}
int No::getChave()//O(1)
{
    return chave;
}
No* No::getProx()//O(1)
{
    return prox;
}
No* No::getAnt()//O(1)
{
    return ant;
}
void No::setChave(int _chave)//O(1)
{
    chave = _chave;
}
void No::setProx(No* _prox)//O(1)
{
    prox = _prox;
}
void No::setAnt(No* _ant)//O(1)
{
    ant = _ant;
}
// Métodos da classe Lista
Lista::Lista()
{
    inicio = 0;
    fim = 0;
}
bool Lista::vazia()//O(1)
{
    return inicio == 0;
}
void Lista::insere_inicio(int _chave)//O(1)
{
    No* novoNo = new No(_chave);

    if(vazia())
    {
        inicio = novoNo;
        fim = novoNo;
    }
    else
    {
        novoNo->setProx(inicio);
        inicio->setAnt(novoNo);
        inicio = novoNo;
    }
}
void Lista::imprime()//O(n)
{
    No* aux = inicio;

    while(aux)
    {
        cout << aux->getChave() << " ";
        aux = aux->getProx();
    }
}
void Lista::insere_fim(int _chave)//O(1)
{
    No* novoNo = new No(_chave);

    if(vazia())
    {
        inicio = novoNo;
        fim = novoNo;
    }
    else
    {
        fim->setProx(novoNo);
        novoNo->setAnt(fim);
        fim = novoNo;
    }
}
void Lista::remove_inicio()//O(1)
{
    if(vazia())
        cout << "Lista vazia!";
    else
    {
        No* noARemover = inicio;
        inicio = inicio->getProx();
        delete noARemover;
    }
}
void Lista::remove_fim()//O(1)
{
    if(vazia())
        cout << "Lista vazia!";
    else
    {
        No* noARemover = fim;
        fim =fim->getAnt();
        delete noARemover;
    }
}
void Lista::remove_qq(int _chave)//O(1), melhor caso, O(n) pior caso
{
    if(vazia()) cout << "\nLista vazia!";
    else
    {
        bool achou = false;
        No* noARemover = inicio;
        No* ant = 0;
        No* fim = fim;

        while(noARemover && !achou)
        {
            if(noARemover->getChave() == _chave)
            {
                achou = true;
                if(ant)
                {
                    if(noARemover->getProx())
                    {
                        ant->setProx(noARemover->getProx());
                        (noARemover->getProx())->setAnt(ant);
                    }
                    else remove_fim();
                }
                else inicio = inicio->getProx();

                delete noARemover;
                noARemover = 0;
            }
            else
            {
                ant = noARemover;
                noARemover = noARemover->getProx();
                ant->setProx(noARemover);
                noARemover->setProx(ant);
            }
        }
        if(!achou)
            cout << "\nChave nao encontrada!\n";
    }
}
void Lista::insere_ordenado(int _chave)//O(1), melhor caso, O(n) pior caso
{
    No *novoNo = new No(_chave);
    No *ant = 0;
    No *proxNovo = inicio;
    No *fim = fim;

    while(proxNovo && proxNovo->getChave() <_chave)
    {
        ant = proxNovo;
        proxNovo = proxNovo->getProx();
    }

    if (ant)
{
    ant->setProx(novoNo);
    novoNo->setAnt(ant);
    novoNo->setProx(proxNovo);

    if (proxNovo)
    {
        proxNovo->setAnt(novoNo);
    }
    else
    {
        fim = novoNo; // New node is now the last node
    }
}
else
{
    novoNo->setProx(inicio);
    if (inicio)
    {
        inicio->setAnt(novoNo);
    }
    inicio = novoNo;
}

}
Lista::~Lista()//O(n)
{
    No* aux;

    while(inicio)
    {
        aux = inicio;
        inicio = inicio->getProx();
        delete aux;
    }
}
int main()
{
    Lista* l = new Lista();

    // Você pode incluir um menu de opções aqui para testar melhor os métodos da classe Lista

    l->insere_ordenado(10);
    l->insere_ordenado(5);
    l->insere_ordenado(35);
    l->remove_qq(50);
    l->remove_qq(35);
    l->remove_qq(10);

    l->insere_ordenado(45);

    l->imprime();

    delete l;

    return 0;
}
