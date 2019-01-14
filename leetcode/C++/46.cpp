#include <vector>
using namespace std;

class Solution
{
  public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> tmp;

        vector<int> status;
        status.resize(nums.size());
        dfs(nums, tmp, status);
        return res;
    }

  private:
    vector<vector<int>> res;
    void dfs(vector<int> &nums, vector<int> &tmp, vector<int> &status)
    {
        if (tmp.size() == nums.size())
        {
            res.push_back(vector<int>(tmp));
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (status[i] == 1)
                continue;
            status[i] = 1;
            tmp.push_back(nums[i]);
            dfs(nums, tmp, status);
            tmp.pop_back();
            status[i] = 0;
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums{1, 2, 3};
    auto res = s.permute(nums);
    return 0;
}