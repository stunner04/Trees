/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };

***********************************************************/

void inorderTraversal(BinaryTreeNode<int> *&root, int &count)
{
    if (root == nullptr)
        return;
    inorderTraversal(root->left, count);
    if (root->left == nullptr && root->right == nullptr)
    {
        count++;
    }
    inorderTraversal(root->right, count);
}

int noOfLeafNodes(BinaryTreeNode<int> *root)
{
    int count = 0;
    inorderTraversal(root, count);
    return count;
}

// https://www.codingninjas.com/studio/problems/count-leaf-nodes_893055?source=youtube&campaign=LoveBabbar_Codestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudio&leftPanelTabValue=PROBLEM