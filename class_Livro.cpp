#include<iostream>
#include<cstring>
using namespace std;

class Livro
{
private:
    char *titulo;
    char *autor;
    int ano;
public:
    //constrotor padrão
    Livro()
    {
        titulo = 0;
        autor = 0;
        ano = 0;
    }
    //construtor com parametros
    Livro(char _titulo[], char _autor[], int _ano)
    {
        ano= _ano;

        titulo = new char[strlen(_titulo)+1];
        strcpy(titulo, _titulo);

        autor = new char[strlen(_autor)+1];
        strcpy(autor, _autor);
    }
    //metodos set e get
    void settitulo(char _titulo[])
    {
        delete [] titulo;
        titulo = new char[strlen(_titulo)+1];
        strcpy(titulo, _titulo);
    }
    void setautor(char _autor[])
    {
        delete [] autor;
        autor = new char[strlen(_autor)+1];
        strcpy(autor, _autor);
    }
    void setano(int _ano)
    {
        ano = _ano;
    }
    char *gettitulo()
    {
        return titulo;
    }

    char *getautor()
    {
        return autor;
    }
    int getano()
    {
        return ano;
    }
    ~Livro()//destrutor
    {
        delete [] titulo;
        titulo = 0;
        delete [] autor;
        autor = 0;
    }
};
int main()
{
      Livro *livroDois = new (nothrow) Livro ("titulodois", "autordois", 2002);
    if(livroDois)
    {
        cout << endl << livroDois->gettitulo();
        cout << endl << livroDois->getautor();
        cout << endl <<livroDois->getano();
        delete livroDois;
    }
    else cout << "Não foi possível alocar memória!";

    Livro *livroUm = new(nothrow) Livro();
    if(livroUm)
    {
        livroUm->setautor("autorUm");
        livroUm->settitulo("tituloUm");
        livroUm->setano(2001);
        cout << endl << livroUm->getautor();
        cout << endl << livroUm->gettitulo();
        cout << endl << livroUm->getano();

        delete livroUm;
    }
    else cout << "Não foi possível alocar na memória";
    return 0;
}
