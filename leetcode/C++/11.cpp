#include <vector>
#include <iostream>
using namespace std;
class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        int value = 0;
        vector<int>::size_type l = 0;
        auto r = height.size() - 1;

        while (l < r)
        {
            int min = height[l] < height[r] ? height[l] : height[r];
            int area = (r - l) * min;
            value = value > area ? value : area;
            if (height[l] < height[r])
            {
                ++l;
            }
            else
            {
                --r;
            }
        }
        return value;
    }
};

int main()
{
    vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution s;
    cout << s.maxArea(v) << endl;
    return 0;
}