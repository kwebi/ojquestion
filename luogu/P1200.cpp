#include <string>
#include <iostream>

using namespace std;

int main()
{
    string a;
    string b;
    cin >> a;
    cin >> b;
    long long r1 = 1;
    long long r2 = 1;
    for (int i = 0; i < a.length(); ++i)
    {
        r1 *= (a[i] - 'A' + 1);
    }
    for (int i = 0; i < b.length(); ++i)
    {
        r2 *= (b[i] - 'A' + 1);
    }
    if (r1 % 47 == r2 % 47)
    {
        cout << "GO" << endl;
    }
    else
    {
        cout << "STAY" << endl;
    }
    return 0;
}
