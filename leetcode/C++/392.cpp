#include <string>
using namespace std;
class Solution
{
  public:
    bool isSubsequence(string s, string t)
    {
        int index = 0;
        if (s.empty())
            return true;
        for (int i = 0; i < t.size(); ++i)
        {
            if (t[i] == s[index])
                ++index;
            if (index == s.size())
                return true;
        }
        return false;
    }
};