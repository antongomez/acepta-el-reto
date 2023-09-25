#include <iostream>

int main()
{

  long n;
  int casos;

  std::cin >> casos;

  for (int i = 0; i < casos; i++)
  {

    std::cin >> n;

    if (n % 3 != 1)
    {
      std::cout << "SI\n";
    }
    else
    {
      std::cout << "NO\n";
    }
  }

  return 0;
}