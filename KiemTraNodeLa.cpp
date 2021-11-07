#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define pb push_back
#define eb emplace_back
#define cl(C) C.clear()
#define f first
#define s second
#define cint cpp_int
#define all(C) C.begin(), C.end()
#define run_test() \
    int test;      \
    cin >> test;   \
    cin.ignore();  \
    while (test--)
#define faster()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOR2(i, a, b) for (ll i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define FORA(test, C) for (auto test : C)

#define reset(C) memset(C, 0, sivalue2eof(C))
#define clearQueue(C, test) C = queue<test>()
#define Fill(C, a) fill(C.begin(), C.end(), a)

#define Sort(C) sort(c, c + n)

using namespace std;
/*__________________________________________________________*/

struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *new_node(int value)
{
    Node *node = new Node;
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

int leaflevel = 0;
bool checkUtil(Node *root, int level)
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
    return checkUtil(root->left, level + 1) && checkUtil(root->right, level + 1);
}

bool check(Node *root)
{
    int level = 0;
    leaflevel = 0;
    return checkUtil(root, level);
}

void transport_node()
{
    int test, value1, value2;
    char c;
    cin >> test >> value1 >> value2 >> c;
    Node *root = NULL;
    root = new_node(value1);
    vector<Node *> boot;
    boot.pb(root);
    if (c == 'L')
    {
        root->left = new_node(value2);
        boot.push_back(root->left);
    }
    else
    {
        root->right = new_node(value2);
        boot.push_back(root->right);
    }
    FOR(j, 2, test)
    {
        cin >> value1 >> value2 >> c;
        FORD(i, boot.size() - 1, 0)
        {
            if (boot[i]->data == value1)
            {
                if (c == 'L')
                {
                    boot[i]->left = new_node(value2);
                    boot.pb(boot[i]->left);
                }
                else
                {
                    boot[i]->right = new_node(value2);
                    boot.pb(boot[i]->right);
                }
            }
        }
    }
    cout << check(root) << endl;
}

main()
{
        run_test()
    {
        transport_node();
    }
    return EXIT_SUCCESS;
}