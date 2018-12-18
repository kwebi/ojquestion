#include <vector>
using namespace std;

class Solution
{
  public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > dp.back())
            {
                dp.push_back(nums[i]);
            }
            else
            {
                int index = binarySearch(dp, nums[i]);
                dp[index] = nums[i];
            }
        }
        return dp.size();
    }
    int binarySearch(vector<int> &nums, int n)
    {
        int beg = 0;
        int end = nums.size() - 1;
        while (beg < end)
        {
            int mid = (beg + end) / 2;
            if (n < nums[mid])
            {
                end = mid;
            }
            else if (n > nums[mid])
            {
                beg = mid + 1;
            }
            else if (n == nums[mid])
            {
                return mid;
            }
        }
        return end;
    }
};

int main()
{
    Solution s;
    vector<int> nums{1, 3, 10, 7, 9, 12, 15, 18};
    //auto r = s.binarySearch(nums, 10);
    auto r = s.lengthOfLIS(nums);
    return 0;
}