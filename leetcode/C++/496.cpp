#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
  public:
    vector<int> res;
    vector<int> nextGreaterElement(vector<int> &findNums, vector<int> &nums)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (auto n : findNums)
            {
                if (nums[i] == n)
                    m[n] = i;
            }
        }
        for (auto num : findNums)
        {
            bool flag = false;
            for (int i = m[num]; i < nums.size(); ++i)
            {
                if (nums[i] > num)
                {
                    res.push_back(nums[i]);
                    flag = true;
                    break;
                }
            }
            if (!flag)
                res.push_back(-1);
        }
        return res;
    }
};