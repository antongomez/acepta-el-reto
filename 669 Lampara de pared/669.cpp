#include <iostream>
#include <vector>

#define MAX_TAM_VARILLAS 100

int main()
{

  // Desvincula a E/S entre C++ e C
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int nvarillas;
  std::cin >> nvarillas;

  while (nvarillas > 0)
  {
    // Creamos un vector que conte o numero de varillas de cada unha
    // das posibles lonxitudes das varillas (entre 1 e MAX_TAM_VARILLAS)
    std::vector<int> varillas(MAX_TAM_VARILLAS + 1, 0);

    for (int i = 0; i < nvarillas; i++)
    {
      int v;

      std::cin >> v;
      varillas[v]++;
    }

    // Contamos grupos de 4 e de 2
    int gr4 = 0, gr2 = 0;
    for (auto v : varillas)
    {
      // Se non temos mais dunha varilla de lonxitude v, pasamos a seguinte
      if (v <= 1)
        continue;

      // Miramos primeiro cantos grupos de 4 podemos facer
      gr4 += v / 4;
      // Miramos se podemos facer un grupo de 2 con algunha das varillas que sobran
      v % 4 >= 2 ? gr2 += 1 : 0;
    }

    if (gr2 >= gr4)
      std::cout << gr4 << "\n";
    else
    {
      // Redistribuimos as varillas de 4 en grupos de 2
      int gr4_sobrantes = gr4 - gr2;
      // Cada 3 grupos de 4 podense facer 2 lamparas mais sen que sobren varillas
      int lamparas = gr2 + 2 * (gr4_sobrantes / 3);
      // Se sobran dous grupos de 4 varillas, podemos facer unha lampara mais
      gr4_sobrantes % 3 == 2 ? lamparas += 1 : 0;
      std::cout << lamparas << "\n";
    }

    std::cin >> nvarillas;
  }

  return 0;
}