#include <cmath>
#include <vector>
#include <deque>
using namespace std;
class Solution
{
  public:
    vector<int> plusOne(vector<int> &digits)
    {
        if (digits.back() != 9)
        {
            ++digits.back();
            return digits;
        }
        int i = digits.size() - 1;
        while (i >= 0 && digits[i] == 9)
        {
            digits[i] = 0;
            --i;
        }
        if (i == -1)
        {
            digits.insert(digits.begin(), 1);
            return digits;
        }
        ++digits[i];
        return digits;
    }
};

int main()
{
    Solution s;
    vector<int> v{8, 8, 9, 9, 9};
    auto res = s.plusOne(v);
    return 0;
}