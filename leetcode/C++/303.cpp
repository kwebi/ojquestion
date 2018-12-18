#include <vector>
using namespace std;

class NumArray
{
  public:
    vector<int> dp;
    NumArray(const vector<int> &nums)
    {
        dp.resize(nums.size());
        if (!nums.empty())
            dp[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            dp[i] = nums[i] + dp[i - 1];
        }
    }

    int sumRange(int i, int j)
    {
        if (i == 0)
        {
            return dp[j];
        }
        return dp[j] - dp[i - 1];
    }
};
