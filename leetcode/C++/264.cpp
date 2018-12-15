#include <vector>
#include <map>
using namespace std;

class Solution
{
  public:
    int num[1695];
    map<int, bool> have;

    int nthUglyNumber(int n)
    {
        num[0] = 1;
        have[0] = true;
        num[1] = 2;
        have[1] = true;
        num[2] = 3;
        have[2] = true;
        num[3] = 4;
        have[3] = true;
        num[4] = 5;
        have[4] = true;
        have[5] = true;
        int index = 5;
        for (double t = 6; index < n; ++t)
        {
            if (t / 2 - int(t / 2) < 1e-9)
            {
                if (have[int(t / 2)] != false)
                {
                    num[index] = t;
                    have[int(t)] = true;
                    ++index;
                }
            }
            else if (t / 3 - int(t / 3) < 1e-9)
            {
                if (have[int(t / 3)] != false)
                {
                    num[index] = t;
                    have[int(t)] = true;
                    ++index;
                }
            }
            else if (t / 5 - int(t / 5) < 1e-9)
            {
                if (have[int(t / 5)] != false)
                {
                    num[index] = t;
                    have[int(t)] = true;
                    ++index;
                }
            }
        }
        return num[n - 1];
    }
};

int main()
{
    Solution s;
    int res = s.nthUglyNumber(1695);
    return 0;
}