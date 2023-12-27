#include <iostream>
#include <list>

std::list<int>::iterator buscar_portal_mais_proximo(std::list<int> &portais, int p_inicial)
{
  std::list<int>::iterator it;
  for (it = portais.begin(); it != portais.end(); it++)
  {
    if (p_inicial == *it) // O p_inicial e un dos que ten que visitar
    {
      return it;
    }
    else if (p_inicial < *it)
    {

      if (it != portais.begin())
      {
        int dist_next = *it - p_inicial;
        int dist_prev = p_inicial - *std::prev(it);
        return (dist_next <= dist_prev) ? it : std::prev(it);
      }
      else // Caso no que p_inicial e menor que todos os portais que se visitan
        return it;
    }
  }
  return std::prev(portais.end()); // Caso no que p_inicial e maior que todos os portais que se visitan
}

int main()
{

  // Desvincula a E/S entre C++ e C
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int casos;
  std::cin >> casos;

  for (int i = 0; i < casos; i++)
  {
    int p_inicial, nportais;
    std::cin >> p_inicial >> nportais;

    std::list<int> portais;

    for (int j = 0; j < nportais; j++)
    {
      int p;
      std::cin >> p;
      portais.push_back(p);
    }

    // Ordenamos os portais de menor a maior
    portais.sort();

    // Calculamos o primeiro portal que visita papa noel
    std::list<int>::iterator pos = buscar_portal_mais_proximo(portais, p_inicial);

    while (portais.size() > 1)
    {
      // Imprimimos o portal que visita papa noel
      std::cout << *pos << " ";

      // Calculamos se o seguinte portal que visita papa noel e o anterior.
      // En caso contrario, sera o seguinte
      bool next_pos_portal_anterior = false;

      if (std::next(pos) == portais.end())
        next_pos_portal_anterior = true;
      else
      {
        int distancia_maior = *std::next(pos) - *pos;
        int distancia_menor = *pos - *std::prev(pos);
        next_pos_portal_anterior = (distancia_maior <= distancia_menor) ? false : true;
      }

      pos = portais.erase(pos);

      // Actualizamos o seguinte portal que visita papa noel
      if (next_pos_portal_anterior == true)
        pos = std::prev(pos);
    }

    // Imprimimos o ultimo portal que visita papa noel
    std::cout << *portais.begin() << "\n";
  }

  return 0;
}