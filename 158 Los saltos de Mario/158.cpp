#include <iostream>

int main()
{

  // Desvincula a E/S entre C++ e C
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  unsigned int casos;
  std::cin >> casos;

  for (unsigned int i = 0; i < casos; i++)
  {
    unsigned long muros;
    std::cin >> muros;

    long altura_actual;
    std::cin >> altura_actual;

    long saltos_arriba = 0;
    long saltos_abaixo = 0;

    for (unsigned long j = 0; j < muros - 1; j++)
    {
      long altura;
      std::cin >> altura;

      if (altura > altura_actual)
        saltos_arriba++;
      else if (altura < altura_actual)
        saltos_abaixo++;

      altura_actual = altura;
    }

    std::cout << saltos_arriba << " " << saltos_abaixo << "\n";
  }

  return 0;
}