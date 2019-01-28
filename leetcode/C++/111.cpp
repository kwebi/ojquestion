#include "tree.h"
#include <bits/stdc++.h>
#include <stdio.h>
class Solution
{
  public:
    int min = (1 << 31) - 1;
    int minDepth(TreeNode *root)
    {
        if(root==0)
            return 0;
        depth(root, 0);
        return min;
    }
    void depth(TreeNode *r, int d)
    {
        if (r != 0)
        {
            if (r->left == 0 && r->right == 0)
            {
                min = d + 1 < min ? d + 1 : min;
            }
            else
            {
                depth(r->left, d + 1);
                depth(r->right, d + 1);
            }
        }
    }
};
