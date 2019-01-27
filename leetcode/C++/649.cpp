#include <string>
#include <deque>
using namespace std;
class Solution
{
  public:
    string predictPartyVictory(string senate)
    {
        deque<int> rq;
        deque<int> dq;
        int n = senate.length();

        for (int i = 0; i != n; ++i)
        {
            if (senate[i] == 'R')
                rq.push_back(i);
            else
                dq.push_back(i);
        }
        while (!rq.empty() && !dq.empty())
        {
            auto rf = rq.front();
            auto df = dq.front();
            rq.pop_front();
            dq.pop_front();
            if (rf < df)
            {
                rq.push_back(rf + n);
            }
            else
            {
                dq.push_back(df + n);
            }
        }
        if (rq.empty())
            return "Dire";
        else
            return "Radiant";
    }
};

int main()
{
    Solution s;
    auto res = s.predictPartyVictory("DR");
    return 0;
}