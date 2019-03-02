/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (20.72%)
 * Total Accepted:    36.5K
 * Total Submissions: 176.2K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); ++k)
        {
            vector<int> v;
            v.push_back(nums[k]);
            for (int i = k + 1, j = nums.size() - 1; i < nums.size() && i < j && j > k;)
            {
                if (nums[k] + nums[i] + nums[j] < 0)
                {
                    ++i;
                    continue;
                }
                else if (nums[k] + nums[i] + nums[j] > 0)
                {
                    --j;
                    continue;
                }
                v.push_back(nums[i]);
                v.push_back(nums[j]);
                res.push_back(vector<int>(v));
                v.pop_back();
                v.pop_back();
                while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                {
                    ++i;
                }
                ++i;
            }
            while (k + 1 < nums.size() && nums[k + 1] == nums[k])
            {
                ++k;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> v{-1, 0, 0, 1};
    auto res = s.threeSum(v);
    return 0;
}