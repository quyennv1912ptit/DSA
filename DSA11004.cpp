#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

Node *root;

Node *s(Node *root, int x)
{
    if (root == nullptr)
        return nullptr;

    if (root->data == x)
        return root;

    Node *l = s(root->left, x);

    if (l != nullptr)
        return l;

    return s(root->right, x);
}

void level_order(Node *root)
{
    if (root == nullptr)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node->left != nullptr)
            q.push(node->left);
        if (node->right != nullptr)
            q.push(node->right);

        cout << node->data << " ";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a, b;
        char c;

        root = nullptr;

        for (int i = 0; i < n; i++)
        {

            cin >> a >> b >> c;

            Node *node = s(root, a);

            if (node == nullptr)
            {
                root = new Node(a);
                node = root;
            }

            if (c == 'L')
            {
                node->left = new Node(b);
            }
            else
            {
                node->right = new Node(b);
            }
        }

        level_order(root);

        cout << "\n";
    }
}