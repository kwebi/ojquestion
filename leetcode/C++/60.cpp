#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution
{
  public:
    string getPermutation(int n, int k)
    {
        vector<int> dec(n, 1), index(n, 1);
        string res;
        for (int i = 1; i < n; ++i)
        {
            dec[i] *= dec[i - 1] * i;
            index[i] = i + 1;
        }
        --k;
        for (int i = n - 1; i >= 0; --i)
        {
            int pos = k / dec[i];
            res.push_back('0' + index[pos]);
            index.erase(index.begin() + pos);
            k %= dec[i];
        }
        return res;
    }
};
int main()
{
    Solution s;
    auto res = s.getPermutation(4, 9);
    return 0;
}