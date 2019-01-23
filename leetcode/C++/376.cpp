#include <vector>
using namespace std;
class Solution
{
  public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 0)
            return 0;
        else if (len == 1)
            return 1;
        int res = 2;
        int flag = 0;
        if (nums[0] < nums[1])
            flag = 1;
        else if (nums[0] > nums[1])
            flag = -1;
        else
        {
            --res;
        }
        for (int i = 1; i < len - 1; ++i)
        {
            if (flag == 1)
            {
                if (nums[i] > nums[i + 1])
                {
                    ++res;
                    flag = -1;
                }
            }
            else if (flag == -1)
            {
                if (nums[i] < nums[i + 1])
                {
                    ++res;
                    flag = 1;
                }
            }
            else if (flag == 0)
            {
                if (nums[i] < nums[i + 1])
                {
                    flag = 1;
                    ++res;
                }
                else if (nums[i] > nums[i + 1])
                {
                    flag = -1;
                    ++res;
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> n{3, 3, 3, 2, 5};
    auto res = s.wiggleMaxLength(n);
    return 0;
}
