#include <iostream>

long long casoDeProba(int n)
{

  long long max1 = -1, max2 = -1, min1 = 1, min2 = 1;

  for (int i = 0; i < n; i++)
  {

    int aux;
    std::cin >> aux;

    // Primeiro comprobamos se o numero e o mais grande que atopamos (positivo ou igual a 0)
    if (aux > max1)
    {
      max2 = max1; // Actualizamos o segundo maximo
      max1 = aux;
    }
    else if (aux > max2) // Comprobamos se e o segundo mais grande (positivo ou igual a 0)
    {
      max2 = aux;
    }
    else if ((aux < 0) && (aux < min1)) // Comprobamos se e o numero mais pequeno que atopamos (negativo)
    {
      min2 = min1;
      min1 = aux;
    }
    else if ((aux < 0) && (aux < min2)) // Comprobamos se e o segundo numero mais pequeno (negativo)
    {
      min2 = aux;
    }
  }

  // Caso no que hai mais de 1 positivo e mais de 1 negativo
  if ((min2 != 1) && (max2 != -1))
  {
    long long res_max = max1 * max2;
    long long res_min = min1 * min2;

    if (res_max > res_min)
      return res_max;
    return res_min;
  }
  else if ((min2 != 1) && (max2 == -1)) // Caso no que so hai un positivo
    return min1 * min2;
  else if ((min2 == 1) && (max2 != -1)) // Caso no que so hai un negativo
    return max1 * max2;
  else // Caso no que so hai un negativo e un positivo
    return max1 * min1;
}

int main()
{

  // Desvincula a E/S entre C++ e C
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;

  std::cin >> n;

  while (n != 0)
  {
    std::cout << casoDeProba(n) << "\n";
    std::cin >> n;
  }

  return 0;
}