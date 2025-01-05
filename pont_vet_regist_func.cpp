#include<iostream>
using namespace std;
const int MAX = 5;
struct Aluno
{
    int matricula;
    char nome[40];
};
void leiaAlunos (Aluno *alunos)
{
    for(int i=0; i<MAX; i++)
    {
        cout << "Matricula: ";
        cin >> alunos[i].matricula;
        cout << "Nome.....: ";
        fflush(stdin);
        gets(alunos[i].nome);
        cout << endl;
    }
}
void imprimeAlunos (Aluno *alunos)
{
    for(int i=0; i<MAX; i++)
    {
        cout << "\nMatricula digitada: " << alunos[i].matricula << endl;
        cout << "Nome digitado.....: " << alunos[i].nome << endl;
    }
}
int main()
{
    Aluno *students = new (nothrow) Aluno[MAX];
    if (students)
    {
        leiaAlunos(students);
        imprimeAlunos(students);
        delete [] students;
    }
    else cout << "Não há memória suficiente para alocação!";
    return 0;
}
