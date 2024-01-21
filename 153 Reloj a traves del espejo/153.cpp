#include <iostream>
#include <iomanip>

int main()
{

  // Desvincula a E/S entre C++ e C
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int casos;

  std::cin >> casos;

  for (int i = 0; i < casos; i++)
  {
    int horas, minutos;
    char _;
    std::cin >> horas >> _ >> minutos;

    int horas_espello, minutos_espello;

    // Pasamos a formato 00:00 - 11:59
    if (horas == 12)
      horas = 0;

    // Se os minutos son distintos de 0:
    // No caso de que a hora estea pertenza ao intervalo [0, 6): horas_espello = 12 - (horas + 1)
    // No caso de que a hora estea pertenza ao intervalo [6, 12): horas_espello = 0 + (12 - (horas + 1))
    if (minutos != 0)
      horas_espello = 11 - horas;
    else
      horas_espello = 12 - horas;

    // Axustamos os minutos
    minutos_espello = (60 - minutos) % 60;

    // Pasamos a formato 01:00 - 12:59
    if (horas_espello == 0)
      horas_espello = 12;

    std::cout << std::setw(2) << std::setfill('0') << horas_espello << ":"
              << std::setw(2) << std::setfill('0') << minutos_espello << "\n";
  }

  return 0;
}