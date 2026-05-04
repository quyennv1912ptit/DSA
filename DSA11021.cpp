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

void leaf(Node* root) {
    if(root == nullptr) return;
    if(root->left == nullptr && root->right == nullptr) {
        cout << root->data << " ";
    }
    leaf(root->left);
    leaf(root->right);
    // int l = 0;
    // if(root->left) l = leaf(root->left);
    // int r = 0;
    // if(root->right) r = leaf(root->right);
    // return l+r;
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
        
        leaf(root);

        cout << "\n";

    }
}