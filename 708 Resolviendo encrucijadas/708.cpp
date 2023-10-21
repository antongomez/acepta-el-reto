#include <iostream>
#include <vector>
#include <cmath>

/* A formula empregada para calcular a suma dos dixitos multiplos de 3
   entre 1 e n esta inspirada en:
   https://www.geeksforgeeks.org/count-sum-of-digits-in-numbers-from-1-to-n/
   Adaptei a solucion que se presenta no anterior enlace para sumar os dixitos dos
   multiplos de 3 en lugar de sumar os dixitos de todos os numeros entre 1 e n
*/

long long axusteNegativo_mod0(long long x)
{
  if (x == 0)
    return 0;
  if (x == 1)
    return 3;
  if (x <= 3)
    return 9;
  if (x == 4)
    return 12;
  if (x <= 6)
    return 18;
  if (x == 7)
    return 21;
  // x <= 9
  return 27;
}

long long axusteNegativo_mod1(long long x)
{
  if (x == 0)
    return 3;
  if (x <= 2)
    return 9;
  if (x == 3)
    return 12;
  if (x <= 5)
    return 18;
  if (x == 6)
    return 21;
  if (x <= 8)
    return 27;
  // x == 9
  return 30;
}

long long axusteNegativo_mod2(long long x)
{
  if (x <= 1)
    return 6;
  if (x == 2)
    return 9;
  if (x <= 4)
    return 15;
  if (x == 5)
    return 18;
  if (x <= 7)
    return 24;
  if (x == 8)
    return 27;
  // x == 9
  return 33;
}

long long axusteNegativo(long long x, long long mod)
{
  if (mod == 0)
    return axusteNegativo_mod0(x);
  if (mod == 1)
    return axusteNegativo_mod1(x);
  return axusteNegativo_mod2(x);
}

long long axustePositivo_mod0(long long x)
{
  // x == 0 || x == 1 || x == 2
  if (x < 3)
    return 0;
  // x == 3 || x == 4 || x == 5
  if (x < 6)
    return 3;
  if (x < 9)
    return 9;
  // x == 9
  return 18;
}

long long axustePositivo_mod1(long long x)
{
  // x == 0 || x == 1
  if (x < 2)
    return 0;
  // x == 2 || x == 3 || x == 4
  if (x < 5)
    return 2;
  if (x < 8)
    return 7;
  // x == 8 || x == 9
  return 15;
}

long long axustePositivo_mod2(long long x)
{
  // x == 0
  if (x == 0)
    return 0;
  // x == 1 || x == 2 || x == 3
  if (x < 4)
    return 1;
  // x == 4 || x == 5 || x == 6
  if (x < 7)
    return 5;
  // x == 7 || x == 8 || x == 9
  return 12;
}

long long axustePositivo(long long x, long long mod)
{
  if (mod == 0)
    return axustePositivo_mod0(x);
  if (mod == 1)
    return axustePositivo_mod1(x);
  return axustePositivo_mod2(x);
}

long long contarMultiplos3(long long n, long long l, long long mod_acum)
{

  if (mod_acum == 0)
    return ((n % l) / 3);

  if ((mod_acum == 1) && ((n - l) >= 2))
  {
    l += 2;
    return ((n % l) / 3) + 1;
  }

  if ((mod_acum == 2) && (n - l) >= 1)
  {
    l += 1;
    return ((n % l) / 3) + 1;
  }

  return 0;
}

// Con estes vectores evitamos realizar o calculo destes numeros repetidas veces
std::vector<long long> treses_d = {0, 3, 33, 333, 3333, 33333, 333333, 3333333, 33333333, 333333333, 3333333333, 33333333333, 333333333333, 3333333333333, 33333333333333, 333333333333333};
// Suma dos multiplos de 3 ata 9...d...9 (d noves):
// a[d] = a[d - 1] * 10 - 27 * (d - 1) + treses * 45 + 18
std::vector<long long> sumas_ata_d_noves = {0, 18, 306, 4509, 60012, 750015, 9000018, 105000021, 1200000024, 13500000027, 150000000030, 1650000000033, 18000000000036, 195000000000039, 2100000000000042, 22500000000000045};

// Funcion recursiva que calcula a suma dos dixitos dos multiplos de 3 de 1 a n
// Para entender que fai a funcion suponhamos que imos sumar os
// dixitos dos multiplos de 3 dende 1 ata 328
long long calcularSumaDixitosMultiplos3_ata_n(long long n, long long mod_acum)
{
  if (n < 10)
    return axustePositivo(n, mod_acum);

  // Calculamos o numero de dixitos menos 1 de n: 2
  long long d = log10(n);

  // Calculamos a suma ata 9...d...9 (d veces 9): 99
  long long a = sumas_ata_d_noves[d];

  // Calculamos 10^d: 100
  long long p = pow(10, d);

  // Dixito mais significativo (msd) de n: 3,
  long long msd = n / p;

  // Obtemos o numero 3...d...3: 33
  // Este numero indica o numero de multiplos de 3 entre
  // 0 e 99 sen contar o 30, 60, 90
  long long treses = treses_d[d];

  // Suma ata 299
  long long primeiro_termo = msd * a + treses * (msd * (msd - 1) / 2) - d * axusteNegativo(msd - 1, mod_acum) + axustePositivo(msd - 1, mod_acum);

  // Suma dende 300 ata 328
  long long segundo_termo = 0;

  // Para calcular a suma dende 300 ata 328 volvemos chamar a funcion
  // Non obstante, hai que ter en conta de que non son os mesmos multiplos
  // de 3 dende 0 a 28 (0, 3, 6, 9, 12, ...), que dende 400 a 428 quitando o 4
  // (402, 405, 408, 411, ...)
  // Para solucionar isto, calculamos o modulo dos dixitos anteriores a msd, incluido
  // e volvemos chamar a funcion tendo o modulo acumulado en conta
  long long novo_mod_acum = (mod_acum + msd) % 3;

  // Sumamos o numero msd*10^d se e multiplo de 3: no noso caso 300 si que o seria
  if (novo_mod_acum == 0)
    segundo_termo += msd;

  // Calculamos a suma dos dixitos dos multiplos de 3 entre msd*10^d e n
  // quitandolle a todos o msd. Aqui debemos ter en conta o modulo acumulado
  long long rec = calcularSumaDixitosMultiplos3_ata_n(n % p, novo_mod_acum);

  // Contamos o numero de multiplos de 3 dende msd*10^d e n
  // Multiplicamolo por msd para calcular a suma de todos os msd
  // entre msd*10^d e n
  long long mult3 = contarMultiplos3(n, p * msd, novo_mod_acum);

  // Contamos os multiplos de tres entre msd*p e n e multiplicamolo por msd
  segundo_termo += msd * mult3 + rec;

  return primeiro_termo + segundo_termo;
}

int main()
{

  // Desvinculamos E/S de C++ e C
  std::ios_base::sync_with_stdio(false);
  // Desactivamos a sincronización entre entrada e saida
  std::cin.tie(nullptr);

  long long a, b;
  std::cin >> a >> b;
  while (a != 0 && b != 0)
  {

    long long l = calcularSumaDixitosMultiplos3_ata_n(a - 1, 0);
    long long m = calcularSumaDixitosMultiplos3_ata_n(b, 0);

    std::cout << m - l << "\n";

    std::cin >> a >> b;
  }

  return 0;
}