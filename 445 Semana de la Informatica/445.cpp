#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define ll long long

int main()
{

  // Desvinculamos E/S de C++ e C
  std::ios_base::sync_with_stdio(false);
  // Desactivamos a sincronización entre entrada e saida
  std::cin.tie(nullptr);

  int N;

  while (std::cin >> N)
  {
    std::vector<std::pair<ll, ll>> actividades(N);

    ll ini, fin;

    for (int i = 0; i < N; i++)
    {
      std::cin >> ini >> fin;
      actividades[i] = std::make_pair(ini, fin);
    }

    // Ordenamos as actividades por orde de inicio
    std::sort(actividades.begin(), actividades.end());

    std::multiset<int> venta_actividades;
    int max_recursos = 1;

    for (auto it = actividades.begin(); it != actividades.end(); ++it)
    {

      while (!venta_actividades.empty() && (*(venta_actividades.begin()) <= it->first))
        venta_actividades.erase(venta_actividades.begin());
      

      venta_actividades.insert(it->second);

      if ((int)venta_actividades.size() > max_recursos)
        max_recursos = venta_actividades.size();
    }

    std::cout << max_recursos - 1 << "\n";
  }

  return 0;
}