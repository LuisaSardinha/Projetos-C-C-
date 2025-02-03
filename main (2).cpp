//Proposta: Modele
//um sistema onde um Carro herda de uma classe base Veiculo e contém um objeto
//Motor (composição). A classe Veiculo deve ter um método ligar(), e a classe
//Motor deve ter um método funcionar(). A classe Carro deve ter um método
//acelerar() que usa o motor. No método principal, crie um objeto Carro, ligue-o
//e acelere.



#include <iostream>
#include <string>
using namespace std;


class Motor {
public:
 
    void funcionar() const {
        cout << "Motor funcionando" << endl;
    }
};


class Veiculo {
protected:
    string marca;
    string modelo;
    int ano;

public:

    Veiculo(string marca, string modelo, int ano)
        : marca(marca), modelo(modelo), ano(ano) {}


    void ligar() const {
        cout << "Veículo " << modelo << " ligado!" << endl;
    }
};


class Carro : public Veiculo {
private:
    Motor motor;  

public:

    Carro(string marca, string modelo, int ano)
        : Veiculo(marca, modelo, ano) {}


    void acelerar() {
        motor.funcionar();
        cout << "Acelerando o carro " << modelo <<  endl;
    }
};

int main() {

    Carro carro("Toyota", "Corolla", 2023);


    carro.ligar();


    carro.acelerar();

    return 0;
}
