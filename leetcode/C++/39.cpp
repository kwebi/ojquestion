#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        auto len = candidates.size();
        vector<int> tmp;
        combinationSum(candidates, target, res, tmp, 0);
        return res;
    }
    void combinationSum(vector<int> &cand, int target, vector<vector<int>> &res, vector<int> &tmp, int beg)
    {
        if (!target)
        {
            res.push_back(tmp);
            return;
        }
        for (int i = beg; i != cand.size() && target >= cand[i]; ++i)
        {
            tmp.push_back(cand[i]);
            combinationSum(cand, target - cand[i], res, tmp, i);
            tmp.pop_back();
        }
    }
};

int main()
{
    vector<int> cand{2, 3, 6, 7};
    auto s = Solution();
    auto res = s.combinationSum(cand, 7);
    return 0;
}