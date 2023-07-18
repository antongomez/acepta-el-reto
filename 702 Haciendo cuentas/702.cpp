#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

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

bool compararPorValor(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
  return a.second > b.second;
}

int main()
{
  std::string line;
  std::getline(std::cin, line);
  int n_unidades = std::stoi(line);
  if (n_unidades == 0)
  {
    exit(0);
  }
  std::getline(std::cin, line);
  int n_bloques = std::stoi(line);

  while (n_bloques != 0)
  {

    std::vector<std::pair<int, int>> unidades_caducidade;

    // Lemos os bloques de unidades
    for (int i = 0; i < n_bloques; i++)
    {
      std::getline(std::cin, line);
      std::vector<std::string> tokens = splitString(line, ' ');
      unidades_caducidade.push_back({std::stoi(tokens[0]), std::stoi(tokens[1])});
    }

    // Ordeamos os bloques de forma que seleccionamos antes aqueles bloques que tenhen unha data mais tardia
    std::sort(unidades_caducidade.begin(), unidades_caducidade.end(), compararPorValor);

    // Collemos os bloques en orde
    int suma = n_unidades;
    for (unsigned int i = 0; i < unidades_caducidade.size(); i++)
    {
      suma -= unidades_caducidade[i].first;
      if (suma <= 0)
      {
        std::cout << unidades_caducidade[i].second << std::endl;
        break;
      }
    }

    if (suma > 0)
    {
      std::cout << unidades_caducidade[unidades_caducidade.size() - 1].second << std::endl;
    }

    // Lemos a seguinte linha
    std::getline(std::cin, line);
    n_unidades = std::stoi(line);
    if (n_unidades == 0)
    {
      break;
    }

    std::getline(std::cin, line);
    n_bloques = std::stoi(line);
  }

  return 0;
}