#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

typedef pair<char, char> pch;

long long minres = INT64_MAX;

void cp(vector<pch> &v, int m)
{
    if (m == v.size())
    {
        string t;
        for (int i = 0; i < v.size(); ++i)
        {
            t.push_back(v[i].first);
            t.push_back(v[i].second);
        }
        minres = min(minres, atoll(t.c_str()));
        return;
    }
    for (int j = m; j < v.size(); ++j)
    {
        swap(v[j], v[m]);
        cp(v, m + 1);
        swap(v[j], v[m]);
    }
}

int main()
{
    map<string, int> m;
    m["zero"] = 0;
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;
    m["four"] = 4;
    m["five"] = 5;
    m["six"] = 6;
    m["seven"] = 7;
    m["eight"] = 8;
    m["nine"] = 9;
    m["ten"] = 10;
    m["eleven"] = 11;
    m["twelve"] = 12;
    m["thirteen"] = 13;
    m["fourteen"] = 14;
    m["fifteen"] = 15;
    m["sixteen"] = 16;
    m["seventeen"] = 17;
    m["eighteen"] = 18;
    m["nineteen"] = 19;
    m["twenty"] = 20;
    m["a"] = 1;
    m["both"] = 2;
    m["another"] = 2;
    m["first"] = 1;
    m["second"] = 2;
    m["third"] = 3;

    string s[6];
    for (int i = 0; i < 6; ++i)
        cin >> s[i];
    if (s[5].back() == '.')
        s[5].pop_back();

    vector<pch> v;
    for (int i = 0; i < 6; ++i)
    {
        if (m.find(s[i]) != m.end())
        {
            char t[5];
            sprintf(t, "%02d", (m[s[i]]) * (m[s[i]]) % 100);
            v.push_back(make_pair(t[0], t[1]));
        }
    }
    cp(v, 0);
    printf("%lld", minres);
    return 0;
}
