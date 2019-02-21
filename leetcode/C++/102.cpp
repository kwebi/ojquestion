#include "tree.h"
#include <vector>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if(root==nullptr)
            return res;
        dfs(root,0);
        return res;
    }
    void dfs(TreeNode *r, int dep)
    {
        int size=res.size();
        if (dep > size - 1)
            res.push_back(vector<int>{});
        res[dep].push_back(r->val);
        if (r->left != nullptr)
        {
            dfs(r->left, dep + 1);
        }
        if (r->right != nullptr)
        {
            dfs(r->right, dep + 1);
        }
    }
};