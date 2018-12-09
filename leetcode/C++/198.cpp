#include <vector>

using namespace std;

class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int m = a, n = b;
            a = n + nums[i];
            b = maxNum(m, n);
        }
        return maxNum(a, b);
    }
    int maxNum(int a, int b)
    {
        return a > b ? a : b;
    }
};