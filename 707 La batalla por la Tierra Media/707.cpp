#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <queue>

// Comparador personalizado da cola de prioridade
struct ComparadorCola
{
  bool operator()(std::pair<int, int> a, std::pair<int, int> b)
  {
    double indice_a = (double)a.first / (double)a.second;
    double indice_b = (double)b.first / (double)b.second;
    return indice_a < indice_b;
  }
};

int main()
{

  // Esto desvincula las operaciones de E/S de C++ de las operaciones de E/S de C, lo que puede mejorar el rendimiento.
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string line;

  while (true)
  {
    int n, e;
    std::cin >> n >> e;

    if (!std::cin)
    {
      break;
    }

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, ComparadorCola> grupos_inimigos;

    // Lemos o numero de inimigos que hai en cada grupo
    for (int i = 0; i < e; i++)
    {
      int n_enemigos;
      std::cin >> n_enemigos;
      grupos_inimigos.push(std::make_pair(n_enemigos, 1));
    }

    // Asignamos o resto de loitadores, xa temos asignados <e> loitadores
    for (int i = (e + 1); i <= n; i++)
    {
      // Obtemos o grupo de inimigos que ten ao loitador que loita contra o maximo numero de inimigos
      std::pair<int, int> grupo_maximo = grupos_inimigos.top();

      // Actualizamos o grupo de loitadores na cola de prioridade
      grupos_inimigos.pop();
      grupo_maximo.second++;
      grupos_inimigos.push(grupo_maximo);
    }

    // Obtemos o grupo de inimigos contra o que loita o loitador mais sobreasigando
    std::pair<int, int> grupo_maximo = grupos_inimigos.top();

    // Obtemos o numero de inimigos contra o que loita
    int max_inimigos = std::ceil((double)grupo_maximo.first / (double)grupo_maximo.second);

    std::cout << max_inimigos << "\n";
  }

  return 0;
}