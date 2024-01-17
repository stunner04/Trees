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

void *levelOrderTraversal(TreeNode *&root)
{
    queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        TreeNode *frontElement = q.front();
        q.pop();

        if (frontElement == nullptr)
        {
            cout << "\n";
            if (!q.empty())
            {                    // having the elements
                q.push(nullptr); // Mark the end of a level
            }
        }
        else
        {
            cout << frontElement->data << " ";
            if (frontElement->left)
            {
                q.push(frontElement->left);
            }
            if (frontElement->right)
            {
                q.push(frontElement->right);
            }
        }
    }
}

int main()
{

    TreeNode *root = nullptr;
    root = buildBinaryTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << "Level Order traversal "
         << "\n";

    levelOrderTraversal(root);
}
