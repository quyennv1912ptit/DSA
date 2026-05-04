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

int d(Node* root) {
    if(root == nullptr) return 0;
    int l = d(root->left);
    int r = d(root->right);

    return max(l, r) + 1;
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
        
        cout << d(root) - 1 << "\n";

    }
}