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
    int n, f, t;
    std::cin >> n >> f >> t;

    // Calculamos o progreso da barra cando se solta a tecla que fai saltar a pulga
    int pasos_de_potencia = t % (n + 1);
    // Multiplicamos o progreso da barra polo factor de potencia
    std::cout << pasos_de_potencia * f << "\n";
  }

  return 0;
}