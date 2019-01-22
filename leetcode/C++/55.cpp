#include <vector>
using namespace std;
class Solution
{
  public:
    bool canJump(vector<int> &nums)
    {
        auto len = nums.size();
        if (len == 0)
            return true;
        int pos = nums[0];
        for (int i = 1; i < len && pos >= i; ++i)
        {
            if (nums[i] + i > pos)
                pos = nums[i] + i;
        }
        if (pos >= len - 1)
            return true;
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> n{1, 2, 3};
    auto res = s.canJump(n);
    return 0;
}