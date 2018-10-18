#include <string>
#include <queue>
#include <map>
using namespace std;

struct Node
{
    Node(const pair<char, int> &val) : p(val) {}
    pair<char, int> p;
};

bool operator<(const Node &a, const Node &b)
{
    return a.p.second < b.p.second;
}

class Solution
{
  public:
    string frequencySort(string s)
    {
        map<char, int> mp;
        priority_queue<Node, vector<Node>, less<Node>> pq;
        for (auto e : s)
        {
            ++mp[e];
        }
        for (auto e : mp)
        {
            pq.push(make_pair(e.first, e.second));
        }
        string res;
        while (!pq.empty())
        {
            for (int i = 0; i < pq.top().p.second; ++i)
                res.push_back(pq.top().p.first);
            pq.pop();
        }
        return res;
    }
};

int main()
{
    Solution s;
    auto res = s.frequencySort("Aabbtreeaacccc");
    return 0;
}