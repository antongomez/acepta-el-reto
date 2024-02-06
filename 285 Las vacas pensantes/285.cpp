#include <iostream>
#include <vector>

// Solucion recursiva con memoizacion. A diferenza da outra solucion,
// neste caso non completamos toda a taboa, senon que so calculamos
// os valores que necesitamos para resolver o problema

long long int max_comida(const std::vector<int> &comida_cubos, std::vector<std::vector<int>> &dp, int i, int j)
{
  if (dp[i][j] != -1)
    return dp[i][j]; // Devolvemos o valor da taboa se xa o temos calculado

  // Temos en conta que a matriz ten unha columna mais que o vector "comida_cubos"
  int k = j - 1;

  // Calculamos canto comemos se comemos o cubo da dereita (posicion k de comida_cubos)
  // Quitamos o cubo que comeria devoradora: posicion i ou k-1, dependendo de cal sexa maior
  int comida_dereita;
  if (comida_cubos[i] > comida_cubos[k - 1])
    comida_dereita = comida_cubos[k] + max_comida(comida_cubos, dp, i + 1, j - 1);
  else
    comida_dereita = comida_cubos[k] + max_comida(comida_cubos, dp, i, j - 2);

  // Calculamos canto comemos se comemos o cubo da esquerda (posicion i de comida_cubos)
  // Quitamos o cubo que comeria devoradora: posicion i+1 ou k, dependendo de cal sexa maior
  int comida_esquerda;
  if (comida_cubos[i + 1] > comida_cubos[k])
    comida_esquerda = comida_cubos[i] + max_comida(comida_cubos, dp, i + 2, j);
  else
    comida_esquerda = comida_cubos[i] + max_comida(comida_cubos, dp, i + 1, j - 1);

  dp[i][j] = std::max(comida_dereita, comida_esquerda);
  return dp[i][j];
}

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

    // Inicializamos a taboa de memoizacion a -1
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, -1));

    // Completamos os valores da diagonal da matriz e a diagonal superior
    for (int i = 0; i < n; i++)
    {
      dp[i][i + 1] = comida_cubos[i]; // Solucionamos os problemas de tamanho 1 (trivial)
      dp[i][i] = 0;
    }
    dp[n][n] = 0;

    std::cout << max_comida(comida_cubos, dp, 0, n) << "\n";

    std::cin >> n;
  }

  return 0;
}