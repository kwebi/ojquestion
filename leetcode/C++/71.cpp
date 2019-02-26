#include <vector>
#include <string>
using namespace std;

class Solution
{
  public:
    string simplifyPath(string path)
    {
        vector<string> res;
        int len = path.size();
        for (int i = 0; i < len;)
        {
            while (i < len && path[i] == '/')
            {
                ++i;
            }
            string tmp;
            while (i < len && path[i] != '/')
            {
                tmp.push_back(path[i]);
                ++i;
            }
            if (tmp == "..")
            {
                if (!res.empty())
                {
                    res.pop_back();
                }
            }
            else if (tmp != "." && tmp != "")
            {
                res.push_back(tmp);
            }
        }
        string ans;
        for (int i = 0; i < res.size(); ++i)
        {
            ans.push_back('/');
            ans += res[i];
        }
        if(ans=="")
            return "/";
        return ans;
    }
};

int main()
{
    Solution s;
    auto res = s.simplifyPath("/../");
    return 0;
}