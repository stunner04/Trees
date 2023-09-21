#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
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

void preOrderTraversal(Node *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }
    ans.push_back(root->data);           // ROOT
    preOrderTraversal(root->left, ans);  // LEFT
    preOrderTraversal(root->right, ans); // RIGHT
}

void postOrderTraversal(Node *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }
    postOrderTraversal(root->left, ans);  // LEFT
    postOrderTraversal(root->right, ans); // RIGHT
    ans.push_back(root->data);            // ROOT
}

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int s = q.size();
        vector<int> level;

        for (int i = 0; i < s; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
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

// https://takeuforward.org/binary-tree/binary-tree-traversal-inorder-preorder-postorder/