#include <iostream>
#include <map>
#include <string>
#include <iomanip>  // Para formatar a média com 2 casas decimais
using namespace std;

// Classe Aluno
class Aluno {
private:
    string nome;
    int matricula;
    float notaMatematica;
    float notaPortugues;
    float notaCiencias;

public:
    // Construtor padrão
    Aluno() : nome(""), matricula(0), notaMatematica(0.0), notaPortugues(0.0), notaCiencias(0.0) {}

    // Construtor com parâmetros
    Aluno(string n, int m, float mat, float por, float c)
        : nome(n), matricula(m), notaMatematica(mat), notaPortugues(por), notaCiencias(c) {}

    // Método para calcular a média
    float calcularMedia() const {
        return (notaMatematica + notaPortugues + notaCiencias) / 3.0f;
    }

    // Método para exibir os dados do aluno
    void exibirDados() const {
        cout << "Nome: " << nome << endl;
        cout << "Matrícula: " << matricula << endl;
        cout << "Matemática: " << notaMatematica << endl;
        cout << "Português: " << notaPortugues << endl;
        cout << "Ciências: " << notaCiencias << endl;
        cout << fixed << setprecision(2) << "Média: " << calcularMedia() << endl << endl;
    }
};

int main() {
    map<int, Aluno> alunos;
    int opcao;

    do {
        cout << "1. Cadastrar Aluno" << endl;
        cout << "2. Exibir Dados de Todos os Alunos" << endl;
        cout << "3. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        if (opcao == 1) {
            string nome;
            int matricula;
            float notaMatematica, notaPortugues, notaCiencias;

            cout << "Informe o nome do aluno: ";
            cin.ignore();  // Limpar o buffer de entrada antes de usar getline
            getline(cin, nome);  // Captura o nome com espaços

            cout << "Informe a matrícula do aluno: ";
            cin >> matricula;

            cout << "Informe a nota de Matemática: ";
            cin >> notaMatematica;

            cout << "Informe a nota de Português: ";
            cin >> notaPortugues;

            cout << "Informe a nota de Ciências: ";
            cin >> notaCiencias;

            // Criar um objeto Aluno e armazená-lo no map com a matrícula como chave
            Aluno aluno(nome, matricula, notaMatematica, notaPortugues, notaCiencias);
            alunos[matricula] = aluno;  // A matrícula é a chave do map
        } 
        else if (opcao == 2) {
            if (alunos.empty()) {
                cout << "Não há alunos cadastrados!" << endl;
            } else {
                for (const auto& alunoPair : alunos) {
                    alunoPair.second.exibirDados();
                }
            }
        }
    } while (opcao != 3);

    cout << "Saindo do programa..." << endl;
    return 0;
}


