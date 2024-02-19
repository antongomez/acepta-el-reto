#include <iostream>
#include <vector>
#include <cmath>

#define MAX_DIF 0.001

double avaliarPolinomio(const std::vector<int> &polinomio, double x)
{
  double resultado = 0;
  for (int i = 0; i < (int)polinomio.size(); i++)
  {
    resultado += polinomio[i] * pow(x, i);
  }
  return resultado;
}

int main()
{

  // Desvincula a E/S entre C++ e C
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int grao;
  std::cin >> grao;

  while (grao != 20)
  {
    std::vector<int> polinomio(grao + 1);

    // Lemos os coeficientes do polinomio
    for (int i = 0; i < grao + 1; i++)
    {
      std::cin >> polinomio[grao - i];
    }

    // Lemos o numero de rectangulos
    int n;
    std::cin >> n;

    double suma = 0;
    for (int i = 0; i < n; i++)
    {
      // A suma sempre e menor que 1, co que suma esta acotada por n
      // Isto permitenos sacar factor comun 1/n sen risco de overflow
      suma += std::min(std::max(avaliarPolinomio(polinomio, (double)i / (double)n), 0.0), 1.0);
    }
    // Sacamos factor comun 1/n
    suma /= n;

    // Cain - Abel
    double diferencia = 2 * suma - 1;

    if (diferencia > MAX_DIF)
      std::cout << "CAIN\n";
    else if (diferencia < -MAX_DIF)
      std::cout << "ABEL\n";
    else
      std::cout << "JUSTO\n";

    // Lemos o seguinte caso
    std::cin >> grao;
  }

  return 0;
}