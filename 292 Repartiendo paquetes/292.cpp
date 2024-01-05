#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <limits>

#define INF std::numeric_limits<int>::max()

// Comparador para a cola de prioridade
class comparador
{
public:
  int operator()(const std::pair<int, int> &p1, const std::pair<int, int> &p2)
  {
    return p1.second > p2.second; // Ordena de menor a maior
  }
};

std::vector<int> Djikstra(std::list<std::pair<int, int>> *conexions, int N, int orixe)
{

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, comparador> pq;

  std::vector<int> dist(N, INF);
  dist[orixe] = 0;

  pq.push(std::make_pair(orixe, 0));

  while (!pq.empty())
  {
    int u = pq.top().first;
    pq.pop();

    for (auto it = conexions[u].begin(); it != conexions[u].end(); it++)
    {
      int v = (*it).first;
      int coste = (*it).second;

      if (dist[v] > dist[u] + coste)
      {
        dist[v] = dist[u] + coste;
        pq.push(std::make_pair(v, dist[v]));
      }
    }
  }

  return dist;
}

int main()
{

  // Desvincula a E/S entre C++ e C
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  // Numero de casas da comarca
  int N;

  while (std::cin >> N)
  {
    // Numero de conexions directas
    int C;
    std::cin >> C;

    // Lemos as conexions directas
    std::list<std::pair<int, int>> *conexions = new std::list<std::pair<int, int>>[N];
    // Almacenamos tamen o grafo invertido para poder calcular a distancia de volta
    std::list<std::pair<int, int>> *conexions_invertidas = new std::list<std::pair<int, int>>[N];
    for (int i = 0; i < C; i++)
    {
      int a, b, coste;
      std::cin >> a >> b >> coste;
      conexions[a - 1].push_back(std::make_pair(b - 1, coste));
      conexions_invertidas[b - 1].push_back(std::make_pair(a - 1, coste));
    }

    // Oficina de reparto
    int orixe;
    std::cin >> orixe;

    // Numero de paquetes a repartir
    int P;
    std::cin >> P;

    // Calculamos a distancia dende a oficina ata cada casa
    std::vector<int> dist = Djikstra(conexions, N, orixe - 1);
    // Calculamos a distancia dende cada casa ata a oficina
    std::vector<int> dist_invertidas = Djikstra(conexions_invertidas, N, orixe - 1);

    long distancia_total = 0;

    for (int i = 0; i < P; i++)
    {
      // Destino do paquete
      int destino;
      std::cin >> destino;

      // Obtemos a distancia de ida ata o destino dende a oficina
      if (dist[destino - 1] == INF)
      {
        distancia_total = -1;
        std::cout << "Imposible\n";
        break;
      }

      // Obtemos a distancia de volta dende o destino ata a oficina
      if (dist_invertidas[destino - 1] == INF)
      {
        distancia_total = -1;
        std::cout << "Imposible\n";
        break;
      }

      // Actualizamos a distancia total co caminho de ida e volta dende a oficina
      distancia_total += dist[destino - 1] + dist_invertidas[destino - 1];
    }
    if (distancia_total != -1)
      std::cout << distancia_total << "\n";
    else // lemos o que queda de linha
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  return 0;
}