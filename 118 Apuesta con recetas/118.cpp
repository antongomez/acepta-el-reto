#include <iostream>
#include <cmath>

// Devolve indice do valor maximo entre tres valores
int calcula_maximo(int a[3])
{
  if (a[0] >= a[1] && a[0] >= a[2])
    return 0;
  else if (a[1] >= a[0] && a[1] >= a[2])
    return 1;
  return 2;
}

// Devolve indice do valor minimo entre tres valores
int calcula_minimo(int a[3])
{
  if (a[0] <= a[1] && a[0] <= a[2])
    return 0;
  else if (a[1] <= a[0] && a[1] <= a[2])
    return 1;
  return 2;
}

int main()
{

  // Desvincula a E/S entre C++ e C
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int a[3];
  int pedro;

  std::cin >> a[0] >> a[1] >> a[2];
  pedro = a[2];

  while ((a[0] >= 0) && (a[1] >= 0) && (a[2] >= 0))
  {
    // Calculamos o maximo e o minimo entre os tres
    int max = calcula_maximo(a);
    int min = calcula_minimo(a);

    // Caso no que os tres son iguais (xogo nulo) ou Pedro esta entre os outros dous (nunca perde)
    if ((a[min] == a[max]) || ((pedro < a[max]) && (pedro > a[min])))
    {
      std::cout << 0 << "\n";
    }
    // Caso no que Pedro e o menor (pode estar empatado)
    else if (pedro < a[max])
    {
      // Calculamos o punto medio entre a aposta de Pedro e a aposta mais alta
      double punto_medio = pedro + (a[max] - pedro) / 2.0;
      // No caso extremo de que os outros dous consigan o maximo posible de recetas (64 cada un)
      // e Pedro non consiga ningunha, a media seria a seguinte
      double minima_media = 128.0 / 3.0; // = 42.66666666666667

      // Neste caso, independentemente dos amigos que convenza Pedro, sempre pode perder
      // O "=" non se vai dar nunca
      if (minima_media > punto_medio)
      {
        std::cout << "I\n";
      }
      else
      {
        // Calculamos o numero maximo de amigos que pode convencer para que lle envien unha receta
        // de forma que siga sendo seguro que a media queda por debaixo do punto medio
        // co -1 axustamos para que a media non quede xusto no punto medio (nese caso Pedro teria que cocinhar)
        int R = ceil(3.0 * punto_medio - 128.0 - 1);
        std::cout << R << "\n";
      }
    }
    // Caso no que Pedro e o maior (pode estar empatado)
    else if (pedro > a[min])
    {
      // Calculamos o punto medio entre a aposta mais baixa e a de Pedro
      double punto_medio = a[min] + (pedro - a[min]) / 2.0;
      // Media mais alta no caso extremo de que os outros dous consigan o minimo posible de recetas (0 cada un)
      double max_media = 64.0 / 3.0; // = 21.33333333333333
      if (max_media < punto_medio)   // O = non se vai dar nunca
      {
        std::cout << "I\n";
      }
      else
      {
        // Calculamos o numero minimo de amigos que debe convencer para que lle envien unha receta
        // de forma que sexa seguro que a media queda por encima do punto medio
        int R = floor(3.0 * punto_medio + 1); // co +1 axustamos para que a media non quede xusto no punto medio
        std::cout << R << "\n";
      }
    }

    std::cin >> a[0] >> a[1] >> a[2];
    pedro = a[2];
  }

  return 0;
}