// Proposta: Implementar
//Herança para as classes Veículo (superclasse), Carro (subclasse) e Moto (subclasse), implementando os atributos e
//métodos abaixo:

//Veiculo:
//- Marca, modelo ano, velocidade
//- acelerar(), frear(), exibirDados()

//Carro:
//-numeroPortas
//-ligarArCondicionado()
//-exibirDados()

//Moto:
//- cilindradas
//- empinar()
//- exibirDados()


#include <iostream>
#include <string>
using namespace std;


class Veiculo {
protected:
    string marca;
    string modelo;
    int ano;
    float velocidade;

public:
   
    Veiculo(string marca, string modelo, int ano)
        : marca(marca), modelo(modelo), ano(ano), velocidade(0) {}

   
    void acelerar() {
        velocidade += 10;
        cout << "Acelerando... Velocidade atual: " << velocidade << " km/h" << endl;
    }


    void frear() {
        if (velocidade >= 10) {
            velocidade -= 10;
        } else {
            velocidade = 0;
        }
        cout << "Freando... Velocidade atual: " << velocidade << " km/h" << endl;
    }


    virtual void exibirDados() const {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Ano: " << ano << endl;
        cout << "Velocidade: " << velocidade << " km/h" << endl;
    }
};


class Carro : public Veiculo {
private:
    int numeroPortas;

public:

    Carro(string marca, string modelo, int ano, int numeroPortas)
        : Veiculo(marca, modelo, ano), numeroPortas(numeroPortas) {}


    void ligarArCondicionado() {
        cout << "Ar-condicionado ligado no carro " << modelo << endl;
    }

    void exibirDados() const override {
        Veiculo::exibirDados();
        cout << "Número de Portas: " << numeroPortas << endl;
    }
};


class Moto : public Veiculo {
private:
    int cilindradas;

public:

    Moto(string marca, string modelo, int ano, int cilindradas)
        : Veiculo(marca, modelo, ano), cilindradas(cilindradas) {}


    void empinar() {
        cout << "Empinando a moto " << modelo << "!" << endl;
    }

    void exibirDados() const override {
        Veiculo::exibirDados();
        cout << "Cilindradas: " << cilindradas << " cc" << endl;
    }
};

int main() {

    Carro carro("Toyota", "Corolla", 2023, 4);
    cout << "\nDados do Carro:" << endl;
    carro.exibirDados();
    carro.acelerar();
    carro.ligarArCondicionado();
    carro.frear();

    Moto moto("Honda", "CB500", 2024, 500);
    cout << "\nDados da Moto:" << endl;
    moto.exibirDados();
    moto.acelerar();
    moto.empinar();
    moto.frear();

    return 0;
}
