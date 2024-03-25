#include <iostream>
#include <vector>

int main()
{

  // Desvincula a E/S entre C++ e C
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  while (n > 0)
  {
    std::vector<int> v(n);

    int indice = -1;
    // Lemos o primeiro numero do vector
    std::cin >> v[0];
    for (int i = 1; i < n; i++)
    {
      std::cin >> v[i];
      // Detectamos o ultimo caso no que v[i-1] == v[i]
      if (v[i - 1] == v[i])
        indice = i;
    }

    // Unico caso no que cambian todos os numeros do vector
    if (indice == -1)
    {
      int aux = v[0] + 1;
      for (int i = 0; i < n - 1; i++)
      {
        std::cout << aux << " ";
      }
      std::cout << aux << "\n";
    }
    else // So cambia o elemento da posicion i que tomaria o valor v[i] + 1
    {
      for (int i = 0; i < n - 1; i++)
      {
        if (i >= indice)
          std::cout << v[indice] + 1 << " ";
        else
          std::cout << v[i] << " ";
      }
      std::cout << v[indice] + 1 << "\n";
    }

    // Lemos o seguinte caso
    std::cin >> n;
  }
}