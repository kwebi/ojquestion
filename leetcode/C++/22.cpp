#include <vector>
#include <string>
using namespace std;

class Solution
{
  public:
    int N;
    vector<string> res;
    vector<string> generateParenthesis(int n)
    {
        N = n * 2;
        string s;
        dfs(0, 0, 0, false, s);
        return res;
    }
    void dfs(int count, int status, int st, bool c, string &s)
    {
        ++count;

        if (c)
        {
            s.push_back(')');
            ++st;
        }
        else
        {
            s.push_back('(');
            status -= 1;
            --st;
        }
        if (count == N)
        {
            res.push_back(string(s));
            return;
        }

        if (st == 0)
        {
            dfs(count, status, st, false, s);
        }
        else if (status == -(N / 2))
            dfs(count, status, st, true, s);
        else
        {
            dfs(count, status, st, false, s);
            s.pop_back();
            dfs(count, status, st, true, s);
        }
        s.pop_back();
    }
};

int main()
{
    Solution s;
    auto res = s.generateParenthesis(3);
    return 0;
}