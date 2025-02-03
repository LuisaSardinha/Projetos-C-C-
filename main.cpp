#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Livro {
private:
    int id;
    string titulo;
    string autor;
    int anoPublicacao;

public:
  
    Livro(int id, const string &titulo, const string &autor, int anoPublicacao) {
        this->id = id;
        this->titulo = titulo;
        this->autor = autor;
        this->anoPublicacao = anoPublicacao;
    }

  
    int getId() const {
        return id;
    }

    string getTitulo() const {
        return titulo;
    }

    string getAutor() const {
        return autor;
    }

    int getAnoPublicacao() const {
        return anoPublicacao;
    }

    void mostrarDetalhes() const {
        cout << "ID: " << id << endl;
        cout << "Título: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Ano de Publicação: " << anoPublicacao << endl;
    }

 
    bool comparaId(int idPesquisa) const {
        return id == idPesquisa;
    }
};

class Biblioteca {
private:
    vector<Livro> livros;

public:

    void adicionarLivro() {
        int id;
        string titulo, autor;
        int ano;

        cout << "Digite o ID do livro: ";
        cin >> id;
        cin.ignore();

        cout << "Digite o título do livro: ";
        getline(cin, titulo);

        cout << "Digite o autor do livro: ";
        getline(cin, autor);

        cout << "Digite o ano de publicação: ";
        cin >> ano;

        livros.push_back(Livro(id, titulo, autor, ano));
        cout << "Livro adicionado com sucesso!" << endl;
    }

    void listarLivros() const {
        if (livros.empty()) {
            cout << "Não há livros cadastrados!" << endl;
            return;
        }

        for (const auto &livro : livros) {
            livro.mostrarDetalhes();
            cout << "-----------------------" << endl;
        }
    }


    void excluirLivro() {
        int id;
        cout << "Digite o ID do livro a ser excluído: ";
        cin >> id;

        auto it = find_if(livros.begin(), livros.end(), [id](const Livro &livro) {
            return livro.comparaId(id);
        });

        if (it != livros.end()) {
            livros.erase(it);
            cout << "Livro excluído com sucesso!" << endl;
        } else {
            cout << "Livro não encontrado!" << endl;
        }
    }

    void pesquisarLivro() const {
        string titulo;
        cout << "Digite o título do livro a ser pesquisado: ";
        cin.ignore();
        getline(cin, titulo);

        bool encontrado = false;
        for (const auto &livro : livros) {
            if (livro.getTitulo() == titulo) {
                livro.mostrarDetalhes();
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            cout << "Livro não encontrado!" << endl;
        }
    }
};

int main() {
    Biblioteca biblioteca;
    int opcao;

    do {
        cout << "----- MENU -----" << endl;
        cout << "1. Inserir livro" << endl;
        cout << "2. Listar livros" << endl;
        cout << "3. Excluir livro por ID" << endl;
        cout << "4. Pesquisar livro por título" << endl;
        cout << "5. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                biblioteca.adicionarLivro();
                break;
            case 2:
                biblioteca.listarLivros();
                break;
            case 3:
                biblioteca.excluirLivro();
                break;
            case 4:
                biblioteca.pesquisarLivro();
                break;
            case 5:
                cout << "Saindo do programa..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
        }

    } while (opcao != 5);

    return 0;
}

