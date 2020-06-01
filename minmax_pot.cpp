#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

struct Node
{
    int value;
    vector<Node*> children;
};

int alfabeta(Node*, int, int, int, bool);
int max(int, int);
int min(int, int);
Node* pushNode(int);

int main()
{
    Node* root = pushNode(0);
    root->children.push_back(pushNode(0));
    root->children.push_back(pushNode(0));
    root->children.push_back(pushNode(0));
    root->children.push_back(pushNode(0));

    root->children[0]->children.push_back(pushNode(4));
    root->children[0]->children.push_back(pushNode(10));

    root->children[1]->children.push_back(pushNode(3));
    root->children[1]->children.push_back(pushNode(7));
    root->children[1]->children.push_back(pushNode(8));

    root->children[2]->children.push_back(pushNode(2));
    root->children[2]->children.push_back(pushNode(6));
    root->children[2]->children.push_back(pushNode(9));

    root->children[3]->children.push_back(pushNode(1));

    cout << alfabeta(root, 2, INT_MIN, INT_MAX, true);

    return 0;
}

int alfabeta(Node* node, int melyseg, int alfa, int beta, bool is_maximizing)
{
    int ertek;

    if (melyseg == 0 || node->children.size() == 0)
    {
        return node->value;
    }

    if (is_maximizing)
    {
        ertek = INT_MIN;

        for (int i = 0; i < node->children.size(); i++)
        {
            ertek = max(ertek, alfabeta(node->children[i], melyseg - 1, alfa, beta, false));

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

        for (int i = 0; i < node->children.size(); i++)
        {
            ertek = min(ertek, alfabeta(node->children[i], melyseg - 1, alfa, beta, true));

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

Node* pushNode(int value)
{
    Node* newnode = new Node;
    newnode->value = value;

    return newnode;
}

