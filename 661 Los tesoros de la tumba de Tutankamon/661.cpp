#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

bool comparadorValorPeso(const std::tuple<int, std::string, int, int> &a, const std::tuple<int, std::string, int, int> &b)
{
  if (std::get<2>(a) == std::get<2>(b))
  {
    if (std::get<3>(a) == std::get<3>(b))
    {
      return std::get<0>(a) < std::get<0>(b); // indice
    }
    else
    {
      return std::get<3>(a) < std::get<3>(b); // peso
    }
  }
  else
  {
    return std::get<2>(a) > std::get<2>(b); // valor
  }
}

int main()
{

  // Desvinculamos E/S de C++ e C
  std::ios_base::sync_with_stdio(false);
  // Desactivamos a sincronización entre entrada e saida
  std::cin.tie(nullptr);

  int N;

  // Lemos o primeiro caso
  std::cin >> N;

  while (N > 0)
  {
    std::vector<std::tuple<int, std::string, int, int>> obxectos(N);
    for (int i = 0; i < N; i++)
    {
      std::string obxecto;
      int valor, peso;

      std::cin >> obxecto >> valor >> peso;

      obxectos[i] = std::make_tuple(i, obxecto, valor, peso);
    }
    // Ordeamos os obxectos de maior a menor valor e de menor a maior peso
    std::sort(obxectos.begin(), obxectos.end(), comparadorValorPeso);

    // Imprimimos os obxectos en orde
    for (auto it = obxectos.begin(); it != obxectos.end(); ++it)
    {
      std::cout << std::get<1>(*it);

      if (std::next(it) != obxectos.end())
        std::cout << " ";
      else
        std::cout << "\n";
    }

    // Lemos o seguinte caso
    std::cin >> N;
  }

  return 0;
}