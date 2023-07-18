#include <iostream>

int main()
{
  int nCasosProba;

  // Esto desvincula las operaciones de E/S de C++ de las operaciones de E/S de C, lo que puede mejorar el rendimiento.
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> nCasosProba;

  for (int i = 0; i < nCasosProba; i++)
  {
    int n_saltos;
    std::cin >> n_saltos;
    int potencia = 0, potencia_inicial = 0, distancia_pedra, salto, salto_anterior = 0;
    for (int j = 0; j < n_saltos; j++)
    {
      std::cin >> salto;
      distancia_pedra = salto - salto_anterior;
      salto_anterior = salto;
      if (distancia_pedra == potencia)
      {
        potencia--;
      }
      else if (distancia_pedra > potencia)
      {
        if (distancia_pedra <= potencia_inicial + 1)
        {
          potencia_inicial++;
        }
        else
        {
          potencia_inicial += (distancia_pedra - potencia_inicial);
        }
        if (potencia_inicial == distancia_pedra)
        {
          potencia = potencia_inicial - 1;
        }
        else
          potencia = potencia_inicial;
      }
    }

    std::cout << potencia_inicial << '\n';
  }

  return 0;
}