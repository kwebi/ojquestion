#include <vector>
#include <iostream>
using namespace std;
class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        vector<int> max;
        for (vector<int>::size_type i = 0; i < height.size() - 1; ++i)
        {
            int imax = height[i + 1] < height[i] ? height[i + 1] : height[i];
            for (vector<int>::size_type j = i + 1; j < height.size(); ++j)
            {
                int min = height[j] < height[i] ? height[j] : height[i];
                int area = min * (j - i);
                if (area > imax)
                {
                    imax = area;
                }
            }
            max.push_back(imax);
        }
        int value = max[0];
        for (auto iter = max.begin(); iter != max.end(); ++iter)
        {
            if (*iter > value)
            {
                value = *iter;
            }
        }
        return value;
    }
};

int main()
{
    vector<int> v = {2, 1};
    Solution s;
    cout << s.maxArea(v) << endl;
    return 0;
}