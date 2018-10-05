#include <algorithm>
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

class Solution
{
  public:
    string intToRoman(int num)
    {
        int copy = num;
        deque<string> res;
        int i = 0;
        while (copy > 0)
        {
            int part = copy % 10;
            if (i == 0)
            {
                if (part == 9)
                    res.push_front("IX");
                else if (part == 4)
                    res.push_front("IV");
                else
                    push_str(res, "I", "V", part);
            }
            else if (i == 1)
            {
                if (part == 9)
                    res.push_front("XC");
                else if (part == 4)
                    res.push_front("XL");
                else
                    push_str(res, "X", "L", part);
            }
            else if (i == 2)
            {
                if (part == 9)
                    res.push_front("CM");
                else if (part == 4)
                    res.push_front("CD");
                else
                    push_str(res, "C", "D", part);
            }
            else if (i == 3)
            {
                for (int j = 0; j < part; ++j)
                    res.push_front("M");
            }
            copy /= 10;
            ++i;
        }
        return accumulate(res.begin(), res.end(), string(""));
    }

  private:
    void push_str(deque<string> &res, const string &one, const string &five, int num)
    {
        if (num == 0)
            return;
        if (num < 4)
        {
            for (int i = 0; i < num; ++i)
                res.push_front(one);
        }
        else if (num >= 5)
        {

            for (int i = 0; i < num - 5; ++i)
            {
                res.push_front(one);
            }
            res.push_front(five);
        }
    }
};

int main()
{
    Solution s;
    cout << s.intToRoman(4) << endl;
    return 0;
}
