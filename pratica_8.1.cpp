#include <iostream>

#define MAX 10

using namespace std;

// Definir a struct de Funcionário
struct Funcionario {
    int codigo;
    string nome;
    string telefone;
};

// Definir a struct de Tipo de Produto
struct TipodeProduto {
    int id;
    string nome;
};

// Definir a struct de Produto
struct Produto {
    string nome;
    float valor;
    int id_tipo_produto;
};

// Procedimento para exibir um menu de opções
void mostrarMenu(){
    cout << "################## MENU ###################\n";
    cout << "# 1 - Cadastrar Funcionario               #\n";
    cout << "# 2 - Mostrar Funcionario(s) Cadastrado(s)#\n";
    cout << "# 3 - Cadastrar Tipo de Produto           #\n";
    cout << "# 4 - Mostrar Tipo de Produto Cadastrado  #\n";
    cout << "# 5 - Cadastrar Produto                   #\n";
    cout << "# 6 - Mostrar Produto Cadastrado          #\n";
    cout << "# 0 - Sair                                #\n";
    cout << "###########################################\n\n";
    cout << "Digite sua opcao:";
}

// Procedimento para cadstrar um novo funcionário
void cadastrarFuncionario(Funcionario vet[], int i){
    cout << "Digite o id: " << endl;
    cin >> vet[i].codigo;
    cin.ignore();
    cout << "Digite o nome: " << endl;
    getline(cin, vet[i].nome);
    cout << "Digite o telefone: " << endl;
    cin >> vet[i].telefone;
}

// Procedimento para exibir os funcionários cadastrados
void mostrarFuncionarios(Funcionario vet[] , int n){
    cout << "Funcionarios cadastrados: \n";
    for(int i=0; i<n;i++){
        cout << " ---------------------------------\n";
        cout << "Codigo: " << vet[i].codigo << endl;
        cout << "Nome: " << vet[i].nome << endl;
        cout << "Telefone: " << vet[i].telefone << endl;

    }
    cout << " ---------------------------------\n";
}

// Procedimento para cadastrar um novo tipo de produto
void cadastrarTipodeproduto(TipodeProduto vet[], int i){
    cout << "Digite o ID: ";
    cin >> vet[i].id;
    cout << "Digite o nome: ";
    cin >> vet[i].nome;
}

// Procedimento para exibir os tipos de produtos cadastrados
void mostrarTipoproduto(TipodeProduto vet[] , int n){
    cout << "Tipos de Produtos cadastrados: \n";
    for(int i=0; i<n;i++){
        cout << " ---------------------------------\n";
        cout << "ID: " << vet[i].id << endl;
        cout << "Nome: " << vet[i].nome << endl;
    }
    cout << " ---------------------------------\n";
}

//Procedimento para buscar o tipo de produto
void buscaTipoProduto(TipodeProduto vet[], Produto bet[], int j, int h){
    for(int i = 0; i < j; i++){
        vet[i].id;
        for(int n = 0; n < h; i++){
            bet[h].id_tipo_produto;
            if(vet[i].id == bet[h].id_tipo_produto);
        }
    }
}

// Procedimento para cadastrar um produto
void cadastrarProduto(Produto vet[], int d){
    cout << "Digite o Nome do Produto: ";
    cin >> vet[d].nome ;
    cout << "Digite o Valor: ";
    cin >> vet[d].valor ;
    cout << "Digite o ID do tipo do produto: ";
    cin >> vet[d].id_tipo_produto;
}

// Procedimento para exibir os tipos de produtos cadastrados
void mostrarProduto(Produto vet[] , int n){
    cout << "Produtos cadastrados: \n";
    for(int i=0; i<n;i++){
        cout << " ---------------------------------\n";
        cout << "Nome: " << vet[i].nome << endl;
        cout << "Valor: " << vet[i].valor << endl;
        cout << "Tipo de Produto" <<vet[i].id_tipo_produto << endl;
    }
    cout << " ---------------------------------\n";
}
int main(){
    // Declarar um vetor de funcionários
    Funcionario listaFuncionario[MAX];
    TipodeProduto listaTipodeproduto[MAX];
    Produto listaProduto[MAX];

    // Contador de funcionários
    int contFuncionarios = 0;
    int contTipoprodutos = 0;
    int contProdutos = 0;
    int opcao;

    while(true) {
        mostrarMenu();
        cin >> opcao;

        if(opcao == 0){
            break;
        }
        switch(opcao) {
            case 1:
                cadastrarFuncionario(listaFuncionario, contFuncionarios);
                contFuncionarios ++;
                break;
            case 2:
                mostrarFuncionarios(listaFuncionario, contFuncionarios);
                break;
            case 3:
                cadastrarTipodeproduto(listaTipodeproduto, contTipoprodutos++);
                break;
            case 4:
                mostrarTipoproduto(listaTipodeproduto, contTipoprodutos);
                break;
            case 5:
                cadastrarProduto(listaProduto, contProdutos++);
                buscaTipoProduto(listaTipodeproduto, listaProduto ,contTipoprodutos ,contProdutos);
                break;
            case 6:
                mostrarProduto(listaProduto, contProdutos);
                break;
            default:
                cout << "Opcao Invalida. Digite novamente.\n\n";
                break;
        }
    }
    return 0;
}
