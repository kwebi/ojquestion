#include "tree.h"
class Solution
{
  public:
    bool flag{false};
    int s{0};
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == 0)
            return false;
        s = sum;
        dfs(root, 0);
        return flag;
    }
    void dfs(TreeNode *root, int sum)
    {
        if (root->left == 0 && root->right == 0)
        {
            if (sum + root->val == s)
                flag = true;
        }
        if (root->left != 0)
            dfs(root->left, sum + root->val);
        if (root->right != 0)
            dfs(root->right, sum + root->val);
    }
};