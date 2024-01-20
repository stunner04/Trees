// https://www.geeksforgeeks.org/problems/sum-tree/1

/**
 * @snippetdoc
 * Time complexity is O(N) , each node is visited once,
 * the overall time complexity is proportional to the number of nodes in the tree.
 *
 * The space complexity is determined by the maximum depth of the call stack during the recursive calls.
 * In this case, the space complexity is O(h), where h is the height of the binary tree.
 *
 * In the worst case, where the tree is skewed (all nodes only have a single child),
 * the height of the tree can be N, resulting in O(N) space complexity.
 * In a balanced tree, the height would be log(N), leading to O(log(N)) space complexity.
 */

class Solution
{
private:
    pair<bool, int> isSumTreeLinearTime(Node *root)
    {
        // Base case 1 : If root is empty
        if (root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        // Base case 2 : If root is leaf node
        if (root->left == NULL && root->right == NULL)
        {
            pair<bool, int> p = make_pair(true, root->data);
            return p;
        }

        // stores the return value-pair from the child function call of left and right tree
        pair<bool, int> leftSumTree = isSumTreeLinearTime(root->left);
        pair<bool, int> rightSumTree = isSumTreeLinearTime(root->right);

        // Extracting the isSum and Sum from both(pairs) trees
        bool isLeftSumTreeAns = leftSumTree.first;
        bool isRightSumTreeAns = rightSumTree.first;
        bool checkRootSumValue = ((leftSumTree.second + rightSumTree.second) == root->data);

        // Return the call to the parent with the ans update second value of sum of whole subtree during the current call
        pair<bool, int> ansReturn;
        ansReturn.second = leftSumTree.second + rightSumTree.second + root->data;

        // Return the call to the parent with the ans if all above value is true(Sum is true) update the first value
        if (isLeftSumTreeAns && isRightSumTreeAns && checkRootSumValue)
        {
            ansReturn.first = true;
        }
        else
        {
            ansReturn.first = false;
        }
        return ansReturn;
    }

public:
    bool isSumTree(Node *root)
    {
        return isSumTreeLinearTime(root).first;
    }
}