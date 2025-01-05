#include<iostream>
#include<cstring>
using namespace std;
// Nome da classe que representa o conjunto de objetos
class Carro
{
// O que o carro tem: atributos
private://DIFICIL ACESSO
    int parado; // 1 - parado, 0 - movimento
    int ligado; // 1 - ligado, 0 - desligado
    char* fabricante; // Era fabricante[20];
    char* modelo; // Era modelo[20];
    char* motor; // Era motor[4];


// O que o carro faz: métodos
public://FACIL ACESSO
// Construtor padrão
    Carro()
    {
        ligado = 0;
        parado = 1;
        fabricante = 0; // Era strcpy(fabricante, "");//COPIA OQ TA NAS "" EM FABRICANTE
        motor = 0; // Era strcpy(motor, "");
        modelo = 0; // Era strcpy(modelo, "");
    }
// Construtor com parâmetros
    Carro(int _parado, int _ligado, char _fabricante[], char _modelo[], char _motor[])//MUDA OS VETORES PRIVADOS PARA OS NOVOS VALORES
    {
        parado = _parado;
        ligado = _ligado;
// Era apenas strcpy(fabricante, _fabricante);
        fabricante = new char[strlen(_fabricante)+1];//DEFINIU UM ARRAYA DE CARACTERES DO TAMANHO MAIS UM DE FABRICANTE
        strcpy(fabricante, _fabricante);//COPIOU O NOVO VALOR LA
// Era apenas strcpy(modelo, _modelo);
        modelo = new char[strlen(_modelo)+1];//O MESMO RACIOCINIO
        strcpy(modelo, _modelo);
// Era apenas strcpy(motor, _motor);
        motor = new char[strlen(_motor)+1];//NOVAMENTE
        strcpy(motor, _motor);
    }
// Métodos de acesso aos atributos: getters e setters
    void setLigado(int _ligado)//MUDA O VALOR NA CLASS PRIVADA COM O PONTEIRO PASSADO POR PARAMETRO
    {
        ligado = _ligado;
    }
    void setParado(int _parado)//MUDA O VALOR NA CLASS PRIVADA COM O PONTEIRO PASSADO POR PARAMETRO
    {
        parado = _parado;
    }
    void setFabricante(char _fabricante[])//FAZ A MESMA COISA EXPLICADA EM SETMOTOR
    {
// Era apenas strcpy(fabricante, _fabricante);
        delete [] fabricante;
        fabricante = new char[strlen(_fabricante)+1];
        strcpy(fabricante, _fabricante);
    }
    void setModelo(char _modelo[])//FAZ A MESMA COISA EXPLICADA EM SETMOTOR
    {
// Era apenas strcpy(modelo, _modelo);
        delete [] modelo;
        modelo = new char[strlen(_modelo)+1];
        strcpy(modelo, _modelo);
    }
    void setMotor(char _motor[])//ACESSA O PONTEIRO MOTOR
    {
// Era apenas strcpy(motor, _motor);
        delete [] motor;//APAGA O PONTEIRO
        motor = new char[strlen(_motor)+1];//CRIA OUTRO UM INDICE A FRENTE
        strcpy(motor, _motor);//COPIA O NOVO PONTEIRO NO VELHO
    }
    int getParado()//RETORNA SE O CARRO ESTA PARADO, ACASSANDO A CLASS PRIVADA
    {
        return parado;
    }
    int getLigado()//RETORNA SE O CARRO ESTA LIGADO, ACASSANDO A CLASS PRIVADA
    {
        return ligado;
    }
    char * getFabricante()//RETORNA O FABRICANTE, ACASSANDO A CLASS PRIVADA
    {
        return fabricante;
    }
    char * getModelo()//RETORNA O MODELO, ACASSANDO A CLASS PRIVADA
    {
        return modelo;
    }
    char * getMotor()//RETORNA O MOTOR, ACASSANDO A CLASS PRIVADA
    {
        return motor;
    }
// Métodos específicos
    void ligar()//ACESSA O PONTEIRO PRIVADO DA CLASS
    {
        ligado = 1;//MUDA ELE PARA UM
    }
    void desligar()//ACESSA O PONTEIRO PRIVADO DA CLASS
    {
        ligado = 0;//MUDA ELE PARA ZERO
    }
    void andar()//ACESSA O PONTEIRO PRIVADO DA CLASS
    {
        parado = 0;//MUDA ELE PARA ZERO
    }
    void parar()//ACESSA O PONTEIRO PRIVADO DA CLASS
    {
        parado = 1;//MUDA ELE PARA UM
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
//APAGA TUDO
    }
};
int main()
{
// O construtor é chamado quando o comando new é executado
    Carro *gol = new (nothrow) Carro (1,0,"Volks", "GTI", "1.8");//GOL É UM PONTEIRO DO TIPO CARRO DEFINIDO EM TEMPO DE EXECULÇÃO
    if(gol)//SE GOL FOI CRIADO
    {
        gol->ligar(); //GOL APONTA PARA LIGAR QUE DIZ SE O CARRO ESTÁ LIGADO, ESSA FUNÇÃO(LIGAR) ACESSA A CLASS PRIVADA
        gol->andar(); //MESMA COISA
//Para saber se o carro está ligado
        if (gol->getLigado()==1)//GOL APONTA PARA A FUNÇÃO GETLIGADO QUE COM O "GET" CONSEGUE ACESSAR A CLASS PRIVADA
            cout << "Carro ligado";//IMPRIME RESULTADO
        else cout << "Carro desligado";//IMPRIME RESULTADO
        gol->parar();//GOL APONTA PARA A FUNÇÃO PARAR QUE COM O CONSEGUE ACESSAR A CLASS PRIVADA
        gol->desligar();//O MESMO RACIOCÍNIO
        delete gol; // neste momento, o destrutor é automaticamente chamado
//APAGA O PONTEIRO GOL
    }
    else cout << "Não foi possível alocar memória!";//SE GOL N FOI CRIADO
// O construtor é chamado quando o comando new é executado
    Carro *astra = new (nothrow) Carro();//DECLARA ASTRA, OOBJETO DO TIPO CARRO EM TEMPO DE EXECULÇÃO
    if(astra)//VERIFICA SE ABRIU
    {
//Agora posso modificar os valores dos atributos
        astra->setMotor ("2.0");//ASTRA APONTA PARA SETMOTOR, QUE NA FUNÇÃO MUDARÁ O VALOR DO MOTOR
//Para conferir se mudou mesmo o valor do motor
        cout << endl << astra->getMotor();//IMPRIME O PONTEIRO APONTADO POR ASTRA
        delete astra; // neste momento, o destrutor é automaticamente chamado
//APAGA ASTRA
    }
    else cout << "Não foi possível alocar memória!";//CONFERE
    return 0;
}
