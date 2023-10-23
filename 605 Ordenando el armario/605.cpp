#include <iostream>
#include <string>

int main()
{

  // Desvinculamos E/S de C++ e C
  std::ios_base::sync_with_stdio(false);
  // Desactivamos a sincronización entre entrada e saida
  std::cin.tie(nullptr);

  std::string linha;

  // Lemos cada linha e comprobamos que non sexa o ultimo caso, que non se procesa
  while (std::getline(std::cin, linha) && linha != ".")
  {
    int veran = 0;
    int inverno = 0;

    // Percorremos a linha e sumamos as veces que aparece cada estación
    // Ignoramos as A, xa que non afectan ao resultado final
    for (std::string::iterator it = linha.begin(); it != linha.end(); ++it)
    {
      char c = *it;
      if (c == 'V')
      {
        veran++;
        ++it; // Saltamos o seguinte carcater, que sera un espazo
      }
      else if (c == 'I')
      {
        inverno++;
        ++it;
      }
    }

    std::cout << (veran > inverno ? "VERANO\n" : (inverno > veran ? "INVIERNO\n" : "EMPATE\n"));
  }

  return 0;
}