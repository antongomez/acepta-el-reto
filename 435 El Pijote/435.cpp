#include <iostream>
#include <string>
#include <vector>

int main()
{
  // Desvincula a E/S entre C++ e C
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string line;

  while (std::getline(std::cin, line))
  {
    std::vector<int> frecuencias(10, 0);
    for (char c : line)
    {
      if (c >= '0' && c <= '9')
        frecuencias[c - '0']++;
    }

    bool subnormal = true;
    for (int i = 1; i < 10; i++)
    {
      if (frecuencias[i - 1] != frecuencias[i])
      {
        subnormal = false;
        break;
      }
    }

    std::cout << (subnormal ? "subnormal" : "no subnormal") << std::endl;
  }

  return 0;
}