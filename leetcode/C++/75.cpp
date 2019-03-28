#include <vector>
using namespace std;
class Solution
{
  public:
    void sortColors(vector<int> &nums)
    {
        int array[3] = {0};
        for (int i = 0; i < nums.size(); ++i)
        {
            switch (nums[i])
            {
            case 0:
                ++array[0];
                break;

            case 1:
                ++array[1];
                break;

            case 2:
                ++array[2];
                break;
            default:
                break;
            }
        }
        for (int i = 0; i < array[0]; ++i)
        {
            nums[i] = 0;
        }
        for (int i = array[0]; i < array[0] + array[1]; ++i)
        {
            nums[i] = 1;
        }
        for (int i = array[0] + array[1]; i < nums.size(); ++i)
        {
            nums[i] = 2;
        }
    }
};