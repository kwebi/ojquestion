/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
#include <vector>
#include <algorithm>
using namespace std;
struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution
{
  public:
    int eraseOverlapIntervals(vector<Interval> &intervals)
    {
        if (intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {
            return a.end < b.end;
        });
        int ans = 1;
        int c_pos = intervals[0].end;
        for (auto &e : intervals)
        {
            if (c_pos <= e.start)
            {
                ++ans;
                c_pos = e.end;
            }
        }
        return intervals.size() - ans;
    }
};