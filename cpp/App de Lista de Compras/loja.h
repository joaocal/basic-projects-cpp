#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Produto {
    public:
        string nome;
        double preco;
        bool comprado;
};

class Loja {
    private:
        vector<Produto> produtos;

    public:
        Loja();
        void adicionarProduto(Produto produto);
        void getProdutos();
        vector<Produto> pGetProduto();

};

// Construtor da classe
Loja::Loja() {
    // Inicializa a lista de produtos da loja
    Produto produto1 = {"Calça Jeans", 29.99, false};
    produtos.push_back(produto1);

    Produto produto2 = {"Calça Arrojada", 59.99, false};
    produtos.push_back(produto2);

    Produto produto3 = {"Calça Camuflada", 199.99, false};
    produtos.push_back(produto3);

    Produto produto4 = {"Calça Cargo", 2.50, false};
    produtos.push_back(produto4);

    Produto produto5 = {"Calça da Dilma", 1000, false};
    produtos.push_back(produto5);
}

// Imprime todos os produtos
void Loja::getProdutos() {
    for (auto produto : produtos) {
        cout << "Nome: " << produto.nome << " | Preço: R$" << produto.preco << endl;
    }
}

// adiciona um novo produto à loja
void Loja::adicionarProduto(Produto produto) {
    produtos.push_back(produto);
}

// Retorna a lista dos produtos do tipo vector<Produto>
vector<Produto> Loja::pGetProduto() {
    return produtos;
}
