#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    string palavras_secretas[] = {"banana", "abutre", "mosntro", "admin", "nmap", "gobuster", "abuser", "coconomato", "macaco", "overdose"};
    int tamanho_lista = sizeof(palavras_secretas) / sizeof(palavras_secretas[0]);
    string palavra_secreta = palavras_secretas[rand() % tamanho_lista]; // Escolhe uma palavra aleatória da lista
    string palavra_mostrada;
    int erros = 0;
    char letra;

    // Duas chances para acertar a palavra
    int chances = palavra_secreta.length() * 2;

    // Adiciona o caracter "-" de acordo com a quantidade de letras me "palavra_secreta"
    palavra_mostrada.assign(palavra_secreta.length(), '-');

    while (erros < chances) {
        cout << palavra_mostrada << endl;
        cout << "Digite uma letra: ";
        cin >> letra;

        bool acertou = false;

        // Confere os acertos
        for (int indice_letra = 0; indice_letra <= palavra_secreta.length(); indice_letra++) {
            if (letra == palavra_secreta[indice_letra]) {
                palavra_mostrada[indice_letra] = letra;
                acertou = true;
            }
        }

        if (!acertou) {
            erros++;
        }

        // Confere o resultado
        if (palavra_mostrada == palavra_secreta) {
            cout << "Parabéns por acertar a palavra \"" << palavra_secreta << "\"!." << endl;
            break;
        }
    }

    if (erros >= chances) {
        cout << "Você perdeu! A palavra era \"" << palavra_secreta << "\".";
    }

    system("pause");

    return 0;
}