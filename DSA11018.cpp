#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

void insert(Node *&root, int x) {
    if(root == nullptr) {
        root = new Node(x);
        return;
    }
    if(root->data < x) insert(root->right, x);
    if(root->data > x) insert(root->left, x);
}

void pre_order(Node *root) {
    if(root == nullptr) return;
    cout << root->data << " ";
    pre_order(root->left);
    pre_order(root->right);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        Node* root = nullptr;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            insert(root, x);
        }

        pre_order(root);

        cout << "\n";
    }
}