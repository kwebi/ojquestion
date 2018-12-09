#include <vector>

using namespace std;

class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 0)
        {
            return 0;
        }
        if (len == 1)
        {
            return nums[0];
        }
        int a = 0;
        int b = 0;
        a = nums[0];
        b = nums[0] > nums[1] ? nums[0] : nums[1];
        for (int i = 2; i < len; ++i)
        {
            int tmp = b;
            b = maxNum(b, a + nums[i]);
            a = tmp;
        }
        return b;
    }
    int maxNum(int a, int b)
    {
        return a > b ? a : b;
    }
};