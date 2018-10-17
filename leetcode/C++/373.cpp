#include <vector>
#include <numeric>
#include <climits>
#include <queue>
#include<functional>
using namespace std;

struct Node
{
    friend class Solution;
    pair<int, int> p;
    Node(int a, int b)
    {
        p.first = a;
        p.second = b;
    }
    Node(const pair<int, int> &v)
    {
        p = v;
    }
};
bool operator>(const Node &n1, const Node &n2)
{
    return (n1.p.first + n1.p.second) > (n2.p.first + n2.p.second);
}

class Solution
{
  public:
    vector<pair<int, int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        priority_queue<Node, vector<Node>, greater<Node>> res;
        for (size_t i = 0; i < nums1.size(); ++i)
        {
            for (size_t j = 0; j < nums2.size(); ++j)
            {
                auto val = make_pair(nums1[i], nums2[j]);
                res.push(val);
            }
        }
        if (k > res.size())
            k = res.size();
        vector<pair<int, int>> r;
        for (size_t i = 0; i < k; ++i)
        {
            r.push_back(res.top().p);
            res.pop();
        }
        return r;
    }

    void insert(vector<pair<int, int>> &res, pair<int, int> &val)
    {
        if (res.size() == 0)
        {
            res.push_back(val);
            return;
        }
        res.push_back(make_pair(INT_MAX, INT_MAX));
        vector<long long> sum;
        long long tmp = val.first + val.second;
        for (size_t i = 0; i < res.size(); ++i)
            sum.push_back(res[i].first + res[i].second);
        size_t i;
        for (i = sum.size(); i / 2 > 0 && sum[i / 2 - 1] > tmp; i /= 2)
        {
            sum[i - 1] = sum[i / 2 - 1];
            res[i - 1] = res[i / 2 - 1];
        }
        sum[i - 1] = tmp;
        res[i - 1] = val;
    }

    pair<int, int> removeMin(vector<pair<int, int>> &nums)
    {
        auto min = nums[0];
        auto last = nums[nums.size() - 1];
        auto lastValue = nums[nums.size() - 1].first + nums[nums.size() - 1].second;
        size_t child;
        size_t i;
        vector<long long> sum;
        for (size_t i = 0; i < nums.size(); ++i)
            sum.push_back(nums[i].first + nums[i].second);
        for (i = 1; i * 2 < nums.size(); i = child)
        {
            child = i * 2;
            if (child != nums.size() - 1 && sum[child - 1] > sum[child])
                ++child;
            if (sum[child - 1] > lastValue)
                break;
            else
            {
                nums[i - 1] = nums[child - 1];
                sum[i - 1] = sum[child - 1];
            }
        }
        nums[i - 1] = last;
        nums.pop_back();
        return min;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 4, 5, 6};
    vector<int> nums2 = {3, 5, 7, 9};
    auto r = s.kSmallestPairs(nums1, nums2, 3);

    return 0;
}