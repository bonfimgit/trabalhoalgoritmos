#include <iostream>
#include <locale>
#include <string>
#include <vector>
using namespace std;

struct TProduto
{
    string nome, desc; // descri��o
    float preco;
    int quant, codigo;
};

int main()
{
    setlocale(LC_ALL, "portuguese");    
    int opc, posicao = 0;
    string busca;
    bool achei = false;
    vector<TProduto> produtos; // vetor para armazenar produtos

    do {
        cout << "LOJINHA TECH MAIS\n";
        cout << "1 - Cadastrar\n";
        cout << "2 - Pesquisar\n";
        cout << "3 - Alterar\n";
        cout << "4 - Excluir\n";
        cout << "5 - Sair\n"; // Alterado para "Sair"
        cout << "Qual a op��o? ";
        cin >> opc;
        cin.ignore(); // limpar entrada

        switch (opc) {
            case 1: 
            {
                TProduto produto;
                cout << "Nome do produto: "; 
                getline(cin, produto.nome);
                cout << "C�digo do produto: "; 
                cin >> produto.codigo;
                cin.ignore(); // limpar dados de entrada
                cout << "Descri��o: ";
                getline(cin, produto.desc);
                cout << "Pre�o: "; 
                cin >> produto.preco;
                cout << "Quantidade em estoque: "; 
                cin >> produto.quant;
                produtos.push_back(produto);
                cout << "Produto cadastrado com sucesso!\n";
                break;
            }
            case 2: 
            {    
                cout << "Qual sua prefer�ncia de pesquisa?\n1 - Nome\n2 - C�digo\n";      
                int opcaopesquisa;
                cin >> opcaopesquisa;
                cin.ignore();
                achei = false;

                if (opcaopesquisa == 1) {
                    cout << "Digite o nome do produto: ";
                    getline(cin, busca);
                    for (posicao = 0; posicao < produtos.size(); posicao++) {
                        if (produtos[posicao].nome == busca) {
                            cout << "Produto: " << produtos[posicao].nome << endl;
                            cout << "C�digo: " << produtos[posicao].codigo << endl;
                            cout << "Descri��o: " << produtos[posicao].desc << endl;
                            cout << "Pre�o: " << produtos[posicao].preco << endl;
                            cout << "Quantidade: " << produtos[posicao].quant << endl;
                            achei = true;
                            break; 
                        }
                    }
                } else if (opcaopesquisa == 2) {
                    cout << "Digite o c�digo do produto: ";
                    int pesquisacodigo;
                    cin >> pesquisacodigo;
                    cin.ignore();
                    for (posicao = 0; posicao < produtos.size(); posicao++) {
                        if (produtos[posicao].codigo == pesquisacodigo) {
                            cout << "Produto: " << produtos[posicao].nome << endl;
                            cout << "C�digo: " << produtos[posicao].codigo << endl;
                            cout << "Descri��o: " << produtos[posicao].desc << endl;
                            cout << "Pre�o: " << produtos[posicao].preco << endl;
                            cout << "Quantidade: " << produtos[posicao].quant << endl;
                            achei = true;
                            break;
                        }
                    }
                } else {
                    cout << "Op��o inv�lida\n";
                }

                if (!achei) {
                    cout << "Produto n�o cadastrado\n";
                }
                break;
            }
            case 3: 
            {
                cout << "Digite o c�digo do produto que deseja alterar: ";
                int codAlterar;
                cin >> codAlterar;
                cin.ignore();
                achei = false;

                for (posicao = 0; posicao < produtos.size(); posicao++) {
                    if (produtos[posicao].codigo == codAlterar) {
                        cout << "Produto encontrado: " << produtos[posicao].nome << endl;
                        cout << "Digite os novos dados:\n";
                        cout << "Nome: ";
                        getline(cin, produtos[posicao].nome);
                        cout << "Descri��o: ";
                        getline(cin, produtos[posicao].desc);
                        cout << "Pre�o: ";
                        cin >> produtos[posicao].preco;
                        cout << "Quantidade: ";
                        cin >> produtos[posicao].quant;
                        achei = true;
                        cout << "Produto alterado com sucesso!\n";
                        break;
                    }
                }

                if (!achei) {
                    cout << "Produto n�o encontrado.\n";
                }
                break;
            }
            case 4: 
            {
                cout << "Digite o c�digo do produto que deseja excluir: ";
                int codExcluir;
                cin >> codExcluir;
                cin.ignore();
                achei = false;

                for (posicao = 0; posicao < produtos.size(); posicao++) {
                    if (produtos[posicao].codigo == codExcluir) {
                        produtos.erase(produtos.begin() + posicao);
                        achei = true;
                        cout << "Produto exclu�do com sucesso!\n";
                        break;
                    }
                }

                if (!achei) {
                    cout << "Produto n�o encontrado.\n";
                }
                break;
            }
            default: 
            {
                if (opc != 5) {
                    cout << "Op��o inv�lida, tente novamente.\n";
                }
                break;
            }
        }
    } while (opc != 5);

    return 0;
}


