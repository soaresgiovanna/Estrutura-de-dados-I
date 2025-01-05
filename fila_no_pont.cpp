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
class Fila
{
private:
    No* inicio;
    No* fim;
    int tamanhofila;
public:
    Fila();//inicio=fim=-1
    ~Fila();
    void enfilheira(int x);
    int desenfilheira();
    bool vazia();
    int tamanho();
    int primeiro();
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

// Métodos da classe Fila
Fila::Fila()
{
    inicio = 0;
}
bool Fila::vazia()
{
      return inicio == 0;
}
void Fila::enfilheira(int _chave)
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
        fim = novoNo;
    }
}
int Fila:: desenfilheira()
{
    if(vazia())
        cout << "Fila vazia!";
    else
    {
        No *noDesenfilheira = &inicio;
        inicio = inicio->getProx();
        return *noDesenfilheira;
    }
}
Fila::~Fila()//?? paa que serve o destrutor se n é cahamdo na main
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
    int numero;
   Fila* f = new Fila();
   cout << "Informe os numeros: ";
   while(cin >> numero)
    f->enfilheira(numero);

    while(!vazia())
        cout << f.desenfilheira();

   delete f;

   return 0;
}
