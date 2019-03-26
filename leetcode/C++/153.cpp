#include <vector>
using namespace std;
class Solution
{
  public:
    int findMin(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 1)
            return nums[0];
        if (len == 2)
            return nums[0] < nums[1] ? nums[0] : nums[1];
        int beg = 0;
        int end = len - 1;
        int mid = (beg + end) / 2;
        while (beg < end)
        {
            mid = (beg + end) / 2;
            if (nums[mid] < nums[end])
            {
                end = mid;
            }
            else
            {
                beg = mid + 1;
            }
        }
        return nums[beg];
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    auto res = s.findMin(nums);
    return 0;
}