#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
  public:
    string longestPalindrome(string s)
    {
        if (s.empty())
        {
            return s;
        }
        vector<int> vec(s.size(), 0);
        int start = 0;
        int end = s.size() - 1;
        vector<bool> fvec(s.size(), false);
        bool success = false;
        for (string::size_type i = 0; i < s.size(); ++i)
        {
            for (start = i, end = i + 1; start >= 0 && end < s.size(); --start, ++end)
            {
                if (s[start] == s[end])
                {
                    ++vec[i];
                    success = true;
                }
                else
                {
                    break;
                }
            }
            int sum = 0;
            for (start = i - 1, end = i + 1; start >= 0 && end < s.size(); --start, ++end)
            {
                if (s[start] == s[end])
                {
                    success = true;
                    ++sum;
                }
                else
                {
                    break;
                }
            }
            if (sum >= vec[i])
            {
                fvec[i] = true;
                vec[i] = sum;
            }
            else
            {
                fvec[i] = false;
            }
        }
        int index = 0;
        int max = vec[0];
        for (int i = 0; i < s.size() - 1; ++i)
        {
            if (vec[i] > max)
            {
                max = vec[i];
                index = i;
            }
            else if (vec[i] == max && fvec[i] == true)
            {
                max = vec[i];
                index = i;
            }
        }

        if (!success)
        {
            return s.substr(0, 1);
        }
        if (fvec[index])
        {
            return s.substr(index - max, max * 2 + 1);
        }
        else
        {
            return s.substr(index - max + 1, max * 2);
        }
    }
};

int main()
{
    Solution s;
    string str = s.longestPalindrome(string("aacacdd"));
    cout << str << endl;
    return 0;
}