#include <iostream>
#include <algorithm>

// Devolve o numero grande
int obterNumGrande(int *a)
{
  return a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0];
}

// Devolve o numero pequeno
int obterNumPequeno(int *a)
{
  return a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
}

int casoDeProba(int n)
{
  if (n == 6174)
    return 0;

  // Descomponhemos o numero en dixitos
  int a[4];
  int num = n;
  for (int i = 0; i < 4; i++)
  {
    a[i] = num % 10;
    num /= 10;
  }

  // Comprobamos que todos os dixitos non sexan iguais
  if ((a[0] == a[1]) && (a[1] == a[2]) && (a[2] == a[3]))
    return 8;

  int iteracions = 0;

  while (n != 6174)
  {
    iteracions++;

    // Descomponhemos o numero en dixitos
    for (int i = 0; i < 4; i++)
    {
      a[i] = n % 10;
      n /= 10;
    }

    // Ordeamos os dixitos en orde ascendente
    std::sort(a, a + 4);

    // Obtemos o numero grande e o numero pequeno
    int grande = obterNumGrande(a);
    int pequeno = obterNumPequeno(a);

    n = grande - pequeno;
  }

  return iteracions;
}

int main()
{

  // Desvincula a E/S entre C++ e C
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int casos, n;

  std::cin >> casos;

  for (int i = 0; i < casos; i++)
  {

    std::cin >> n;
    std::cout << casoDeProba(n) << "\n";
  }

  return 0;
}