#include <iostream>
#include <string>

float converterMParaCM(float metros);
float converterCMParaM(float centimetros);
float converterMParaP(float metros);
float converterPParaM(float pes);
float converterCelsiusParaFarenheit(float celsius);
float converterFarenheitParaCelsius(float farenheit);

int main() {
    float fInputUsuario;
    float valorConvertido;
    std::string sInputUsuario;

    std::cout << "=====! Bem-vindo ao conversor de unidades! !=====\n" << std::endl;

    while (sInputUsuario != "3") {
        std::cout << "[1] Distância\n[2] Temperatura\n[3] Sair\n";
        std::cin >> sInputUsuario;

        if (sInputUsuario == "1") {
            while (sInputUsuario != "5") {
                std::cout << "[1] Metros para centímetros\n[2] Centímetros para metros\n[3] Metros para pés\n[4] Pés para metros\n[5] Voltar\n";
                std::cin >> sInputUsuario;

                if (sInputUsuario == "1") {
                    std::cout << "Digite a unidade em metros... ";
                    std::cin >> fInputUsuario;

                    valorConvertido = converterMParaCM(fInputUsuario);

                    std::cout << valorConvertido << " CM\n";
                } else if (sInputUsuario == "2") {
                    std::cout << "Digite a unidade em centímetros...";
                    std::cin >> fInputUsuario;

                    valorConvertido = converterCMParaM(fInputUsuario);

                    std::cout << valorConvertido << " M\n";
                } else if (sInputUsuario == "3") {
                    std::cout << "Digite a unidade em metros... ";
                    std::cin >> fInputUsuario;

                    valorConvertido = converterMParaP(fInputUsuario);

                    std::cout << valorConvertido << " pés\n";
                } else if (sInputUsuario == "4") {
                    std::cout << "Digite a unidade em pés... ";
                    std::cin >> fInputUsuario;

                    valorConvertido = converterPParaM(fInputUsuario);

                    std::cout << valorConvertido << " M\n";
                }
            }

        } else if (sInputUsuario == "2") {
            while (sInputUsuario != "3") {
                std::cout << "[1] Celsius para Farenheit\n[2] Farenheit para Celsius\n[3] Sair\n";
                std::cin >> sInputUsuario;

                if (sInputUsuario == "1") {
                    std::cout << "Digite a unidade em Celsius... ";
                    std::cin >> fInputUsuario;

                    std::cout << converterCelsiusParaFarenheit(fInputUsuario) << " °F";
                } else if (sInputUsuario == "2") {
                    std::cout << "Digite a unidade em Farenheit... ";
                    std::cin >> fInputUsuario;

                    std::cout << converterFarenheitParaCelsius(fInputUsuario) << " °C";
                }
            }
        }

    }

    return 0;
}

float converterMParaCM(float metros) {
    return metros * 100;
}

float converterCMParaM(float centimetros) {
    return centimetros / 100;
}

float converterPParaM(float pes) {
    return pes / 3.281;
}

float converterMParaP(float metros) {
    return metros * 3.281;
}

float converterCelsiusParaFarenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float converterFarenheitParaCelsius(float farenheit) {
    return (farenheit - 32) * 5 / 9;
}