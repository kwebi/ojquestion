#include <string>
using namespace std;

class Solution
{
  public:
    string removeKdigits(string num, int k)
    {
        if (k == num.size())
            return string(1, '0');

        int len = num.size();
        int cop = len - k;
        string res(cop, '0');
        int index = -1;
        for (int j = 0; j < cop; ++j)
        {
            char min;
            index = index + 1;

            min = num[index];
            for (int i = index; i <= len - cop + j; ++i)
            {
                if (num[i] < min)
                {
                    min = num[i];
                    index = i;
                }
            }
            res[j] = min;
        }
        int i = 0;
        while (i < res.size() && res[i] == '0')
        {
            ++i;
        }
        if (i == res.size())
            return string(1, '0');
        else
            return res.substr(i);
    }
};

int main()
{
    string s("10");
    Solution so;
    auto res = so.removeKdigits(s, 1);
    return 0;
}