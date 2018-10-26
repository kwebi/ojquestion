#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode *build(vector<int> &preorder, int beg1, int end1, vector<int> &inorder, int beg2, int end2)
    {
        if (beg1 > end1)
            return NULL;
        else if (beg1 == end1)
            return new TreeNode(preorder[beg1]);
        TreeNode *root = new TreeNode(preorder[beg1]);
        int i;
        for (i = beg2; i <= end2; ++i)
        {
            if (inorder[i] == preorder[beg1])
                break;
        }

        int leftLen = i - beg2;
        root->left = build(preorder, beg1 + 1, beg1 + leftLen, inorder, beg2, beg2 + leftLen - 1);
        root->right = build(preorder, beg1 + 1 + leftLen, end1, inorder, beg2 + 1 + leftLen, end2);
        return root;
    }
};