//introdução a Programação orientada a Objetos (POO)
#include <iostream>
using namespace std;
class Carro
{
    private://O que o carro tem :atributos
        int parado;//1_parado, 0_movimento
        int ligado;//1_ligado, 0_desligado
        char fabricante[20]; //
        char modelo[20];
        char motor[4];

    public: //o que o carro faz: métodos(ações)
        Carro();
        Carro(int,int,char*,char*,char*);
        //Métodos gette e setters

        void set ();
        void set ();
        void set ();
        void set ();
        void set ();

}
