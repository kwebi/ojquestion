#include <vector>
using namespace std;

class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        int a = 0, b = 0;
        int len = nums.size();
        for (int i = 0; i < len - 1; ++i)
        {
            int m = a, n = b;
            a = n + nums[i];
            b = maxInt(m, n);
        }
        int r1 = maxInt(a, b);
        if (len <= 2)
        {
            if (len == 1)
            {
                return nums[0];
            }
            else if (len == 0)
            {
                return 0;
            }
            else if (len == 2)
            {
                return maxInt(nums[0], nums[1]);
            }
        }
        a = 0;
        b = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            int m = a, n = b;
            a = n + nums[i];
            b = maxInt(m, n);
        }
        int r2 = maxInt(a, b);
        return maxInt(r1, r2);
    }
    int maxInt(int a, int b)
    {
        return a > b ? a : b;
    }
};

int main()
{
    Solution s;
    vector<int> nums{1};
    int res = s.rob(nums);
    return 0;
}