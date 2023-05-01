#include <iostream>
#include <string>
#include <vector>

std::string gerarMensagem(std::vector<std::string> lista, std::vector<int> prioridades);

int main() {
    std::vector<std::string> listaDeTarefas;
    std::vector<std::string> listaDeVencimento;
    std::vector<int> prioridadeTarefas;
    std::string tarefasDoUsuario;
    std::string inputUsuario;
    std::string mensagem;
    std::string vencimentoInput;
    int prioridadesUsuario;
    int tarefa;

    while (inputUsuario != "404") {
        std::cout << "[1]: Tarefas\n[2]: Alterar prioridades\n[404]: Sair" << std::endl;
        std::cin >> inputUsuario;

        if (inputUsuario == "1") {
            std::cout << "[1] Adicionar tarefas\n[2] Editar tarefas\n[3] Excluir tarefas\n[4] Datas de vencimento" << std::endl;
            std::cin >> inputUsuario;

            if (inputUsuario == "1") {
                while (tarefasDoUsuario != "sair") {
                    std::cout << "[Digite \"sair\" para sair] Adicione uma tarefa: " << std::endl;
                    std::cin >> tarefasDoUsuario;

                    if (tarefasDoUsuario != "sair")
                        listaDeTarefas.push_back(tarefasDoUsuario);
                    
                }

            } else if (inputUsuario == "2") {
                mensagem = gerarMensagem(listaDeTarefas, prioridadeTarefas);

                std::cout << mensagem << std::endl;

                std::cout << "Digite a posição da tarefa que deseja alterar... " << std::endl;
                std::cin >> tarefa;

                std::cout << "[digite \"sair\" para sair] Digite o nome da tarefa... ";
                std::cin >> tarefasDoUsuario;

                listaDeTarefas[tarefa - 1] = tarefasDoUsuario;
            } else if (inputUsuario == "3") {
                mensagem = gerarMensagem(listaDeTarefas, prioridadeTarefas);

                std::cout << mensagem << std::endl;

                std::cout << "Digite a posição da tarefa que deseja excluir... " << std::endl;
                std::cin >> tarefa;

                listaDeTarefas.erase(listaDeTarefas.begin() + tarefa - 1);
            } else if (inputUsuario == "4") {
                mensagem = "";
                if (!listaDeVencimento.empty()) {
                    for (int indice = 0; indice < listaDeTarefas.size(); indice++) {
                        mensagem = mensagem + "[" + listaDeVencimento[indice] + "] " + listaDeTarefas[indice] + ",  ";
                    }

                    std::cout << mensagem << std::endl;
                } else {
                    std::cout << "Defina uma data de vencimento para cada item... " << std::endl;

                    mensagem = gerarMensagem(listaDeTarefas, prioridadeTarefas);

                    std::cout << mensagem << std::endl;

                    for (int indice = 0; indice < listaDeTarefas.size(); indice++) {
                        std::cout << "Digite um data de vencimento para a " << indice + 1 << "° tarefa" << std::endl;
                        std::cin >> vencimentoInput;

                        listaDeVencimento.push_back(vencimentoInput);
                    }
                }
            } else if (inputUsuario == "5") {
                mensagem = gerarMensagem(listaDeTarefas, prioridadeTarefas);

                std::cout << mensagem << std::endl;
            }
            
        } else if (inputUsuario == "2") {
            if (!prioridadeTarefas.empty()) {
                while (prioridadesUsuario != 99) {
                    mensagem = gerarMensagem(listaDeTarefas, prioridadeTarefas);

                    std::cout << mensagem << std::endl;
                    std::cout << "insira a posição da tarefa que deseja alterar a prioridade... ";
                    std::cin >> tarefa;

                    std::cout << "[99 para sair] insira a prioridade que deseja... ";
                    std::cin >> prioridadesUsuario;

                    prioridadeTarefas[tarefa - 1] = prioridadesUsuario;

                }

            } else {
                mensagem = "";

                std::cout << "Crie prioridades" << std::endl;

                for (int indiceTarefa = 0; indiceTarefa < listaDeTarefas.size(); indiceTarefa++) {
                    mensagem = mensagem + listaDeTarefas[indiceTarefa] + ",  ";
                }

                std::cout << mensagem << std::endl;

                for (int i = 0; i < listaDeTarefas.size(); i++) {
                    std::cout << "Digite a prioridade da primeira tarefa... ";
                    std::cin >> prioridadesUsuario;

                    prioridadeTarefas.push_back(prioridadesUsuario);
                }

            }

        }
    }

}

std::string gerarMensagem(std::vector<std::string> lista, std::vector<int> prioridades) {
    std::string mensagem;
    if (!prioridades.empty()) {
        for (int indiceTarefa = 0; indiceTarefa < lista.size(); indiceTarefa++) {
            mensagem = mensagem + "[" + std::to_string(prioridades[indiceTarefa]) + "] " + lista[indiceTarefa] + ",  ";
        }
    } else {
        mensagem = "Você precisa definir as prioridades primeiro!";
    }
    return mensagem;
}