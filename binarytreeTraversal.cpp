#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;

class Node
{
    int data;
    Node *left;
    Node *right;

public:
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

void inOrderTraversal(Node *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }

    inOrderTraversal(root->left, ans); // LEFT
    ans.push_back(root->data);
    // cout << root->data <<" "; // ROOT
    inOrderTraversal(root->right, ans); // RIGHT
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = new Node(5);
    root->left = new Node(6);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(9);
    root->left->right->left = new Node(1);

    return 0;
}