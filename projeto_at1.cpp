
#include <iostream>
#include <string>

using namespace std;

#define MAX 10

struct Usuario {
    int matricula;
    string nome;
    string tipo;
};

struct Livro {
    int codigo;
    string titulo;
    string autor;
    string edicao;
    int matricula_usuario;
};

// Menu
void mostrarMenu() {
    cout << "\n===== MENU =====\n";
    cout << "1 - Cadastrar Usuario\n";
    cout << "2 - Cadastrar Livro\n";
    cout << "3 - Listar Usuarios\n";
    cout << "4 - Listar Livros\n";
    cout << "5 - Buscar Livros por Usuario\n";
    cout << "6 - Relatorio Geral\n";
    cout << "0 - Sair\n";
    cout << "Escolha: ";
}

// Buscar usuario
int buscarUsuario(Usuario usuarios[], int n, int matricula) {
    for (int i = 0; i < n; i++) {
        if (usuarios[i].matricula == matricula) {
            return i;
        }
    }
    return -1;
}

// Cadastrar usuario
void cadastrarUsuario(Usuario usuarios[], int &n) {

    if (n == MAX) {
        cout << "Limite de usuarios atingido!\n";
        return;
    }

    int matricula;

    cout << "Matricula: ";
    cin >> matricula;

    if (buscarUsuario(usuarios, n, matricula) != -1) {
        cout << "Matricula ja cadastrada!\n";
        return;
    }

    usuarios[n].matricula = matricula;

    cin.ignore();

    cout << "Nome: ";
    getline(cin, usuarios[n].nome);

    cout << "Tipo: ";
    getline(cin, usuarios[n].tipo);

    n++;

    cout << "Usuario cadastrado!\n";
}

// Cadastrar livro
void cadastrarLivro(Livro livros[], int &n,
                    Usuario usuarios[], int nUsuarios) {

    if (n == MAX) {
        cout << "Limite de livros atingido!\n";
        return;
    }

    cout << "Codigo: ";
    cin >> livros[n].codigo;

    cin.ignore();

    cout << "Titulo: ";
    getline(cin, livros[n].titulo);

    cout << "Autor: ";
    getline(cin, livros[n].autor);

    cout << "Edicao: ";
    getline(cin, livros[n].edicao);

    cout << "Matricula do usuario (0 para disponivel): ";
    cin >> livros[n].matricula_usuario;

    if (livros[n].matricula_usuario != 0 &&
        buscarUsuario(usuarios, nUsuarios,
                      livros[n].matricula_usuario) == -1) {

        cout << "Usuario nao cadastrado!\n";
        return;
    }

    n++;

    cout << "Livro cadastrado!\n";
}

// Listar usuarios
void mostrarUsuario(Usuario usuarios[], int n) {

    for (int i = 0; i < n; i++) {
        cout << "\nMatricula: " << usuarios[i].matricula;
        cout << "\nNome: " << usuarios[i].nome;
        cout << "\nTipo: " << usuarios[i].tipo << endl;
    }
}

// Listar livros
void mostrarLivro(Livro livros[], int n,
                  Usuario usuarios[], int nUsuarios) {

    for (int i = 0; i < n; i++) {

        cout << "\nCodigo: " << livros[i].codigo;
        cout << "\nTitulo: " << livros[i].titulo;
        cout << "\nAutor: " << livros[i].autor;
        cout << "\nEdicao: " << livros[i].edicao;

        if (livros[i].matricula_usuario == 0) {
            cout << "\nDisponivel\n";
        } else {
            int pos = buscarUsuario(usuarios, nUsuarios,
                                   livros[i].matricula_usuario);

            cout << "\nEmprestado para: " << usuarios[pos].nome << endl;
        }
    }
}

// Buscar livros por usuario
void buscarLivros(Livro livros[], int nLivros,
                  Usuario usuarios[], int nUsuarios) {

    int matricula;
    bool encontrou = false;

    cout << "Digite a matricula: ";
    cin >> matricula;

    int pos = buscarUsuario(usuarios, nUsuarios, matricula);

    if (pos == -1) {
        cout << "Usuario nao encontrado!\n";
        return;
    }

    cout << "\nLivros de " << usuarios[pos].nome << ":\n";

    for (int i = 0; i < nLivros; i++) {

        if (livros[i].matricula_usuario == matricula) {
            cout << "Titulo: " << livros[i].titulo << endl;
            encontrou = true;
        }
    }

    if (encontrou == false) {
        cout << "Nenhum livro emprestado.\n";
    }
}

// Relatorio geral
void relatorioGeral(Usuario usuarios[], int nUsuarios,
                    Livro livros[], int nLivros) {

    for (int i = 0; i < nUsuarios; i++) {

        int quantidade = 0;

        for (int j = 0; j < nLivros; j++) {

            if (livros[j].matricula_usuario == usuarios[i].matricula) {
                quantidade++;
            }
        }

        cout << "\nUsuario: " << usuarios[i].nome;
        cout << "\nLivros emprestados: " << quantidade << endl;
    }
}

// Programa principal
int main() {

    Usuario listaUsuario[MAX];
    Livro listaLivro[MAX];

    int contUsuario = 0;
    int contLivro = 0;
    int opcao;

    do {
        mostrarMenu();
        cin >> opcao;

        switch (opcao) {

            case 1:
                cadastrarUsuario(listaUsuario, contUsuario);
                break;

            case 2:
                cadastrarLivro(listaLivro, contLivro,
                               listaUsuario, contUsuario);
                break;

            case 3:
                mostrarUsuario(listaUsuario, contUsuario);
                break;

            case 4:
                mostrarLivro(listaLivro, contLivro,
                             listaUsuario, contUsuario);
                break;

            case 5:
                buscarLivros(listaLivro, contLivro,
                             listaUsuario, contUsuario);
                break;

            case 6:
                relatorioGeral(listaUsuario, contUsuario,
                               listaLivro, contLivro);
                break;

            case 0:
                cout << "Encerrando programa...\n";
                break;

            default:
                cout << "Opcao invalida!\n";
        }

    } while (opcao != 0);

    return 0;
}
