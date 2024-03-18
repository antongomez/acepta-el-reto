#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main()
{

  // Desvincula a E/S entre C++ e C
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::cin.ignore();

  for (int i = 0; i < n; i++)
  {
    std::vector<std::string> nomes;

    std::string linea;
    std::getline(std::cin, linea);

    std::stringstream ss(linea);
    std::string nome;

    while (ss >> nome)
    {
      if (nome == "F")
        break;
      nomes.push_back(nome);
    }

    int n = nomes.size();

    std::string aux;

    ss >> aux;
    int camas = std::stoi(aux);

    ss >> aux;
    int palabras = std::stoi(aux);

    if (camas >= n)
      std::cout << "TODOS TIENEN CAMA\n";
    else if (camas == 0)
      std::cout << "NADIE TIENE CAMA\n";
    else
    {
      int ind = 0;
      int n_actual = n;
      palabras--; // Axustamos para operar en aritmetica modular
      for (int i = 0; i < (n - camas); i++)
      {
        ind = (ind + palabras) % n_actual;
        nomes.erase(nomes.begin() + ind);
        n_actual--;
        if (ind == n_actual) // Axustamos no caso de que o indice eliminado sexa o ultimo
          ind = 0;
      }
      for (int i = 0; i < n_actual; i++)
      {
        std::cout << nomes[i];
        if (i < n_actual - 1)
          std::cout << " ";
      }
      std::cout << "\n";
    }
  }

  return 0;
}