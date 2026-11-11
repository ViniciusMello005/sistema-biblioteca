
#include <iostream>
#include <string>

using namespace std;

#define MAX 10 // Limite maximo de usuarios e livros

// Estrutura para armazenar os dados dos usuarios
struct Usuario {
    int matricula;
    string nome;
    string tipo;
};

// Estrutura para armazenar os dados dos livros
struct Livro {
    int codigo;
    string titulo;
    string autor;
    string edicao;
    int matricula_usuario;
};

// Funcao que exibe o menu do programa
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

// Procura um usuario pela matricula
// Retorna a posicao do usuario ou -1 se nao encontrar
int buscarUsuario(Usuario usuarios[], int n, int matricula) {

    for (int i = 0; i < n; i++) {

        if (usuarios[i].matricula == matricula) {
            return i;
        }
    }

    return -1;
}

// Funcao para cadastrar um usuario
void cadastrarUsuario(Usuario usuarios[], int &n) {

    // Verifica se ainda existe espaco no vetor
    if (n == MAX) {
        cout << "Limite de usuarios atingido!\n";
        return;
    }

    int matricula;

    cout << "Matricula: ";
    cin >> matricula;

    // Verifica se a matricula ja esta cadastrada
    if (buscarUsuario(usuarios, n, matricula) != -1) {
        cout << "Matricula ja cadastrada!\n";
        return;
    }

    // Armazena a matricula na proxima posicao livre
    usuarios[n].matricula = matricula;

    cin.ignore();

    cout << "Nome: ";
    getline(cin, usuarios[n].nome);

    cout << "Tipo: ";
    getline(cin, usuarios[n].tipo);

    // Aumenta a quantidade de usuarios cadastrados
    n++;

    cout << "Usuario cadastrado!\n";
}

// Funcao para cadastrar um livro
void cadastrarLivro(Livro livros[], int &n,
                    Usuario usuarios[], int nUsuarios) {

    // Verifica se ainda existe espaco no vetor
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

    // Verifica se o usuario informado esta cadastrado
    if (livros[n].matricula_usuario != 0 &&
        buscarUsuario(usuarios, nUsuarios,
                      livros[n].matricula_usuario) == -1) {

        cout << "Usuario nao cadastrado!\n";
        return;
    }

    // Aumenta a quantidade de livros cadastrados
    n++;

    cout << "Livro cadastrado!\n";
}

// Funcao para mostrar todos os usuarios
void mostrarUsuario(Usuario usuarios[], int n) {

    for (int i = 0; i < n; i++) {

        cout << "\nMatricula: " << usuarios[i].matricula;
        cout << "\nNome: " << usuarios[i].nome;
        cout << "\nTipo: " << usuarios[i].tipo << endl;
    }
}

// Funcao para mostrar todos os livros
void mostrarLivro(Livro livros[], int n,
                  Usuario usuarios[], int nUsuarios) {

    for (int i = 0; i < n; i++) {

        cout << "\nCodigo: " << livros[i].codigo;
        cout << "\nTitulo: " << livros[i].titulo;
        cout << "\nAutor: " << livros[i].autor;
        cout << "\nEdicao: " << livros[i].edicao;

        // Verifica se o livro esta disponivel
        if (livros[i].matricula_usuario == 0) {
            cout << "\nDisponivel\n";
        } else {

            // Busca o usuario associado ao livro
            int pos = buscarUsuario(usuarios, nUsuarios,
                                    livros[i].matricula_usuario);

            cout << "\nEmprestado para: "
                 << usuarios[pos].nome << endl;
        }
    }
}

// Funcao para buscar livros pela matricula do usuario
void buscarLivros(Livro livros[], int nLivros,
                  Usuario usuarios[], int nUsuarios) {

    int matricula;
    bool encontrou = false;

    cout << "Digite a matricula: ";
    cin >> matricula;

    // Verifica se o usuario existe
    int pos = buscarUsuario(usuarios, nUsuarios, matricula);

    if (pos == -1) {
        cout << "Usuario nao encontrado!\n";
        return;
    }

    cout << "\nLivros de " << usuarios[pos].nome << ":\n";

    // Percorre todos os livros procurando pela matricula
    for (int i = 0; i < nLivros; i++) {

        if (livros[i].matricula_usuario == matricula) {
            cout << "Titulo: " << livros[i].titulo << endl;
            encontrou = true;
        }
    }

    // Informa se nenhum livro foi encontrado
    if (encontrou == false) {
        cout << "Nenhum livro emprestado.\n";
    }
}

// Funcao que mostra quantos livros cada usuario possui
void relatorioGeral(Usuario usuarios[], int nUsuarios,
                    Livro livros[], int nLivros) {

    // Percorre todos os usuarios
    for (int i = 0; i < nUsuarios; i++) {

        int quantidade = 0;

        // Conta os livros associados a matricula do usuario
        for (int j = 0; j < nLivros; j++) {

            if (livros[j].matricula_usuario ==
                usuarios[i].matricula) {

                quantidade++;
            }
        }

        cout << "\nUsuario: " << usuarios[i].nome;
        cout << "\nLivros emprestados: " << quantidade << endl;
    }
}

// Funcao principal do programa
int main() {

    // Cria os vetores com limite de MAX (10)
    Usuario listaUsuario[MAX];
    Livro listaLivro[MAX];

    // Contadores de usuarios e livros cadastrados
    int contUsuario = 0;
    int contLivro = 0;

    int opcao;

    // Repete o menu ate o usuario escolher a opcao 0
    do {

        mostrarMenu();
        cin >> opcao;

        // Executa a funcao conforme a opcao escolhida
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
