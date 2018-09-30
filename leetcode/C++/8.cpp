#include <string>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
  public:
    int myAtoi(string str)
    {
        if (str.empty())
        {
            return 0;
        }

        string::size_type i = 0;
        int z = 0;
        int f = 0;
        while (i < str.size())
        {
            if (str[i] == ' ')
            {
                ++i;
            }
            else if (str[i] == '+')
            {
                if (i + 1 == str.size() || !(str[i + 1] >= '0' && str[i + 1] <= '9'))
                {
                    return 0;
                }
                ++i;
                ++z;
            }
            else if (str[i] == '-')
            {
                if (i + 1 == str.size() || !(str[i + 1] >= '0' && str[i + 1] <= '9'))
                {
                    return 0;
                }
                ++i;
                --f;
            }
            else if (str[i] >= '0' && str[i] <= '9')
            {
                break;
            }
            else
            {
                return 0;
            }
        }

        if (!((z == 0 || z == 1) && (f == -1 || f == 0) && !(z == 1 && f == -1)) || i == str.size())
        {
            return 0;
        }

        string::size_type j = i;
        while (j < str.size())
        {
            if (!(str[j] >= '0' && str[j] <= '9'))
            {
                break;
            }
            ++j;
        }

        --j;

        vector<int> vec;
        for (string::size_type k = i; k <= j; ++k)
        {
            vec.push_back(str[k] - '0');
        }

        int length = vec.size();
        long long sum = 0;

        int max_len = 0;
        for (vector<int>::size_type k = 0; k < vec.size(); ++k)
        {
            if (vec[k] == 0)
            {
                ++max_len;
            }
            else
            {
                break;
            }
        }
        max_len = length - max_len;
        for (vector<int>::size_type k = 0; k < vec.size(); ++k)
        {

            sum += static_cast<long long>(pow(10LL, length - k - 1)) * static_cast<long long>(vec[k]);
            if (f == -1)
            {
                if (sum > (long long)((unsigned)~0 >> 1) + 1 || max_len > 10)
                {
                    return -(int)((unsigned)~0 >> 1) - 1;
                }
            }
            else
            {
                if (sum > (long long)((unsigned)~0 >> 1) || max_len > 10)
                {
                    return (int)((unsigned)~0 >> 1);
                }
            }
        }
        if (f == -1)
        {
            return static_cast<int>(sum) * -1;
        }
        else
        {
            return static_cast<int>(sum);
        }
    }
};

int main()
{
    string s;
    cin >> s;
    Solution so;
    cout << so.myAtoi(s) << endl;
    return 0;
}