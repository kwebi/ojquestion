/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (54.19%)
 * Total Accepted:    11.7K
 * Total Submissions: 21.6K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 * 
 * 示例:
 * 
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * 输出:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * 说明：
 * 
 * 
 * 所有输入均为小写字母。
 * 不考虑答案输出的顺序。
 * 
 * 
 */
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
  public:
    vector<vector<string>> res{};
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        if (strs.empty())
            return res;
        vector<string> t;
        unordered_map<string, multiset<string>> m;
        for (auto e : strs)
        {
            string s = sortStr(e);
            m[s].insert(e);
        }
        for (auto &e : m)
        {
            vector<string> v(e.second.begin(), e.second.end());
            res.push_back(v);
        }
        return res;
    }
    string sortStr(string &str)
    {
        vector<int> tmp(26, 0);
        for (auto e : str)
        {
            ++tmp[e - 'a'];
        }
        string ans{""};
        for (int i = 0; i < 26; ++i)
        {
            while (tmp[i]--)
            {
                ans.push_back('a' + i);
            }
        }
        return ans;
    }
};

int main()
{
    vector<string> v{"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    auto res = s.groupAnagrams(v);
    return 0;
}