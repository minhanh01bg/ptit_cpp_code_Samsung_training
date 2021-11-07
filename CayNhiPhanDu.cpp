#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left, *right;
    int data;
};


Node *newNode(int value)
{
    Node *node = new Node;
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

bool perfectTree(Node *node)
{
    if (node == NULL)
        return true;
    if (node->left == NULL && node->right == NULL)
        return true;
    if (node->left == NULL || node->right == NULL)
        return false;
    return perfectTree(node->left) && perfectTree(node->right);
}

void transport_node()
{
    int n, value1, value2;
    char c;
    cin >> n >> value1 >> value2 >> c;
    Node *root = NULL;
    root = newNode(value1);
    vector<Node *> boot;
    boot.push_back(root);
    if (c == 'L')
    {
        root->left = newNode(value2);
        boot.push_back(root->left);
    }
    else
    {
        root->right = newNode(value2);
        boot.push_back(root->right);
    }
    for (int j = 2; j <= n; j++)
    {
        cin >> value1 >> value2 >> c;
        for (int i = boot.size() - 1; i >= 0; i--)
        {
            if (boot[i]->data == value1)
            {
                if (c == 'L')
                {
                    boot[i]->left = newNode(value2);
                    boot.push_back(boot[i]->left);
                }
                else
                {
                    boot[i]->right = newNode(value2);
                    boot.push_back(boot[i]->right);
                }
            }
        }
    }
    if (perfectTree(root))
        cout << "1";
    else
        cout << "0";
    cout << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        transport_node();
    return 0;
}