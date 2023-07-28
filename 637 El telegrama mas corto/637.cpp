#include <iostream>
#include <unordered_map>

int main()
{

    std::unordered_map<char, int> puntosCaracter = {
        {'!', 19},
        {'?', 15},
        {'A', 5},
        {'B', 9},
        {'C', 11},
        {'D', 7},
        {'E', 1},
        {'F', 9},
        {'G', 9},
        {'H', 7},
        {'I', 3},
        {'J', 13},
        {'K', 9},
        {'L', 9},
        {'M', 7},
        {'N', 5},
        {'O', 11},
        {'P', 11},
        {'Q', 13},
        {'R', 7},
        {'S', 5},
        {'T', 3},
        {'U', 7},
        {'V', 9},
        {'W', 9},
        {'X', 11},
        {'Y', 13},
        {'Z', 11}};

    // Desvinculamos as operacions de E/S de C++ das de C
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int casos;

    std::cin >> casos;
    std::string line;
    std::getline(std::cin, line);

    for (int i = 0; i < casos; i++)
    {

        std::getline(std::cin, line);

        int puntos = 0;

        char ant = ' ';

        for (char c : line)
        {
            // Entre palabras hai 5 puntos
            if (c == ' ')
            {
                puntos += 5;
            }
            else
            {
                puntos += puntosCaracter[c];

                // Entre letras dunha palabra hai 3 puntos
                if (ant != ' ')
                {
                    puntos += 3;
                }
            }

            ant = c;
        }

        std::cout << puntos << "\n";
    }

    return 0;
}