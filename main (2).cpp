
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
