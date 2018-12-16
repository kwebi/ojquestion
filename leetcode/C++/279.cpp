#include <vector>
#include <utility>
using namespace std;

class Solution
{
  public:
    vector<int> v;
    int numSquares(int n)
    {
        v.resize(n + 1);
        for (int i = 0; i <= n; ++i)
        {
            v[i] = INT_MAX;
        }
        for (int i = 1; i <= sqrt(n); ++i)
        {
            v[i * i] = 1;
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; i + j * j <= n; ++j)
            {
                v[i + j * j] = minInt(v[i] + 1, v[i + j * j]);
            }
        }
        return v[n];
    }
    int minInt(int a, int b)
    {
        return a < b ? a : b;
    }
};