#include <iostream>
#include <vector>
#include <algorithm>

int main()
{

  // Desvincula a E/S entre C++ e C
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long lonxitude, n;

  while (std::cin >> lonxitude >> n)
  {

    std::vector<long> coches;

    for (int i = 0; i < n; i++)
    {
      long t, v;
      std::cin >> t >> v;
      // Se o coche ten velocidade 0, non chega nunca ao destino
      // Se o coche pasa antes de que Marty McFly chegue, so
      // o poderia coller se despois pasa un coche que vaia mais
      // rapido e o adianta
      if ((v > 0) && (t >= 0))
      {
        coches.push_back(t + lonxitude / v);
      }
    }

    // Calculamos o minimo tempo de chegada
    auto maximo_it = std::min_element(coches.begin(), coches.end());
    std::cout << *maximo_it << "\n";
  }

  return 0;
}