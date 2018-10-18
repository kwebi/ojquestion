#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct Node
{
    Node(const pair<int, int> &v)
    {
        p.first = v.first;
        p.second = v.second;
    }
    Node &operator=(const pair<int, int> &v)
    {
        p.first = v.first;
        p.second = v.second;
        return *this;
    }
    pair<int, int> p;
};
bool operator<(const Node &a, const Node &b)
{
    return a.p.second < b.p.second;
}

class Solution
{
  public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> m;
        for (auto e : nums)
        {
            ++m[e];
        }
        vector<pair<int, int>> tmp;
        for (auto iter = m.begin(); iter != m.end(); ++iter)
        {
            tmp.push_back(make_pair(iter->first, iter->second));
        }
        priority_queue<Node, vector<Node>, less<Node>> v;
        vector<int> res;
        for (auto e : tmp)
        {
            v.push(e);
        }
        for (size_t i = 0; i < k; ++i)
        {
            res.push_back(v.top().p.first);
            v.pop();
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 1, 1, 2, 2, 3};
    s.topKFrequent(v, 2);
    return 0;
}