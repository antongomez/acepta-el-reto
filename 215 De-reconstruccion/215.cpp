#include <iostream>
#include <vector>
#include <stack>

class Nodo
{
public:
  int valor;
  Nodo *filloEsquerdo;
  Nodo *filloDereito;

  Nodo(int val) : valor(val), filloEsquerdo(nullptr), filloDereito(nullptr) {}
};

class Arbore
{
private:
  void posorde(Nodo *nodo)
  {
    if (nodo != nullptr)
    {
      posorde(nodo->filloEsquerdo);
      posorde(nodo->filloDereito);
      std::cout << nodo->valor << " ";
    }
  }

public:
  Nodo *raiz;

  Arbore() : raiz(nullptr) {}

  // Insertamos un nodo como fillo esquerdo (-1), fillo dereito (1) ou raiz (0)
  Nodo *insertar(Nodo *pai, int val, int pos)
  {
    Nodo *nodo = new Nodo(val);

    if (pos == -1)
      pai->filloEsquerdo = nodo;

    else if (pos == 0)
      raiz = nodo;

    else if (pos == 1)
      pai->filloDereito = nodo;

    return nodo;
  }

  void posorde()
  {
    if (raiz != nullptr)
    {
      posorde(raiz->filloEsquerdo);
      posorde(raiz->filloDereito);
      std::cout << raiz->valor << "\n";
    }
  }
};

// Vai introducindo os fillos esquerdos do nodo que visita ata que non teña fillo esquerdo
// (momento no que o percorrido inorde e o preorde coinciden)
int profundizar_esquerda(std::vector<int> &rInorde, std::vector<int> &rPreorde, int i, int j, Arbore &arbore, Nodo *&n, std::stack<Nodo *> &pila)
{

  while (rPreorde[i] != rInorde[j])
  {
    n = arbore.insertar(n, rPreorde[i + 1], -1);
    pila.push(n);
    i++;
  }

  return i;
}

int main()
{
  // Desvincula a E/S entre C++ e C
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int nodo;
  std::cin >> nodo;

  while (nodo != -1)
  {

    std::vector<int> rInorde;
    std::vector<int> rPreorde;
    while (nodo != -1)
    {
      rPreorde.push_back(nodo);
      std::cin >> nodo;
    }

    std::cin >> nodo;
    while (nodo != -1)
    {
      rInorde.push_back(nodo);
      std::cin >> nodo;
    }

    Arbore arbore;
    // O primeiro nodo do recorrido en preorde é a raiz da arbore
    Nodo *n = arbore.insertar(nullptr, rPreorde[0], 0);

    // A idea e ir introducindo na arbore todos os fillos esquerdos
    // ata que cheguemos a un nodo que non ten fillos esquerdos
    // (primeiro nodo do percorrido inorde).

    // Na pila imos almacenando todos estes nodos que teñen fillos esquerdos
    // incluído o último nodo introducido na arbore, que non ten fillo esquerdo.
    size_t i = 0, j = 0;
    std::stack<Nodo *> pila;
    // Introducimos a raiz na pila
    pila.push(n);

    // Profundizamos pola esquerda ata que atopemos o primeiro nodo do percorrido inorde
    i = profundizar_esquerda(rInorde, rPreorde, i, j, arbore, n, pila);
    j++;
    while (j < rInorde.size()) // Profundizamos pola esquerda con todos os fillos dereitos dos nodos da pila
    {
      n = pila.top();
      pila.pop();

      // Primeira condicion: Se e igual, o nodo n non ten fillo dereito
      // Segunda condicion: Caso especial: Comprobamos se ten fillo dereito a raiz da arbore
      if ((!pila.empty() && (pila.top()->valor != rInorde[j])) || (pila.empty() && (i < rPreorde.size())))
      {
        i++;
        // Metemos o fillo dereito na arbore e na pila
        n = arbore.insertar(n, rPreorde[i], 1);
        pila.push(n);
        i = profundizar_esquerda(rInorde, rPreorde, i, j, arbore, n, pila);
      }

      j++;
    }

    arbore.posorde();

    // Lemos o inicio do seguinte caso
    std::cin >> nodo;
  }

  return 0;
}