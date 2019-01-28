#include "tree.h"
class Solution
{
  public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == 0)
            return true;
        return check(root->left, root->right);
    }
    bool check(TreeNode *node1, TreeNode *node2)
    {
        if (node1 == 0 && node2 == 0)
            return true;
        else if (node1 == 0 && node2 != 0)
            return false;
        else if (node1 != 0 && node2 == 0)
            return false;
        else if (node1->val != node2->val)
            return false;
        else
        {
            return check(node1->left, node2->right) &&
                   check(node1->right, node2->left);
        }
    }
};