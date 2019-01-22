#include <vector>
using namespace std;
class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int sum = 0;
        int beg = 0;
        long long len = prices.size();
        while (beg < len - 1 && prices[beg] > prices[beg + 1])
            ++beg;
        int end = beg + 1;
        while (end < len && beg < end)
        {
            while (end < len && prices[end - 1] < prices[end])
            {
                ++end;
            }
            sum += prices[end - 1] - prices[beg];
            beg = end;
            ++end;
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> p{6, 1, 3, 2, 4, 7};
    Solution s;
    auto res = s.maxProfit(p);
    return 0;
}
