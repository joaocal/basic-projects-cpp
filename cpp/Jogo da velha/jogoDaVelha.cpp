#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool verificarVitoria(vector<char> interfaceJogo, char jogadorA, char jogadorB);
void mostrarInterface(vector<char> interfaceJogo);

int main()
{
    vector<char> interfaceJogo = {
        '#', '#', '#',
        '#', '#', '#',
        '#', '#', '#'
    };

    char jogador;
    char oponente;
    int posicaoJogada;
    bool ganhou = false;

    cout << "Escolha X ou O para jogar... " << endl;
    cin >> jogador;

    if (jogador == 'X') {
        oponente = 'O';
    } else if (jogador == 'O') {
        oponente = 'X';
    }

    int jogadas = 0;
    while (!ganhou && jogadas < 9) {
        // Monta a interface do jogo no terminal
        mostrarInterface(interfaceJogo);

        cout << "[Jogador] Escolha uma posição para jogar... " << endl;
        cin >> posicaoJogada;

        while (!isdigit(posicaoJogada)) {
            cout << "Entrada inválida! Escolha uma posição para jogar... " << endl;
            cin >> posicaoJogada;
        }

        while (interfaceJogo[posicaoJogada - 1] != '#') {
            cout << "Posição já preenchida! Escolha outra posição... " << endl;
            cin >> posicaoJogada;
        }

        interfaceJogo[posicaoJogada - 1] = jogador;

        // Atualiza a interface do jogo no terminal
        mostrarInterface(interfaceJogo);

        cout << "[Oponente] Escolha uma posição para jogar... " << endl;
        cin >> posicaoJogada;

        while (!isdigit(posicaoJogada)) {
            cout << "Entrada inválida! Escolha uma posição para jogar... " << endl;
            cin >> posicaoJogada;
        }

        while (interfaceJogo[posicaoJogada - 1] != '#') {
            cout << "Posição já preenchida! Escolha outra posição... " << endl;
            cin >> posicaoJogada;
        }

        interfaceJogo[posicaoJogada - 1] = oponente;

        ganhou = verificarVitoria(interfaceJogo, jogador, oponente);
        if (ganhou) {
            break;
        }

        jogadas++;
    }

    return 0;
}

void mostrarInterface(vector<char> interfaceJogo) {
    cout << interfaceJogo[0] << "   " << interfaceJogo[1] << "   " << interfaceJogo[2] << endl
         << interfaceJogo[3] << "   " << interfaceJogo[4] << "   " << interfaceJogo[5] << endl
         << interfaceJogo[6] << "   " << interfaceJogo[7] << "   " << interfaceJogo[8] << endl;
}

bool verificarVitoria(vector<char> interfaceJogo, char jogadorA, char jogadorB) {
    // Possibilidades de vitória para o jogador
        if (interfaceJogo[0] == jogadorA && interfaceJogo[1] == jogadorA && interfaceJogo[2] == jogadorA) {
            cout << "[Jogador] Parabéns! Você venceu!" << endl;
            return true;
        } else if (interfaceJogo[0] == jogadorA && interfaceJogo[4] == jogadorA && interfaceJogo[8] == jogadorA) {
            cout << "[Jogador] Parabéns! Você venceu!" << endl;
            return true;
        } else if (interfaceJogo[0] == jogadorA && interfaceJogo[3] == jogadorA && interfaceJogo[6] == jogadorA) {
            cout << "[Jogador] Parabéns! Você venceu!" << endl;
            return true;
        } else if (interfaceJogo[6] == jogadorA && interfaceJogo[7] == jogadorA && interfaceJogo[8] == jogadorA) {
            cout << "[Jogador] Parabéns! Você venceu!" << endl;
            return true;
        } else if (interfaceJogo[2] == jogadorA && interfaceJogo[5] == jogadorA && interfaceJogo[8] == jogadorA) {
            cout << "[Jogador] Parabéns! Você venceu!" << endl;
            return true;
        } else if (interfaceJogo[3] == jogadorA && interfaceJogo[4] == jogadorA && interfaceJogo[5] == jogadorA) {
            cout << "[Jogador] Parabéns! Você venceu!" << endl;
            return true;
        }

        // Possibilidades de vitória para o oponente
        if (interfaceJogo[0] == jogadorB && interfaceJogo[1] == jogadorB && interfaceJogo[2] == jogadorB) {
            cout << "[Oponente] Parabéns! Você venceu!" << endl;
            return true;
        } else if (interfaceJogo[0] == jogadorB && interfaceJogo[4] == jogadorB && interfaceJogo[8] == jogadorB) {
            cout << "[Oponente] Parabéns! Você venceu!" << endl;
            return true;
        } else if (interfaceJogo[0] == jogadorB && interfaceJogo[3] == jogadorB && interfaceJogo[6] == jogadorB) {
            cout << "[Oponente] Parabéns! Você venceu!" << endl;
            return true;
        } else if (interfaceJogo[6] == jogadorB && interfaceJogo[7] == jogadorB && interfaceJogo[8] == jogadorB) {
            cout << "[Oponente] Parabéns! Você venceu!" << endl;
            return true; 
        } else if (interfaceJogo[2] == jogadorB && interfaceJogo[5] == jogadorB && interfaceJogo[8] == jogadorB) {
            cout << "[Oponente] Parabéns! Você venceu!" << endl;
            return true;
        } else if (interfaceJogo[3] == jogadorB && interfaceJogo[4] == jogadorB && interfaceJogo[5] == jogadorB) {
            cout << "[Oponente] Parabéns! Você venceu!" << endl;
            return true;
        }

        return false;
}