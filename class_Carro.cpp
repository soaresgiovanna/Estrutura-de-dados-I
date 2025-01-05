#include<iostream>
#include<cstring>
using namespace std;
// Nome da classe que representa o conjunto de objetos
class Carro
{
// O que o carro tem: atributos
private:
    int parado;
    int ligado;
    char* fabricante;
    char* modelo;
    char* motor;

// O que o carro faz: métodos
public:
// Construtor padrão
    Carro()
    {
        ligado = 0;
        parado = 1;
        fabricante = 0;
        motor = 0;
        modelo = 0;
    }
// Construtor com parâmetros
    Carro(int _parado, int _ligado, char _fabricante[], char _modelo[], char _motor[])
    {
        parado = _parado;
        ligado = _ligado;

        fabricante = new char[strlen(_fabricante)+1];
        strcpy(fabricante, _fabricante);

        modelo = new char[strlen(_modelo)+1];
        strcpy(modelo, _modelo);

        motor = new char[strlen(_motor)+1];
        strcpy(motor, _motor);
    }
// Métodos de acesso aos atributos: getters e setters
    void setLigado(int _ligado)
    {
        ligado = _ligado;
    }
    void setParado(int _parado)
    {
        parado = _parado;
    }
    void setFabricante(char _fabricante[])
    {
        delete [] fabricante;
        fabricante = new char[strlen(_fabricante)+1];
        strcpy(fabricante, _fabricante);
    }
    void setModelo(char _modelo[])
    {
        delete [] modelo;
        modelo = new char[strlen(_modelo)+1];
        strcpy(modelo, _modelo);
    }
    void setMotor(char _motor[])
    {
        delete [] motor;
        motor = new char[strlen(_motor)+1];
        strcpy(motor, _motor);
    }
    int getParado()
    {
        return parado;
    }
    int getLigado()
    {
        return ligado;
    }
    char * getFabricante()
    {
        return fabricante;
    }
    char * getModelo()
    {
        return modelo;
    }
    char * getMotor()
    {
        return motor;
    }
// Métodos específicos
    void ligar()
    {
        ligado = 1;
    }
    void desligar()
    {
        ligado = 0;
    }
    void andar()
    {
        parado = 0;
    }
    void parar()
    {
        parado = 1;
    }
// Destrutor
    ~Carro()
    {
// Libera as memórias alocadas
        delete [] fabricante;
        fabricante = 0;
        delete [] motor;
        motor = 0;
        delete [] modelo;
        modelo = 0;
    }
};
int main()
{
    Carro *gol = new (nothrow) Carro (1,0,"Volks", "GTI", "1.8");
    if(gol)
    {
        gol->ligar();
        gol->andar();

        //Para saber se o carro está ligado
        if (gol->getLigado()==1)
            cout << "Carro ligado";
        else cout << "Carro desligado";

        gol->parar();
        gol->desligar();
        delete gol; // neste momento, o destrutor é automaticamente chamado
    }
    else cout << "Não foi possível alocar memória!";
// O construtor é chamado quando o comando new é executado
    Carro *astra = new (nothrow) Carro();
    if(astra)
    {
//Agora posso modificar os valores dos atributos
        astra->setMotor ("2.0");
//Para conferir se mudou mesmo o valor do motor
        cout << endl << astra->getMotor();
        delete astra; // neste momento, o destrutor é automaticamente chamado
    }
    else cout << "Não foi possível alocar memória!";
    return 0;
}
