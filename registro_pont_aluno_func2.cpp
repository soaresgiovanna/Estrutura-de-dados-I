#include<iostream>
using namespace std;
struct Aluno
{
    int matricula;
    char nome[40];
};
bool alocaAluno(Aluno **a)
{
    *a = new (nothrow) Aluno();
    if (*a) return true;
    else return false;
}
void leiaAluno (Aluno *a)
{
    cout << "Matricula: ";
    cin >> a->matricula;
    cout << "Nome.....: ";
    fflush(stdin);
    cin.getline(a->nome, 40);
}
void imprimeAluno (Aluno *a)
{
    cout << "Matricula digitada: " << a->matricula << endl;
    cout << "Nome digitado.....: " << a->nome << endl;
}
int main()
{
    Aluno *student = NULL;

    if (alocaAluno(&student))
    {
        leiaAluno (student);
        imprimeAluno (student);
        delete student;
    }
    else cout << "\nNão há memória suficiente para alocação!";
    return 0;
}
