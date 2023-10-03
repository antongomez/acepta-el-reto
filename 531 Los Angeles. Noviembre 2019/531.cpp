#include <iostream>

int main()
{

  // Desvincula a E/S entre C++ e C
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int r, fallos_r, h, fallos_h, h_cidade, r_cidade;

  while (std::cin >> r >> fallos_r >> h >> fallos_h >> h_cidade >> r_cidade)
  {

    // Calculamos o numero de replicantes que retiraria (correctamente)
    double replicantes_mortos = r_cidade - ((double)fallos_r / r) * r_cidade;
    // Calculamos o numero de humanos que retiraria (erroneamente)
    double humanos_mortos = ((double)fallos_h / h) * h_cidade;

    if (humanos_mortos == 0)
    {
      std::cout << "APRUEBA\n";
      continue;
    }

    // Calulamos a taxa de humanos mortos entre o total de mortes
    double taxa_humanos_mortos = humanos_mortos / (replicantes_mortos + humanos_mortos);

    if (taxa_humanos_mortos <= 0.1)
      std::cout << "APRUEBA\n";
    else
      std::cout << "SUSPENDE\n";
  }

  return 0;
}