//Giovanna Maira Soares Chaves, 2024005472, 25/11/2024
// O código a seguir ...

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Book
{
private:
    char* ISBN;
    char* title;
    char* author;
    int yearOfPublication;
    char* publisher;
    Book* prox; // Encadeamento

public:
    // Construtor e Destrutor
    Book();
    ~Book();

    // Getters
    char* get_ISBN();
    char* get_title();
    char* get_author();
    int get_yearOfPublication();
    char* get_publisher();
    Book* get_prox();

    // Setters
    void set_ISBN(char* _ISBN);
    void set_title(char* _title);
    void set_author(char* _author);
    void set_yearOfPublication(int _year);
    void set_publisher(char* _publisher);
    void set_prox(Book* _prox);

    // Método de impressão
    void print();
};

Book::Book() {
    ISBN = 0;
    title = 0;
    author = 0;
    publisher = 0;
    yearOfPublication = 0;
    prox = 0;
}

Book::~Book() {
    delete[] ISBN;
    ISBN = 0;
    delete[] title;
    title = 0;
    delete[] author;
    author = 0;
    delete[] publisher;
    publisher = 0;
}

char* Book::get_ISBN() {
    return ISBN;
}

char* Book::get_title() {
    return title;
}

char* Book::get_author() {
    return author;
}

int Book::get_yearOfPublication() {
    return yearOfPublication;
}

char* Book::get_publisher() {
    return publisher;
}

Book* Book::get_prox() {
    return prox;
}

void Book::set_ISBN(char* _ISBN) {
    delete[] ISBN;
    ISBN = new char[strlen(_ISBN) + 1];
    strcpy(ISBN, _ISBN);
}

void Book::set_title(char* _title) {
    delete[] title;
    title = new char[strlen(_title) + 1];
    strcpy(title, _title);
}

void Book::set_author(char* _author)
 {
    delete[] author;
    author = new char[strlen(_author) + 1];
    strcpy(author, _author);
}

void Book::set_yearOfPublication(int _year) {
    yearOfPublication = _year;
}

void Book::set_publisher(char* _publisher) {
    delete[] publisher;
    publisher = new char[strlen(_publisher) + 1];
    strcpy(publisher, _publisher);
}

void Book::set_prox(Book* _prox) {
    prox = _prox;
}

void Book::print() {
    cout << "ISBN: " << (ISBN ? ISBN : "N/A") << endl// se isbn for verdadeiro, imprime, senão N/A
         << "Title: " << (title ? title : "N/A") << endl
         << "Author: " << (author ? author : "N/A") << endl
         << "Year of Publication: " << yearOfPublication << endl
         << "Publisher: " << (publisher ? publisher : "N/A") << endl;
    cout << endl;
}

class Lista {
private:
    Book* inicio;
    Book* fim;
    int tamanho_lista;

public:
    Lista();
    ~Lista();
    int get_tamanho();
    void insere_fim(Book* p);
    bool vazia();
    void imprime();
    Book* procura(char* str);
};

Lista::Lista() {
    inicio = 0;
    fim = 0;
    tamanho_lista = 0;
}

Lista::~Lista() {
    Book* aux = inicio;
    while (aux) {
        inicio = inicio->get_prox();
        delete aux;
        aux = inicio;
    }
}

int Lista::get_tamanho() {
    return tamanho_lista;
}

void Lista::insere_fim(Book* b) {
    if (vazia())
    {
        inicio = b;
        fim = b;
    } else {
        fim->set_prox(b);
        fim = b;
    }
    tamanho_lista++;
}

bool Lista::vazia() {
    return inicio == 0;
}

void Lista::imprime() {
    if (vazia()) cout << "Lista vazia!" << endl;
    else {
        Book* atual = inicio;
        while (atual) {
            atual->print();
            atual = atual->get_prox();
        }
    }
}

Book* Lista::procura(char* str) {
    Book* aux = inicio;
    while (aux) {
        if (strcmp(aux->get_ISBN(), str) == 0)
            return aux;
        aux = aux->get_prox();
    }
    return 0;
}

class Hashing {
private:
    Lista** vet;
    int tamanho_tabela;
    int quant_colisoes;

public:
    Hashing(int _tam);
    ~Hashing();
    int get_tamanho();
    int f(char* str);
    void insere(Book* b);
    void imprime();
    int get_quantColisoes();
    void consulta(char* str);
};

Hashing::Hashing(int _tam) {
    tamanho_tabela = _tam;
    vet = new Lista * [tamanho_tabela];
    for (int i = 0; i < tamanho_tabela; ++i)
        vet[i] = new Lista();
    quant_colisoes = 0;
}

Hashing::~Hashing() {
    for (int i = 0; i < tamanho_tabela; ++i) {
        delete vet[i];
    }
    delete[] vet;
}

int Hashing::get_tamanho() {
    return tamanho_tabela;
}

int Hashing::f(char* str) {
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash = (hash * 31 + str[i]) % tamanho_tabela;
    }
    return hash;
}

void Hashing::insere(Book* b) {
    int index = f(b->get_ISBN());
    if (vet[index]->vazia()) {
        vet[index]->insere_fim(b);
    } else {
        quant_colisoes++;
        vet[index]->insere_fim(b);
    }
}

void Hashing::imprime()//erro
{
    for (int i = 0; i < tamanho_tabela; ++i)
    {
        if (!vet[i]->vazia())
        {
            cout << "Indice " << i << ": ";
            vet[i]->imprime();
        }
    }
}
int Hashing::get_quantColisoes()
{
    return quant_colisoes;
}

void Hashing::consulta(char* str)
{
    int index = f(str);
    Book* b = vet[index]->procura(str);
    if (b) {
        cout << "Livro encontrado: " << endl;
        b->print();
    } else {
        cout << "Livro não encontrado." << endl;
    }
}

class Arquivo {
private:
    char* nome_arquivo;
    void substring(char* linha, char* aux, int& i, char delim);
    void separa_atributos(char* linha, Book* b);

public:
    Arquivo(char* _nome_arquivo);
    ~Arquivo();
    bool carrega_csv(Hashing* h);
};

Arquivo::Arquivo(char* _nome_arquivo) {
    nome_arquivo = new char[strlen(_nome_arquivo) + 1];
    strcpy(nome_arquivo, _nome_arquivo);
}

Arquivo::~Arquivo()
{
    delete[] nome_arquivo;
}

void Arquivo::substring(char* linha, char* aux, int& i, char delim) {
    int k = 0;
    if (linha[i] == '\"') {
        delim = '\"';
        i++;
    }
    while (linha[i] != delim) {
        aux[k] = linha[i];
        i++;
        k++;
    }
    aux[k] = '\0';
    i++;
}

void Arquivo::separa_atributos(char* linha, Book* b) {
    char aux[500];
    int i = 0;

    // Extrai o ISBN
    substring(linha, aux, i, ';');
    b->set_ISBN(aux);

    // Extrai o título
    substring(linha, aux, i, ';');
    b->set_title(aux);

    // Extrai o autor
    substring(linha, aux, i, ';');
    b->set_author(aux);

    // Extrai o ano de publicação
    substring(linha, aux, i, ';');
    b->set_yearOfPublication(atoi(aux));

    // Extrai o nome da editora (publisher)
    substring(linha, aux, i, '\0');
    b->set_publisher(aux);
}

bool Arquivo::carrega_csv(Hashing* h) {
    ifstream fin;
    fin.open(nome_arquivo);
    if (!fin.is_open()) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return false;
    }
    Book* b;
    char linha[1000];
    fin.getline(linha, 1000); // Ignora o cabeçalho do CSV

    while (fin.getline(linha, 1000)) {
        b = new Book();
        separa_atributos(linha, b);
        h->insere(b);
    }
    fin.close();
    return true;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    char nome_arq[] = "books1.csv";
    Arquivo* arq = new Arquivo(nome_arq);
    int tam;

    cout << "Entre com o tamanho da tabela hash: ";
    cin >> tam;

    Hashing* h = new Hashing(tam);

    if (arq->carrega_csv(h))
    {
        h->imprime();
        cout << "Quantidades de colisões: " << h->get_quantColisoes() << endl;

        // Testar consulta
        char ISBN_procurado[20];
        cout << "Digite o ISBN para consulta: ";
        cin >> ISBN_procurado;
        h->consulta(ISBN_procurado);
    }

    delete h;
    delete arq;
    return 0;
}
