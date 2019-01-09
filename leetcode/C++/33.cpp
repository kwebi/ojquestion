#include <vector>
using namespace std;
class Solution
{
  public:
    int search(vector<int> &nums, int target)
    {
        auto len = nums.size();
        int beg = 0;
        int end = len - 1;
        while (beg <= end)
        {
            int mid = (beg + end) / 2;
            if (target == nums[mid])
                return mid;
            else if (nums[mid] < nums[end])
            {
                if (target > nums[mid] && target <= nums[end])
                    beg = mid + 1;
                else
                    end = mid - 1;
            }
            else
            {
                if (target >= nums[beg] && target < nums[mid])
                    end = mid - 1;
                else
                    beg = mid + 1;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    Solution s;
    auto res = s.search(nums, 0);
    return 0;
}