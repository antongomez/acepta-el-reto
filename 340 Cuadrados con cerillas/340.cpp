#include <iostream>

int main()
{

  // Desvincula a E/S entre C++ e C
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int casos;
  std::cin >> casos;

  for (int i = 0; i < casos; i++)
  {

    int n, m;
    std::cin >> n >> m;

    std::cout << 2 * m * n + m + n << "\n";
  }

  return 0;
}