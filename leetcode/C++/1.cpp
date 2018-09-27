#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res;
        int i;
        int j;
        for (i = 1; i < nums.size(); ++i)
        {
            bool t = false;
            for (j = 0; j < i; ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    t = true;
                    break;
                }
            }
            if (t)
            {
                break;
            }
        }
        res.push_back(j);
        res.push_back(i);
        return res;
    }
};

int main()
{
    Solution s;
    int arr[] = {3, 2, 3};
    vector<int> v(arr, arr + 3);
    vector<int> &nums = v;
    vector<int> res = s.twoSum(nums, 6);
    for (vector<int>::iterator iter = res.begin(); iter != res.end(); ++iter)
    {
        cout << *iter << endl;
    }
}