#include <iostream>

using namespace std;

int main()
{
    int userChoice, numberA, numberB,
        sum, sub, multiply, division;

    cout << "Primeiro número: ";
    cin >> numberA;

    cout << "Segundo número: ";
    cin >> numberB;

    cout << "[1]: Adição\n[2]: Subtração\n[3]: Multiplicação\n[4]: Divisão\nEscolha uma operação... ";
    cin >> userChoice;

    sum = numberA + numberB;
    sub = numberA - numberB;
    multiply = numberA * numberB;
    division = numberA / numberB;

    switch (userChoice)
    {
    case 1:
        cout << sum;
        break;
    
    case 2:
        cout << sub;
        break;

    case 3:
        cout << multiply;
        break;
    
    case 4:
        cout << division;
        break;

    default:
        break;
    }

    return 0;
}
