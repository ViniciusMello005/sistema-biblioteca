#include <iostream>

using namespace std;

#define MAX 10

// Definir a struct de Usuario
struct Usuario {
    int matricula;
    string nome;
    string tipo;
};

// Definir a struct de Livro
struct Livro {
    int codigo;
    string titulo;
    string autor;
    string edicao;
    int matricula_usuario;
};

// Procedimento para exibir um menu de opções
void mostrarMenu(){
    cout << "################## MENU ###################\n";
    cout << "# 1 - Cadastrar Usuario                   #\n";
    cout << "# 2 - Cadastrar Livro                     #\n";
    cout << "# 3 - Listar Usuarios                     #\n";
    cout << "# 4 - Listar Livros                       #\n";
    cout << "# 5 - Buscar Livros por Usuario           #\n";
    cout << "# 6 - Relatorio Geral                     #\n";
    cout << "# 0 - Sair                                #\n";
    cout << "###########################################\n\n";
    cout << "Digite sua opcao:";
}

// Procedimento para cadastrar um novo usuario
void cadastrarUsuario(Usuario vet[], int i){
    for(int n=0;n<i;n++){
        if(vet[n].matricula == vet[i].matricula){
        cout << "Essa Matricula ja existe";

    cout << "Digite a matricula: " << endl;
    cin >> vet[i].matricula;
    cin.ignore();
    cout << "Digite o nome: " << endl;
    getline(cin, vet[i].nome);
    cout << "Digite o Tipo de Usuario: " << endl;
    cin >> vet[i].tipo;
    }
  }
}

// Procedimento para cadastrar um novo livro
void cadastrarLivro(Livro vet[], int i){
    cout << "Digite a Codigo: " << endl;
    cin >> vet[i].codigo;
    cin.ignore();
    cout << "Digite o Titulo: " << endl;
    getline(cin, vet[i].titulo);
    cin.ignore();
    cout << "Digite o Autor: " << endl;
    getline(cin, vet[i].autor);
    cout << "Digite a Edicao: " << endl;
    cin >> vet[i].edicao;
}

// Procedimento para exibir os usuarios cadastrados
void mostrarUsuario(Usuario vet[] , int n){
    cout << "Usuarios cadastrados: \n";
    for(int i=0; i<n;i++){
        cout << " ---------------------------------\n";
        cout << "Matricula: " << vet[i].matricula << endl;
        cout << "Nome: " << vet[i].nome << endl;
        cout << "Tipo: " << vet[i].tipo << endl;

    }
    cout << " ---------------------------------\n";
}

// Procedimento para exibir os livros cadastrados
void mostrarLivro(Livro vet[] , int n){
    cout << "Livros cadastrados: \n";
    for(int i=0; i<n;i++){
        cout << " ---------------------------------\n";
        cout << "Codigo: " << vet[i].codigo << endl;
        cout << "Titulo: " << vet[i].titulo << endl;
        cout << "Autor: " << vet[i].autor << endl;
        cout << "Edicao: " << vet[i].edicao << endl;
    }
    cout << " ---------------------------------\n";
}

int main(){
    Usuario listaUsuario[MAX];
    Livro listaLivro[MAX];

    int contUsuario = 0;
    int contLivro = 0;
    int opcao;

    while(true){
        mostrarMenu();
        cin >> opcao;

        if(opcao == 0){
            break;
        }
        switch(opcao) {
            case 1:
                cadastrarUsuario(listaUsuario, contUsuario);
                contUsuario ++;
                break;
            case 2:
                cadastrarLivro(listaLivro, contLivro);
                contLivro ++;
                break;
            case 3:
                mostrarUsuario(listaUsuario, contUsuario);
                break;
            case 4:
                mostrarLivro(listaLivro, contLivro);
                break;
            default:
                cout << "Opcao Invalida. Digite novamente.\n\n";
                break;
          }

    }
 return 0;
}
