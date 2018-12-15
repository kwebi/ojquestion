#include <vector>

using namespace std;

class Solution
{
  public:
    int ids[3]{0};
    vector<int> uglys;

    int nthUglyNumber(int n)
    {
        uglys.resize(n);
        uglys[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            int a = uglys[ids[0]] * 2;
            int b = uglys[ids[1]] * 3;
            int c = uglys[ids[2]] * 5;
            int min = minInt(a, minInt(b, c));
            if (a == min)
                ++ids[0];
            if (b == min)
                ++ids[1];
            if (c == min)
                ++ids[2];
            uglys[i] = min;
        }
        return uglys[n - 1];
    }
    int minInt(int a, int b)
    {
        return a < b ? a : b;
    }
};

int main()
{
    Solution s;
    int res = s.nthUglyNumber(1695);
    return 0;
}