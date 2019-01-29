#include "tree.h"
class Solution
{
  public:
    int max = 0;
    int maxDepth(TreeNode *root)
    {
        if (root == 0)
            return 0;
        depth(root, 1);
        return max;
    }
    void depth(TreeNode *r, int n)
    {
        if (r != 0)
        {
            if (r->left == 0 && r->right == 0)
            {
                max = n > max ? n : max;
            }
            else
            {
                depth(r->left, n + 1);
                depth(r->right, n + 1);
            }
        }
    }
};