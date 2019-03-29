#include <vector>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> tmp;
        dfs(nums, tmp, 0);
        return res;
    }
    void dfs(vector<int> &nums, vector<int> &tmp, int i)
    {
        res.push_back(vector<int>(tmp));
        for (int j = i; j < nums.size(); ++j)
        {
            tmp.push_back(nums[j]);
            dfs(nums, tmp, j+1);
            tmp.pop_back();
        }
    }
};