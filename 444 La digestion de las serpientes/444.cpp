#include <iostream>

int casoDeProba(int n, int k)
{
  // Numero maximo de medicions nos que unha serpe pode sair a cazar
  int max_medicions = 0;
  // Medicions actuais nos que unha serpe pode sair a cazar
  int medicions = 0;
  // Numero de medicions con 0 consecutivas
  int ceros = 0;

  int dato;

  for (int i = 0; i < n; i++)
  {
    std::cin >> dato;

    if (dato == 1)
    {
      // Sumamos a medicion actual e as medidicions anteriores que foron 0
      medicions += 1 + ceros;
      ceros = 0; // Reiniciamos os 0 atopados
    }
    else
    {
      if (medicions > 0)
        ceros++;

      if (ceros > k)
      {
        if (medicions > max_medicions)
          max_medicions = medicions;

        // Reiniciamos o contador de ceros e medicions
        ceros = 0;
        medicions = 0;
      }
    }
  }

  // Caso no que o numero maximo de medicions estea ao final
  if (medicions > max_medicions)
    max_medicions = medicions;

  return max_medicions;
}

int main()
{

  // Desvincula a E/S entre C++ e C
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;

  std::cin >> n >> k;

  while ((n != 0) || (k != 0))
  {
    std::cout << casoDeProba(n, k) << "\n";
    std::cin >> n >> k;
  }

  return 0;
}