#include <vector>
#include <bitset>
using namespace std;
class Solution
{
  public:
    vector<int> countBits(int num)
    {
        vector<int> res(num + 1);
        for (int i = 0; i <= num; ++i)
        {
            bitset<64> b(i);
            res[i] = b.count();
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