// Lista simplesmente encadeada com ponteiro apenas para o início da lista
// Claudia Akemi Izeki
// 02/10/2023

#include<iostream>
using namespace std;

class No{
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

class Lista{
    private:
        No* inicio;
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
}
No::No(int _chave)
{
    chave = _chave;
    prox = 0;
}
int No::getChave()
{
    return chave;
}
No* No::getProx()
{
    return prox;
}
void No::setChave(int _chave)
{
    chave = _chave;
}
void No::setProx(No* _prox)
{
    prox = _prox;
}

// Métodos da classe Lista
Lista::Lista()
{
    inicio = 0;
}
bool Lista::vazia()
{
    return inicio == 0;
}
void Lista::insere_inicio(int _chave)
{
    No* novoNo = new No(_chave);

    if(vazia())
        inicio = novoNo;
    else{
        novoNo->setProx(inicio);
        inicio = novoNo;
    }
}
void Lista::imprime()
{
    No* aux = inicio;

    while(aux)
    {
        cout << aux->getChave() << " ";
        aux = aux->getProx();
    }
}
void Lista::insere_fim(int _chave)
{
    No* novoNo = new No(_chave);

    if(vazia())
        inicio = novoNo;
    else{
        No* aux = inicio;

        while(aux->getProx())
            aux = aux->getProx();

        aux->setProx(novoNo);
    }
}
void Lista::remove_inicio()
{
    if(vazia())
        cout << "Lista vazia!";
    else{
        No* noARemover = inicio;
        inicio = inicio->getProx();
        delete noARemover;
    }
}
void Lista::remove_fim()
{
    if(vazia())
        cout << "Lista vazia!";
    else{

        No* noARemover = inicio;
        No* ant = 0;

        while(noARemover->getProx())
        {
            ant = noARemover;
            noARemover = noARemover->getProx();
        }
        if (ant)
            ant->setProx(0);
        else
            inicio = 0;
        delete noARemover;
    }
}
void Lista::remove_qq(int _chave)
{
    if(vazia())
        cout << "\nLista vazia!";
    else
    {
        bool achou = false;
        No* noARemover = inicio;
        No* ant = 0;

        while(noARemover && !achou)
        {
            if(noARemover->getChave() == _chave)
            {
                achou = true;
                if(ant)
                    ant->setProx(noARemover->getProx());
                else
                    inicio = inicio->getProx();
                delete noARemover;
                noARemover = 0;
            }
            else
            {
                ant = noARemover;
                noARemover = noARemover->getProx();
            }
        }
        if(!achou)
            cout << "\nChave nao encontrada!\n";
    }
}
void Lista::insere_ordenado(int _chave)
{
    No *novoNo = new No(_chave);

    No *ant = 0;
    No *proxNovo = inicio;

    while(proxNovo && proxNovo->getChave()<_chave)
    {
        ant = proxNovo;
        proxNovo = proxNovo->getProx();
    }

    if(ant)
    {
        ant->setProx(novoNo);
        novoNo->setProx(proxNovo);
    }
    else
    {
        novoNo->setProx(inicio);
        inicio = novoNo;
    }

}
Lista::~Lista()
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
