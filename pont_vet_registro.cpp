#include<iostream>
using namespace std;
const int MAX = 5;
struct Aluno
{
    int matricula;
    char nome[40];
};
int main()
{
    Aluno *students = new (nothrow) Aluno[MAX];
    if(students)
    {
        for (int i = 0; i < MAX; i++)
        {
            cout << "Matricula: ";
            cin >> students[i].matricula;
            cout << "Nome.....: ";
            fflush(stdin);
            cin.getline(students[i].nome, 40);
        }
        for (int i = 0; i < MAX; i++)
        {
            cout << "\nMatricula digitada: " << students[i].matricula;
            cout << "\nNome digitado.....: " << students[i].nome << endl;
        }
        delete [] students;
    }
    else cout << "Não há memória suficiente para alocação!";

    return 0;
}
