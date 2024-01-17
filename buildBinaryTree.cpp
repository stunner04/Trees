#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;

    TreeNode(int root)
    {
        this->data = root;
        left = right = nullptr;
    }
};

TreeNode *buildBinaryTree(TreeNode *root)
{
    int data;
    cin >> data;

    root = new TreeNode(data);

    if (data == -1)
    {
        return nullptr;
    }

    cout << "Left child of " << data << "\n";
    root->left = buildBinaryTree(root->left);

    cout << "Right child of " << data << "\n";
    root->right = buildBinaryTree(root->right);
    return root;
}

int main()
{

    TreeNode *root = nullptr;
    root = buildBinaryTree(root);

    return 0;
}