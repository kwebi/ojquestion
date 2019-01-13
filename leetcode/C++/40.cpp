#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> res;
    int len;
    int tar;
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        len = candidates.size();
        tar = target;
        vector<int> t;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, t, 0, 0);
        return res;
    }
    void dfs(vector<int> &can, vector<int> &tmp, int index, int sum)
    {
        if (sum == tar)
        {
            res.push_back(tmp);
            return;
        }
        else if (sum > tar)
            return;
        for (int i = index; i < len; ++i)
        {
            tmp.push_back(can[i]);

            dfs(can, tmp, i + 1, sum + can[i]);
            int j = i + 1;
            while (j < len && can[j] == can[i])
            {
                ++j;
            }
            i = j - 1;
            tmp.pop_back();
        }
    }
};

int main()
{
    Solution s;
    vector<int> can{3, 1, 3, 5, 1, 1};
    auto res = s.combinationSum2(can, 8);
    return 0;
}