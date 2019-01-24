#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people)
    {
        vector<pair<int, int>> res;
        sort(people.begin(), people.end(), [](pair<int, int> &a, pair<int, int> &b) -> bool {
            return a.first == b.first ? a.second < b.second : a.first > b.first;
        });
        for (auto val : people)
            res.insert(res.begin() + val.second, val);
        return res;
    }
};
