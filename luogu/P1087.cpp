#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
string str;
string res;

char fen(string &str, int beg, int end)
{
    char ans;
    if (beg < end)
    {

        int mid = (beg + end) / 2;
        char left = fen(str, beg, mid);
        char right = fen(str, mid + 1, end);
        if (left == 'I')
        {
            if (right == 'I')
                ans = 'I';
            else
                ans = 'F';
        }
        else if (left == 'B')
        {
            if (right == 'B')
                ans = 'B';
            else
                ans = 'F';
        }
        if (left == 'F' || right == 'F')
            ans = 'F';
        res.push_back(ans);
        return ans;
    }
    if (str[beg] == '0')
        ans = 'B';
    else
        ans = 'I';
    res.push_back(ans);
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);

    cin >> str;
    fen(str, 0, str.size() - 1);
    cout << res << endl;
    return 0;
}
