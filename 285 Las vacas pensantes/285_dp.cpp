#include <iostream>
#include <vector>

// Solucion con programacion dinamica
// Nesta solucion calculamos a taboa enteira por columnas de abaixo arriba
// e de esquerda a dereita (so completamos a parte triangular superior da matriz)

int main()
{
  // Desvincula a E/S entre C++ e C
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  while (n > 0)
  {

    std::vector<int> comida_cubos(n);
    for (int i = 0; i < n; i++)
      std::cin >> comida_cubos[i];

    // Inicializamos a taboa de programacion dinamica a 0
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));

    // Enchemos a diagonal superior da matriz cos valores do vector
    for (int i = 0; i < n; i++)
      dp[i][i + 1] = comida_cubos[i];

    for (int j = 2; j <= n; j++)
    {
      // Temos en conta que a matriz ten unha columna mais que o vector "comida_cubos"
      int k = j - 1;
      for (int i = j - 2; i >= 0; i--)
      {
        // Calculamos canto comemos se comemos o cubo da dereita (posicion k de comida_cubos)
        // Quitamos o cubo que comeria devoradora: posicion i ou k-1, dependendo de cal sexa maior
        int comida_dereita;
        if (comida_cubos[i] > comida_cubos[k - 1])
          comida_dereita = comida_cubos[k] + dp[i + 1][j - 1];
        else
          comida_dereita = comida_cubos[k] + dp[i][j - 2];

        // Calculamos canto comemos se comemos o cubo da esquerda (posicion i de comida_cubos)
        // Quitamos o cubo que comeria devoradora: posicion i+1 ou k, dependendo de cal sexa maior
        int comida_esquerda;
        if (comida_cubos[i + 1] > comida_cubos[k])
          comida_esquerda = comida_cubos[i] + dp[i + 2][j];
        else
          comida_esquerda = comida_cubos[i] + dp[i + 1][j - 1];

        dp[i][j] = std::max(comida_dereita, comida_esquerda);
      }
    }

    std::cout << dp[0][n] << "\n";

    std::cin >> n;
  }

  return 0;
}