#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#define ll long long

class Comparador
{
public:
  bool operator()(const std::tuple<ll, ll, int> &a, const std::tuple<ll, ll, int> &b)
  {
    if (std::get<1>(a) == std::get<1>(b))
    {
      return std::get<0>(a) > std::get<0>(b);
    }
    return std::get<1>(a) > std::get<1>(b);
  }
};

int main()
{

  // Desvincula a E/S entre C++ e C
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  while (n > 0)
  {
    std::vector<std::tuple<ll, ll, int>> usuarios(n);
    for (int i = 0; i < n; i++)
    {
      ll id;
      int periodo;
      std::cin >> id >> periodo;
      usuarios[i] = std::make_tuple(id, periodo, periodo);
    }
    // Numero de id de usuario que hai que imprimir
    int k;
    std::cin >> k;

    // Creamos unha cola de prioridade con todos os id de usuario
    std::priority_queue<std::tuple<ll, ll, int>, std::vector<std::tuple<ll, ll, int>>, Comparador> pq(usuarios.begin(), usuarios.end());

    for (int i = 0; i < k; i++)
    {
      // Obtemos o seguinte envio de monitorizacion de usuario
      auto seguinte_envio = pq.top();
      std::cout << std::get<0>(seguinte_envio) << "\n";

      // Quitamos o seguinte envio de monitorizacion da cola de prioridade
      pq.pop();
      // Engadimos o seguinte envio de monitorizacion de usuario std::get<0>(seguinte_envio) a cola de prioridade
      std::get<1>(seguinte_envio) += std::get<2>(seguinte_envio);
      pq.push(seguinte_envio);
    }
    std::cout << "----\n";

    // Lemos o seguinte caso
    std::cin >> n;
  }

  return 0;
}