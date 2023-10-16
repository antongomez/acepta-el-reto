#include <iostream>
#include <string>

int main()
{

  // Desvinculamos E/S de C++ e C
  std::ios_base::sync_with_stdio(false);
  // Desactivamos a sincronización entre entrada e saida
  std::cin.tie(nullptr);

  std::string palabra;

  while (std::cin >> palabra)
  {

    // Imos probando con distintos tamaños de posibles subdivisions da palabra
    // dende 1 ata palabra.size()
    for (int i = 1; i <= (int)palabra.size(); i++)
    {
      // Se o tam da palabra non é divisible entre i non pode ser i-ciclica
      if (palabra.size() % i != 0)
        continue;

      bool ciclo = true;
      // Percorremos a palabra e comprobamos se a palabra é i-ciclica
      for (int j = i; j < (int)palabra.size(); j++)
      {
        if (std::tolower(palabra[j]) != std::tolower(palabra[j % i]))
        {
          ciclo = false;
          break;
        }
      }
      if (ciclo)
      {
        std::cout << i << "\n";
        break;
      }
    }
  }

  return 0;
}