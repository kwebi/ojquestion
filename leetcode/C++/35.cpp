#include <vector>
using namespace std;
class Solution
{
  public:
    int searchInsert(vector<int> &nums, int target)
    {
        int beg = 0;
        int end = nums.size();
        while (beg < end)
        {
            int mid = (beg + end) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
            {
                end = mid;
            }
            else if (nums[mid] < target)
            {
                beg = mid+1;
            }
        }
        return end;
    }
};

int main()
{
    vector<int> n {1,3,5,6};
    auto res = Solution().searchInsert(n,5);
    return 0;
}