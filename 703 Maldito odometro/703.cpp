#include <iostream>

int main()
{
  int nCasosProba;
  char _;

  // Esto desvincula las operaciones de E/S de C++ de las operaciones de E/S de C, lo que puede mejorar el rendimiento.
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> nCasosProba;

  for (int i = 0; i < nCasosProba; i++)
  {
    int horas, minutos, distancia, velocidade;
    std::cin >> horas >> _ >> minutos >> distancia >> velocidade;
    std::cout << (horas + minutos / 60.0f) * velocidade << '\n';
  }

  return 0;
}