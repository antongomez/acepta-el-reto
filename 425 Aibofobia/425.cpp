#include <iostream>
#include <vector>

int main()
{

  // Desvincula a E/S entre C++ e C
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string s;

  while (std::cin >> s)
  {
    int n = s.length();

    // Matriz que almacena o numero de letras que hai que engadir para
    // formar un palindromo con cada subcadea da cadea orixinal
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for (int j = 1; j < n; j++)
    {
      for (int i = j - 1; i >= 0; i--)
      {
        if (s[i] == s[j])
          dp[i][j] = dp[i + 1][j - 1];
        else
          dp[i][j] = std::min(dp[i + 1][j], dp[i][j - 1]) + 1;
      }
    }

    std::cout << dp[0][n - 1] << "\n";
  }
  return 0;
}