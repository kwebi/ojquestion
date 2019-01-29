#include "tree.h"
#include <vector>
using namespace std;

class Solution
{
  public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return toBST(nums, 0, nums.size() - 1);
    }
    TreeNode *toBST(vector<int> &nums, int beg, int end)
    {
        if (beg > end)
            return 0;
        int mid = (beg + end) / 2;
        auto node = new TreeNode(nums[mid]);
        node->left = toBST(nums, beg, mid - 1);
        node->right = toBST(nums, mid + 1, end);
        return node;
    }
};