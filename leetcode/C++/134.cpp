#include <vector>

#define left(i) (gas[i] - cost[i])
using namespace std;
class Solution
{
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int t = 0;
        int lack = 0;
        int index = 0;
        for (int i = 0; i < gas.size(); ++i)
        {
            t += left(i);
            if (t < 0)
            {
                index = i + 1;
                lack += t;
                t = 0;
            }
        }
        return t + lack >= 0 ? index : -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> g{5, 8, 2, 8};
    vector<int> c{6, 5, 6, 6};
    auto res = s.canCompleteCircuit(g, c);
    return 0;
}
