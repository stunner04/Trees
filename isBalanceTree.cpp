// https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1

/**
 * @snippetdoc
 * This code runs in O(n^2) time because we are first calling the [isBalanced] function and
 * again calling the [height] function for same the node which in turns lead to quadratic time complexity.
 */

class Solution
{
private:
    int height(Node *root)
    {

        if (root == NULL)
            return 0;

        int leftt = height(root->left);
        int rightt = height(root->right);

        int ans = max(leftt, rightt) + 1;
        return ans;
    }

public:
    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if (root == NULL)
            return true;

        bool leftt = isBalanced(root->left);
        bool rightt = isBalanced(root->right);
        bool ans = abs(height(root->left) - height(root->right)) <= 1;

        if (leftt && rightt && ans)
            return true;
        else
            return false;
    }
};

/**
 * @snippetdoc
 * We simantaneously calculating the height of the tree with checking tree is balanced or not.
 * This gives time of O(n) and space of O(h), h is height of tree for recursive function call stack.
 */

class Solution
{
private:
    pair<bool, int> isBalanceLinearTime(Node *root)
    {

        // base case when root is null then node is balanced
        if (root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        // stores the return value-pair from the child function call of lrft and right tree
        pair<bool, int> leftTreePair = isBalanceLinearTime(root->left);
        pair<bool, int> rightTreePair = isBalanceLinearTime(root->right);

        // Extracting the isBalance and height from both(pairs) trees
        bool leftTreeBalanceAns = leftTreePair.first;
        bool rightTreeBalanceAns = rightTreePair.first;
        bool diffLeftRightAns = abs(leftTreePair.second - rightTreePair.second) <= 1;

        // Return the call to the parent with the ans if all above value is true(balanced) update the first value

        pair<bool, int> ansReturn;

        // Return the call to the parent with the height update the second value
        ansReturn.second = max(leftTreePair.second, rightTreePair.second) + 1;

        // Return the call to the parent with the ans if all above value is true(balanced) update the first value
        if (leftTreeBalanceAns && rightTreeBalanceAns && diffLeftRightAns)
        {
            ansReturn.second = true;
        }
        else
        {
            ansReturn.second = false;
        }
        // Return the ans pair
        return ansReturn;
    }

public:
    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return isBalanceLinearTime(root).first;
    }
};
