#include <iostream>
#include <string>

#define ll long long

long long contarletras(int n)
{
  if (n == 1)
  {
    return 3;
  }
  return 2 * contarletras(n - 1) + 2 + n;
}

char atoparCaracter(ll primeiro_grupo, ll segundo_grupo, int n, ll k)
{
  if (k < primeiro_grupo)
  {
    n = n - 1;
    primeiro_grupo = (primeiro_grupo - 2 - n) / 2;
    segundo_grupo = primeiro_grupo + 2 + n;
    // std::cout << "n-1: " << n << ", k; " << k << ". Primeiro grupo " << primeiro_grupo << ". Segundo grupo " << segundo_grupo << "\n";
    return atoparCaracter(primeiro_grupo, segundo_grupo, n, k);
  }
  else if (k < segundo_grupo)
  {
    if (k == primeiro_grupo)
      return 'B';
    else if (k == (segundo_grupo - 1))
      return 'H';
    else
      return 'U';
  }
  else
  {
    n = n - 1;
    k = k - segundo_grupo;
    primeiro_grupo = (primeiro_grupo - 2 - n) / 2;
    segundo_grupo = primeiro_grupo + 2 + n;
    return atoparCaracter(primeiro_grupo, segundo_grupo, n, k);
  }
}

int main()
{

  // Desvinculamos E/S de C++ e C
  std::ios_base::sync_with_stdio(false);
  // Desactivamos a sincronización entre entrada e saida
  std::cin.tie(nullptr);

  int n;
  ll k;

  while (std::cin >> n >> k)
  {
    ll nletras = contarletras(n);

    ll primeiro_grupo = (nletras - 2 - n) / 2;
    ll segundo_grupo = primeiro_grupo + 2 + n;

    std::cout << atoparCaracter(primeiro_grupo, segundo_grupo, n, k - 1) << "\n";
  }

  return 0;
}