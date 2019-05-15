#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

string create(int x)
{
    string s = "";
    int i = 0;

    if (x == 0)
        return "0";
    do
    {
        if (x & 1)
        {
            string tmp = (s == "" ? "" : "+");

            if (i == 1)
                s = string("2") + tmp + s;
            else
            {
                s = "2(" + create(i) + ")" + tmp + s;
            }
        }
        ++i;
        x >>= 1;
    } while (x > 0);
    return s;
}

int main()
{
    int n;
    scanf("%d", &n);
    string res;
    res = create(n);
    cout << res << endl;
    return 0;
}