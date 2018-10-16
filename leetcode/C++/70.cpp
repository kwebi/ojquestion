#include <vector>
using namespace std;
class Solution
{
  public:
    int climbStairs(int n)
    {
        vector<size_t> v(n + 5);
        v[1] = 1;
        v[2] = 2;
        for (int i = 3; i <= n; ++i)
        {
            v[i] = v[i - 2] + v[i - 1];
        }
        return v[n];
    }
};