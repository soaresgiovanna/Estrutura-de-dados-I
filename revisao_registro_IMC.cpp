#include <iostream>
#include <cstring>
using namespace std;
const int N=2;
struct pessoas
{
    char nome[50];
    float peso;
    float altura;
    float IMC;
};
float calIMC (pessoas p[], int i)
{
    return p[i].peso / (p[i].altura * p[i].altura);
}
void situacao(pessoas p[])
{
    for(int i=0; i<N; i++)
    {
    if(p[i].IMC < 18.5)
            {
                cout << p[i].nome << ", " << "você está abaixo do peso ideal " << endl;
            }
    else if(p[i].IMC < 25)
            {
                cout << p[i].nome << ", " << "você está no seu peso ideal" << endl;
            }
         else if(p[i].IMC >= 25)
            {
                cout << p[i].nome << ", " << "você está acima do peso ideal" << endl;
            }
               else
                cout << "Erro cod.33";
    }
}
void entrada(pessoas p[])
{
    for(int i=0; i<N; i++)
    {
    cout << "Informe o nome: " << endl;
    cin.ignore();
    cin.getline(p[i].nome, 50);
    cout << "Informe o peso: " << endl;
    cin >> p[i].peso;
    cout << "Informe a altura: " << endl;
    cin >> p[i].altura;

    p[i].IMC = calIMC(p, i);
    }
}
int main()
{setlocale(LC_ALL, "Portuguese");

    cout << "Não use virgura, use ponto!" << endl;
    pessoas p[N];
    entrada(p);
    situacao(p);

    return 0;
}
