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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode *build(vector<int> &inorder, int beg1, int end1, vector<int> &postorder, int beg2, int end2)
    {
        if (beg2 > end2)
            return NULL;
        else if (beg2 == end2)
            return new TreeNode(postorder[end2]);
        TreeNode *root = new TreeNode(postorder[end2]);
        int i;
        for (i = end1; i >= beg1; --i)
        {
            if (inorder[i] == postorder[end2])
            {
                break;
            }
        }
        int rightLen = end1 - i;
        root->left = build(inorder, beg1, end1 - rightLen - 1, postorder, beg2, end2 - 1 - rightLen);
        root->right = build(inorder, end1 - rightLen + 1, end1, postorder, end2-rightLen, end2 - 1);
        return root;
    }
};

int main()
{
    Solution s;
    vector<int> inorder{1, 2, 3, 4};
    vector<int> postorder{2, 1, 4, 3};
    auto res = s.buildTree(inorder, postorder);
    return 0;
}