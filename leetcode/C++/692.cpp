#include <string>
#include <queue>
#include <map>
using namespace std;
struct Node
{
    Node(const pair<string, int> &val) : p(val) {}
    pair<string, int> p;
};

bool operator<(const Node &a, const Node &b)
{
    if (a.p.second != b.p.second)
        return a.p.second < b.p.second;
    else
        return a.p.first > b.p.first;
}

class Solution
{
  public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        map<string, int> mp;
        priority_queue<Node, vector<Node>, less<Node>> pq;
        for (auto e : words)
        {
            ++mp[e];
        }
        for (auto e : mp)
        {
            pq.push(make_pair(e.first, e.second));
        }
        vector<string> res;
        for (int i = 0; i < k; ++i)
        {
            res.push_back(pq.top().p.first);
            pq.pop();
        }
        return res;
    }
};

int main()
{
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;
    Solution s;
    auto res = s.topKFrequent(words, k);
    return 0;
}