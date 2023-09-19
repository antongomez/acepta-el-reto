#include <iostream>
#include <vector>
#include <algorithm>

bool comparadorDescendente(int a, int b)
{
  return a > b;
}

int main()
{

  // Vai algo mais rapido
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int P, N;

  std::cin >> P >> N;

  while ((P != 0) && (N != 0))
  {
    std::vector<int> pesos(N);

    for (int i = 0; i < N; i++)
    {
      std::cin >> pesos[i];
    }

    std::sort(pesos.begin(), pesos.end(), comparadorDescendente);

    int i = 0, j = N - 1, viaxes = 0;

    while (i < j)
    {
      int suma_peso = pesos[i] + pesos[j];

      if (suma_peso <= P)
        j--;

      i++;
      viaxes++;
    }

    if (i == j)
      viaxes++;

    std::cout << viaxes << "\n";

    std::cin >> P >> N;
  }

  return 0;
}