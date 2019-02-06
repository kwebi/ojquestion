#include "tree.h"
class Solution
{
  public:
    void flatten(TreeNode *root)
    {
        TreeNode *p = root;
        while (p != nullptr)
        {
            if (p->left != nullptr)
            {
                TreeNode *left = p->left;
                while (left->right != nullptr)
                {
                    left = left->right;
                }
                left->right = p->right;
                p->right = p->left;
                p->left = nullptr;
            }
            p = p->right;
        }
    }
};