#include <string>
#include <vector>
using namespace std;
class Solution
{
  public:
    string predictPartyVictory(string senate)
    {

        int pos = 0;

        while (true)
        {
            for (long long i = 0; i < senate.size(); ++i)
            {
                for (long long j = i + 1; j < senate.size() + i; ++j)
                {
                    auto t = j;
                    if (t >= senate.size())
                        t -= senate.size();
                    if (senate[t] != senate[i])
                    {
                        senate.erase(senate.begin() + t);
                        break;
                    }
                }
            }
            bool flag = true;
            char cur = '0';
            for (int i = 0; i < senate.size(); ++i)
            {
                if (cur == '0')
                    cur = senate[i];
                else
                {
                    if (senate[i] != cur)
                    {
                        flag = false;
                        break;
                    }
                }
                pos = i;
            }
            if (flag != false)
                break;
        }
        if (senate[pos] == 'R')
            return string("Radiant");
        else
            return string("Dire");
    }
};

int main()
{
    Solution s;
    auto res = s.predictPartyVictory("DRRDRDRDRDDRDRDR");
    return 0;
}