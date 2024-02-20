#include <iostream>
#include <vector>
#include <algorithm>

bool compareBases(std::pair<int, int> a, std::pair<int, int> b)
{
  return a.first - a.second > b.first - b.second;
}

int main()
{
  // Desvincula a E/S entre C++ e C
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  // Numero de bases enemigas
  int n;
  std::cin >> n;

  while (n != 0)
  {
    std::vector<std::pair<int, int>> bases(n);

    for (int i = 0; i < n; i++)
    {
      // s: soldados necesarios para conquistar a base
      // b: baixas que se producen
      // r: soldados reten
      int s, b, r;
      std::cin >> s >> b >> r;
      bases[i] = std::make_pair(s, b + r); // p = b + r soldados perdidos na conquista
    }

    std::sort(bases.begin(), bases.end(), compareBases);

    int soldados_necesarios = 0, soldados_actuais = 0;
    // Percorremos as bases dende a ultima ata a primeira cun iterador
    for (auto it = bases.begin(); it != bases.end(); it++)
    {
      int s = (*it).first;
      int p = (*it).second;
      if (s > soldados_actuais)
      {
        soldados_necesarios += s - soldados_actuais;
        soldados_actuais = s;
      }

      if (p > soldados_actuais)
      {
        soldados_necesarios += p - soldados_actuais;
        soldados_actuais = 0; // p > s  e non queda ningun soldado para a seguinte base
      }
      else
        soldados_actuais -= p; // Quitamos os soldados que quedan na base
    }

    std::cout << soldados_necesarios << "\n";

    // Lemos o seguinte caso
    std::cin >> n;
  }

  return 0;
}