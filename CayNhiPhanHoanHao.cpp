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
int leaflevel = 0;
bool checkUntil(Node *root, int level)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
    {
        if (leaflevel == 0)
        {
            leaflevel = level;
            return true;
        }
        return (level == leaflevel);
    }
    return checkUntil(root->left, level + 1) && checkUntil(root->right, level + 1);
}

bool checkNode(Node *root)
{
    int level = 0;
    leaflevel = 0;
    return checkUntil(root, level);
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
    if (perfectTree(root) && checkNode(root))
        cout << "Yes";
    else
        cout << "No";
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