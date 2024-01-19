// https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1

/**
 * @snippetdoc
 * The time complexity of the code is O(n).
 * The space complexity of the code is O(max(h1,h2)).
 * The space complexity is not affected by the number of nodes in the trees,
 * as the memory used for each function call is constant (storing local variables and the return address).
 * The recursive calls for left and right subtrees contribute to the height of the call stack.
 */

class Solution
{
public:
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        // Base Case
        if (r1 == NULL && r2 == NULL)
            return true;
        if (r1 == NULL && r2 != NULL)
            return false;
        if (r1 != NULL && r2 == NULL)
            return false;

        // Storing the returned value from the child function calls
        bool leftTree = isIdentical(r1->left, r2->left);
        bool rightTree = isIdentical(r1->right, r2->right);

        // Checking the value of the currentNode
        bool currentValueNode = (r1->data == r2->data);

        // Returning the boolean value to the parent function call
        if (leftTree && rightTree && currentValueNode)
            return true;
        else
            return false;
    }
};