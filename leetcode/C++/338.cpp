#include <vector>
#include <bitset>
using namespace std;
class Solution
{
  public:
    vector<int> countBits(int num)
    {
        vector<int> res(num + 1);
        res[0] = 0;
        for (int i = 1; i <= num; ++i)
        {
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;
    }
};

int main()
{
    Solution s;
    auto v = s.countBits(5);
    return 0;
}