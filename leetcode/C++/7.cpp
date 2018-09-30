#include <vector>
#include <climits>
#include <cmath>
#include <iostream>
using namespace std;

class Solution
{
  public:
    int reverse(int x)
    {
        int z = 1;
        long long tmp = x;
        if (x < 0)
        {
            z = -1;
            tmp = -tmp;
        }

        vector<int> vec;
        int i = 0;
        
        while (tmp >= 1)
        {
            vec.push_back(tmp % 10);
            tmp /= 10;
            ++i;
        }

        int zero_num = 0;
        for (int j = 0; j < vec.size(); ++j)
        {
            if (vec[j] == 0)
            {
                ++zero_num;
            }
            else
            {
                break;
            }
        }

        if (vec.size() - zero_num > 10)
        {
            return 0;
        }

        if (i == 1)
        {
            return x;
        }

        long long sum = 0;
        for (int j = zero_num; j < vec.size(); ++j)
        {
            sum += vec[j] * (static_cast<long long>(pow(10LL, vec.size() - j - 1)));
            if (z == -1)
            {
                if (-sum < INT_MIN)
                {
                    return 0;
                }
            }
            else
            {
                if (sum > INT_MAX)
                {
                    return 0;
                }
            }
        }
        return static_cast<int>(sum * z);
    }
};

int main()
{
    Solution s;
    int num;
    cin >> num;
    cout << s.reverse(num) << endl;
    return 0;
}