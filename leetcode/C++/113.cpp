#include "tree.h"
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> ans;
    int s{0};
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        if (root == 0)
            return ans;
        s = sum;
        vector<int> v;
        dfs(root, 0, v);
        return ans;
    }
    void dfs(TreeNode *r, int sum, vector<int> &v)
    {
        v.push_back(r->val);
        if (r->left == 0 && r->right == 0)
        {
            if (r->val + sum == s)
                ans.push_back(vector<int>(v));
        }
        if (r->left != 0)
            dfs(r->left, sum + r->val, v);
        if (r->right != 0)
            dfs(r->right, sum + r->val, v);
        v.pop_back();
    }
};