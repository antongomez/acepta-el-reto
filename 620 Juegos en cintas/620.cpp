#include <iostream>
#include <vector>

// Funcion recursiva que comproba todas as combinacions posibles.
// Neste caso, temos un problema da doble mochila con duas mochilas iguais.
// Poren, o tamanho maximo da mochila e moi grande, polo que a solucion
// clasica da dobre mochila poderia tardar mais que xerar todas as combinacions
// xa que neste caso, como maximo temos 8 xogos (o que da lugar a 2^8 = 256 combinacions)
bool xerarVectores(std::vector<long> &xogos, int pos, long e1, long e2)
{
  if (pos == (int)xogos.size())
    return true;

  // Se a combinacion de xogos nas cintas non e valida, probamos a meter o xogo na outra cinta
  // e exploramos todas as posibilidades a partir de ahi
  if ((e1 - xogos[pos] >= 0) && xerarVectores(xogos, pos + 1, e1 - xogos[pos], e2))
    return true;
  if ((e2 - xogos[pos] >= 0) && xerarVectores(xogos, pos + 1, e1, e2 - xogos[pos]))
    return true;

  return false;
}

int main()
{

  // Desvincula a E/S entre C++ e C
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long espazo_cara_cinta;
  int num_xogos;

  while (std::cin >> espazo_cara_cinta >> num_xogos)
  {

    std::vector<long> xogos(num_xogos);
    for (int i = 0; i < num_xogos; i++)
    {
      long tam_xogo;
      std::cin >> tam_xogo;
      xogos[i] = tam_xogo;
    }

    xerarVectores(xogos, 0, espazo_cara_cinta, espazo_cara_cinta) ? std::cout << "SI\n" : std::cout << "NO\n";
  }

  return 0;
}