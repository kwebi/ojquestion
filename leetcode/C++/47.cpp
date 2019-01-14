#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        status.resize(nums.size());
        sort(nums.begin(), nums.end());
        dfs(nums);
        return res;
    }

  private:
    vector<bool> status;
    vector<int> tmp;
    vector<vector<int>> res;
    void dfs(vector<int> &nums)
    {
        if (tmp.size() == nums.size())
        {
            res.push_back(vector<int>(tmp));
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (status[i] == true)
                continue;

            status[i] = true;
            tmp.push_back(nums[i]);
            dfs(nums);
            tmp.pop_back();
            status[i] = false;
            int j = i + 1;
            while (j < nums.size() && nums[j] == nums[i])
                ++j;
            i = j - 1;
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums{1, 1, 3};
    auto res = s.permuteUnique(nums);
    return 0;
}