#include <iostream>
#include <string>
#include <stack>

char obter_parentese_oposto(char parentese)
{
  char oposto;
  switch (parentese)
  {
  case ')':
    oposto = '(';
    break;
  case ']':
    oposto = '[';
    break;
  case '}':
    oposto = '{';
    break;

  default:
    oposto = '(';
    break;
  }
  return oposto;
}

int main()
{

  // Desvincula a E/S entre C++ e C
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string line;

  while (std::getline(std::cin, line))
  {
    bool balanced = true;
    std::stack<char> stack;

    for (char c : line)
    {
      if (c == '(' || c == '[' || c == '{')
        stack.push(c);
      else if (c == ')' || c == ']' || c == '}')
      {
        if (!stack.empty() && stack.top() == obter_parentese_oposto(c))
          stack.pop();
        else
        {
          balanced = false;
          break;
        }
      }
    }

    if (balanced && stack.empty())
      std::cout << "YES\n";
    else
      std::cout << "NO\n";
  }

  return 0;
}