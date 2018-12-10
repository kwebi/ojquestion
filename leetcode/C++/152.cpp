#include <vector>
using namespace std;

class Solution
{
  public:
    int maxProduct(vector<int> &nums)
    {
        int local_min = nums[0];
        int local_max = nums[0];
        int global = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            int local_max_copy = local_max;
            int A = nums[i];
            local_max = maxInt(maxInt(A, A * local_max), local_min * A);
            local_min = minInt(minInt(A, A * local_max_copy), local_min * A);
            global = maxInt(global, local_max);
        }
        return global;
    }
    int maxInt(int a, int b)
    {
        return a > b ? a : b;
    }
    int minInt(int a, int b)
    {
        return a > b ? b : a;
    }
};

int main()
{
    Solution s;
    vector<int> nums{1, -2, 3, -2};
    int res = s.maxProduct(nums);
    return 0;
}