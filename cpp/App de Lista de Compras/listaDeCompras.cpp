#include "loja.h"
#include "cliente.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void menuDeAcoes(Cliente& cliente, vector<Produto> produtosDaLoja, int iInputUsuario);

int main() {
    Cliente cliente;
    Loja loja;
    vector<Produto> produtosDaLoja = loja.pGetProduto();
    string sInputUsuario = "";
    int iInputUsuario = 0;

    while (sInputUsuario != "4") {
        cout << "[1]: Ir para loja\n[2]: Ver seu carrinho\n[3] Itens comprados\n[Enter] Para sair\n";
        cin >> sInputUsuario;

        if (sInputUsuario == "1") {
            loja.getProdutos();

            while (iInputUsuario != 99) {
                cout << "Digite a posição do produto para escolher as ações... ";
                cin >> iInputUsuario;

                if (cin.fail() || iInputUsuario == 99) {
                    cout << "Saindo\n";
                    iInputUsuario = 0;
                    break;
                }

                cout << "Nome: " << produtosDaLoja[iInputUsuario - 1].nome << " | R$" << produtosDaLoja[iInputUsuario - 1].preco << endl;
                menuDeAcoes(cliente, produtosDaLoja, iInputUsuario - 1);
            }
        } else if (sInputUsuario == "2") {
            cliente.getCarrinho();

            while (iInputUsuario != 99) {
                cout << "Digite a posição do produto para escolher as ações... ";
                cin >> iInputUsuario;

                if (cin.fail() || iInputUsuario == 99) {
                    cout << "Saindo\n";
                    iInputUsuario = 0;
                    break;
                }

                cout << "Nome: " << produtosDaLoja[iInputUsuario - 1].nome << " | R$" << produtosDaLoja[iInputUsuario - 1].preco << endl;
                menuDeAcoes(cliente, produtosDaLoja, iInputUsuario - 1);
            }
        } else if (sInputUsuario == "3") {
            cliente.getListaCliente();
        }
    }
}

void menuDeAcoes(Cliente& cliente, vector<Produto> produtosDaLoja, int iInputUsuario) {
    string sInputUsuario;

    cout << "[1] Comprar\n[2] Adicionar à lista de compras\n[3] Cancelar\n";
    cin >> sInputUsuario;

    if (sInputUsuario == "1") {
        cliente.adicionarItem(produtosDaLoja[iInputUsuario]);
    } else if (sInputUsuario == "2") {
        cliente.adicionarAoCarrinho(produtosDaLoja[iInputUsuario]);
    }
}