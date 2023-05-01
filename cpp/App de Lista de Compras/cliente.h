#include <vector>
#include <string>
#include <iostream>

class Cliente {
    private:
        vector<Produto> listaProdutos;
        vector<Produto> carrinho;
    public:
        Cliente();
        void getListaCliente();
        void getCarrinho();
        void adicionarItem(Produto produto);
        void adicionarAoCarrinho(Produto produto);

};

void Cliente::getListaCliente() {
    for (auto produto : listaProdutos) {
        cout << "Nome: " << produto.nome << " | Preço: R$" << produto.preco << endl;
    }
}

void Cliente::getCarrinho() {
    for (auto produto : carrinho) {
        cout << "Nome: " << produto.nome << " | Preço: R$" << produto.preco << endl;
    }
}

void Cliente::adicionarItem(Produto produto) {
    listaProdutos.push_back(produto);
}

void Cliente::adicionarAoCarrinho(Produto produto) {
    carrinho.push_back(produto);
}

Cliente::Cliente() : listaProdutos{}, carrinho{} {}