#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
  public:
    int findMinArrowShots(vector<pair<int, int>> &points)
    {
        if (points.empty())
            return 0;
        vector<int> m(points.size());
        sort(points.begin(), points.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.second < b.second;
        });
        int ans = 1;
        int current_pos = points[0].second;
        for (auto &e : points)
        {
            if (e.first > current_pos)
            {
                ++ans;
                current_pos = e.second;
            }
        }
        return ans;
    }
};