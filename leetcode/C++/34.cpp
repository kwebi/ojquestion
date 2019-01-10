#include <vector>
using namespace std;
class Solution
{
  public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> res(2);
        auto len = nums.size();
        int beg = 0;
        int end = len - 1;
        while (beg <= end)
        {
            int mid = (beg + end) / 2;
            if (nums[mid] == target)
            {
                auto p = find(nums, mid);
                res[0] = p.first;
                res[1] = p.second;
                return res;
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else if (nums[mid] < target)
            {
                beg = mid + 1;
            }
        }
        res[0] = -1;
        res[1] = -1;

        return res;
    }
    pair<int, int> find(vector<int> &nums, int index)
    {
        int i = index;
        int j = index;
        while (i >= 0 && nums[i] == nums[index])
        {
            --i;
        }
        while (j < nums.size() && nums[j] == nums[index])
        {
            ++j;
        }
        return pair<int, int>{i + 1, j - 1};
    }
};

int main()
{
    Solution s;
    auto nums = vector<int>{0, 0, 0, 1, 2, 3};
    auto v = s.searchRange(nums, 0);
    return 0;
}