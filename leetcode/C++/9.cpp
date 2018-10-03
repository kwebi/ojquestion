#include <vector>
using namespace std;
class Solution
{
  public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }

        vector<int> v;
        int t = x;
        while (t >= 1)
        {
            v.push_back(t % 10);
            t /= 10;
        }
        if (v.size() == 1 || x == 0)
        {
            return true;
        }
        bool res1 = true;
        vector<int>::size_type i = 0;
        vector<int>::size_type j = v.size() - 1;

        while (i <= j)
        {
            if (v[i] != v[j])
            {
                res1 = false;
                break;
            }
            ++i;
            --j;
        }
        return res1;
    }
};

int main()
{
    Solution s;
    bool res = s.isPalindrome(0);
    return 0;
}