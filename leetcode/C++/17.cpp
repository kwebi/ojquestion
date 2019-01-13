#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Solution
{
  public:
    map<char, string> m;

    Solution()
    {
        char c = 'a';
        for (int i = 2; i < 10; ++i)
        {
            string s;
            for (int i = 0; i < 3; ++i)
            {
                s.push_back(c + i);
            }
            m[i + '0'] = s;
            c += 3;
            if (i == 7)
            {
                c += 1;
            }
        }
        m['9'].push_back('z');
        m['7'].push_back('s');
    }
    vector<string> letterCombinations(string digits)
    {

        vector<string> res;
        if (digits.empty())
            return res;
        string s;
        foo(digits, 0, s, res);
        return res;
    }
    void foo(string &digits, int index, string &tmp, vector<string> &res)
    {
        if (index == digits.size())
        {
            res.push_back(string(tmp));
            return;
        }
        auto s = m[digits[index]];

        for (int i = 0; i < s.size(); ++i)
        {
            tmp.push_back(s[i]);
            foo(digits, index + 1, tmp, res);
            tmp.pop_back();
        }
    }
};

int main()
{
    Solution s;
    auto r = s.letterCombinations("23");
    return 0;
}