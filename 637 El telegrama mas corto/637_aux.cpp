#include <iostream>
#include <map>
#include <string>

// Programa auxiliar para contar o numero de puntos de cada letra.
// No programa principal empregamos directamente o map que devolve
// a funcion `contraPuntosLetra`

std::map<char, int> contarPuntosLetra(std::map<char, std::string> codigoMorse)
{
    std::map<char, int> puntosLetra;

    for (auto iter : codigoMorse)
    {
        int puntos = 0;
        for (char c : iter.second)
        {
            if (c == '.')
            {
                puntos++;
            }
            else
            {
                puntos += 3;
            }
        }
        // Sumamos os puntos correspondentes a meter un punto entre cada simbolo de cada letra
        puntos += (iter.second.length() - 1);
        puntosLetra[iter.first] = puntos;
    }

    return puntosLetra;
}

int main()
{
    // Transcripcion a codigo morse do alfabeto ingles
    std::map<char, std::string> codigoMorse = {
        {'A', ".-"},
        {'B', "-..."},
        {'C', "-.-."},
        {'D', "-.."},
        {'E', "."},
        {'F', "..-."},
        {'G', "--."},
        {'H', "...."},
        {'I', ".."},
        {'J', ".---"},
        {'K', "-.-"},
        {'L', ".-.."},
        {'M', "--"},
        {'!', "-.-.--"},
        {'N', "-."},
        {'O', "---"},
        {'P', ".--."},
        {'Q', "--.-"},
        {'R', ".-."},
        {'S', "..."},
        {'T', "-"},
        {'U', "..-"},
        {'V', "...-"},
        {'W', ".--"},
        {'X', "-..-"},
        {'Y', "-.--"},
        {'Z', "--.."},
        {'?', "..--.."},
    };

    std::map<char, int> puntosLetra = contarPuntosLetra(codigoMorse);

    // Imprimimos a lonxitude en "puntos" de cada letra do alfabeto ingles
    for (auto iter : puntosLetra)
    {
        std::cout << iter.first << " " << iter.second << std::endl;
    }

    return 0;
}