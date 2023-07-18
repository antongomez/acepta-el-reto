#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>

std::vector<std::string> splitString(const std::string &input, char delimiter)
{
    std::vector<std::string> tokens;
    std::stringstream ss(input);
    std::string token;
    // Lee el primer token
    if (std::getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }
    // Obtiene el resto de la línea como el segundo token
    if (std::getline(ss, token))
    {
        tokens.push_back(token);
    }
    return tokens;
}

// Función auxiliar para comparar dos pares de clave-valor por valor (segundo elemento)
bool compararPorValor(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b)
{
    if (a.second > b.second)
        return true;
    else if (a.second == b.second)
    {
        return a.first < b.first;
    }
    else
    {
        return false;
    }
}

int main()
{
    std::string line;
    std::getline(std::cin, line);
    int n_series = std::stoi(line);

    // Lee la entrada estándar línea por línea hasta el final
    while (n_series != 0)
    {
        n_series = std::stoi(line);
        std::vector<std::pair<std::string, int>> series;

        // Lemos todas as series de cada usuario
        for (int i = 0; i < n_series; i++)
        {
            std::getline(std::cin, line);
            std::vector<std::string> tokens = splitString(line, ' ');

            bool atopado = false;
            int minutos = std::stoi(tokens[0]);

            for (auto &it : series)
            {
                if (it.first == tokens[1])
                {
                    it.second += minutos;
                    atopado = true;
                }
            }

            if (atopado == false)
            {
                series.push_back({tokens[1], minutos});
            }
        }

        // Ordeamos as series de cada usuario por valor e en caso de empate, por orde lexicografico do nome da serie
        std::sort(series.begin(), series.end(), compararPorValor);

        // Imprimimos as series
        for (int i = 0; i < series.size(); i++)
        {
            if ((series[i].second < 30) || (i >= 3))
            {
                break;
            }
            std::cout << series[i].first << std::endl;
        }

        std::getline(std::cin, line);
        n_series = std::stoi(line);
        std::cout << "---" << std::endl;
    }

    return 0;
}