#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

struct Node
{
    int value;
    vector<Node*> childs;
};

int max(int, int);
int min(int, int);

int main()
{


    return 0;
}

int alfabeta(Node* node, int melyseg, int alfa, int beta, bool is_maximizing)
{
    int ertek;

    if (melyseg == 0 || node->childs.size() == 0)
    {
        return node->value;
    }

    if (is_maximizing)
    {
        ertek = INT_MIN;

        for (int i = 0; i < node->childs.size(); i++)
        {
            ertek = max(ertek, alfabeta(node->childs[i], melyseg - 1, alfa, beta, false));

            alfa = max(alfa, ertek);

            if (alfa >= beta)
            {
                break;
            }

            return ertek;
        }
    }
    else
    {
        ertek = INT_MAX;

        for (int i = 0; i < node->childs.size(); i++)
        {
            ertek = min(ertek, alfabeta(node->childs[i], melyseg - 1, alfa, beta, true));

            beta = min(beta, ertek);

            if (beta <= alfa)
            {
                break;
            }

            return ertek;
        }
    }
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

