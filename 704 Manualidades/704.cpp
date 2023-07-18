#include <iostream>
#include <map>
#include <sstream>
#include <vector>

// Funcion que divide en tokens a cadea de entrada como maximo maxDivisions
std::vector<std::string> splitString(const std::string &input, char delimiter, int maxDivisions)
{
  std::vector<std::string> tokens;
  std::stringstream ss(input);
  std::string token;

  for (int i = 0; i < maxDivisions; i++)
  {
    if ((i == (maxDivisions - 1)) && std::getline(ss, token))
    {
      tokens.push_back(token);
    }
    else if (std::getline(ss, token, delimiter))
    {
      tokens.push_back(token);
    }
    else
    {
      break;
    }
  }

  return tokens;
}

int main()
{
  std::string line;
  std::getline(std::cin, line);
  int nCasosProba = std::stoi(line);

  for (int i = 0; i < nCasosProba; i++)
  {
    // Variables para determianr cando se poden cubrir ambas partes do marco
    bool ancho = false, alto = false;
    std::getline(std::cin, line);
    std::vector<std::string> tokens_dimensions = splitString(line, ' ', 2);
    int palos_ancho = std::stoi(tokens_dimensions[0]);
    int palos_alto = std::stoi(tokens_dimensions[1]);

    std::getline(std::cin, line);
    std::vector<std::string> tokens_n_palitos = splitString(line, ' ', 100000000);
    int maior, menor;
    if (palos_ancho > palos_alto)
    {
      maior = palos_ancho;
      menor = palos_alto;
    }
    else
    {
      maior = palos_alto;
      menor = palos_ancho;
    }
    for (int j = 1; j <= std::stoi(tokens_n_palitos[0]); j++)
    {
      if (!ancho && (std::stoi(tokens_n_palitos[j]) >= 2 * maior))
      {
        ancho = true;
        if (alto)
          break;
      }
      else if (!alto && (std::stoi(tokens_n_palitos[j]) >= 2 * menor))
      {
        alto = true;
        if (ancho)
          break;
      }
    }

    if (alto && ancho)
    {
      std::cout << "SI" << std::endl;
    }
    else
    {
      std::cout << "NO" << std::endl;
    }
  }

  return 0;
}