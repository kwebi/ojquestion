#include <string>
using namespace std;
class Solution
{
  public:
    bool isValid(string s)
    {
        string res;
        for (auto e : s)
        {
            if (!res.empty())
            {
                if (e == ')')
                {
                    if (res.back() == '(')
                    {
                        res.pop_back();
                        continue;
                    }
                }
                else if (e == '}')
                {
                    if (res.back() == '{')
                    {
                        res.pop_back();
                        continue;
                    }
                }
                else if (e == ']')
                {
                    if (res.back() == '[')
                    {
                        res.pop_back();
                        continue;
                    }
                }
            }
            res.push_back(e);
        }
        if (res == "")
            return true;
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution s;
    auto res = s.isValid("([)]");
    return 0;
}