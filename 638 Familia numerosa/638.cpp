#include <iostream>

int main()
{

    // Desvinculamos as operacions de E/S de C++ das de C
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int casos;

    std::cin >> casos;

    for (int i = 0; i < casos; i++)
    {
        int c, n;

        std::cin >> c >> n;

        // Esta formula proporcionanos o maximo
        // E equivalente a max = n*c/(c-1)
        int max = n + n / (c - 1);

        int min;

        if (n % (c - 1) == 0)
        {
            min = max - 1;
        }
        else
        {
            min = max;
        }

        std::cout << min << " " << max << "\n";
    }

    return 0;
}