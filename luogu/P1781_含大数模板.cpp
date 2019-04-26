#include <iostream> // 要用cin、cout
#include <string>   // 要用string类
#include <cstring>  // 要用strlen
#include <cstdio>   // 要用sprintf
#include <algorithm>
using namespace std;

const int maxn = 2000; // 大整数的最高位数限制

struct bign
{
    int d[maxn], len;

    // 去掉大数的前导0
    void clean()
    {
        while (len > 1 && !d[len - 1])
            len--;
    }

    // 初始化：默认初始化为值0
    bign()
    {
        memset(d, 0, sizeof(d));
        len = 1;
    }

    // 初始化：可以用“bign [bign] = [int];”或“bign [bign]([int]);”
    bign(int num) { *this = num; }

    // 初始化：可以用“bign [bign] = [char*];”或“bign [bign](char*);”
    bign(char *num) { *this = num; }

    // 赋值：可以用“[bign] = [char*];”
    bign operator=(const char *num)
    {
        len = strlen(num);
        for (int i = 0; i < len; i++)
            d[i] = num[len - 1 - i] - '0';
        clean();
        return *this;
    }

    // 赋值：可以用“[bign] = [int];”
    bign operator=(int num)
    {
        char s[maxn];
        sprintf(s, "%d", num);
        *this = s;
        return *this;
    }
    bign operator+(const bign &b)
    {
        bign c = *this;
        int i;
        for (i = 0; i < b.len; i++)
        {
            c.d[i] += b.d[i];
            if (c.d[i] > 9)
                c.d[i] %= 10, c.d[i + 1]++;
        }
        while (c.d[i] > 9)
            c.d[i++] %= 10, c.d[i]++;
        c.len = len > b.len ? len : b.len;
        if (c.d[i] && c.len <= i)
            c.len = i + 1;
        return c;
    }
    bign operator-(const bign &b)
    {
        bign c = *this;
        int i;
        for (i = 0; i < b.len; i++)
        {
            c.d[i] -= b.d[i];
            if (c.d[i] < 0)
                c.d[i] += 10, c.d[i + 1]--;
        }
        while (c.d[i] < 0)
            c.d[i++] += 10, c.d[i]--;
        c.clean();
        return c;
    }
    bign operator*(const bign &b) const
    {
        int i, j;
        bign c;
        c.len = len + b.len;
        for (j = 0; j < b.len; j++)
            for (i = 0; i < len; i++)
                c.d[i + j] += d[i] * b.d[j];
        for (i = 0; i < c.len - 1; i++)
            c.d[i + 1] += c.d[i] / 10, c.d[i] %= 10;
        c.clean();
        return c;
    }
    bign operator/(const bign &b)
    {
        int i, j;
        bign c = *this, a = 0;
        for (i = len - 1; i >= 0; i--)
        {
            a = a * 10 + d[i];
            for (j = 0; j < 10; j++)
                if (a < b * (j + 1))
                    break;
            c.d[i] = j;
            a = a - b * j;
        }
        c.clean();
        return c;
    }
    bign operator%(const bign &b)
    {
        int i, j;
        bign a = 0;
        for (i = len - 1; i >= 0; i--)
        {
            a = a * 10 + d[i];
            for (j = 0; j < 10; j++)
                if (a < b * (j + 1))
                    break;
            a = a - b * j;
        }
        return a;
    }
    bign operator+=(const bign &b)
    {
        *this = *this + b;
        return *this;
    }

    bool operator<(const bign &b) const
    {
        if (len != b.len)
            return len < b.len;
        for (int i = len - 1; i >= 0; i--)
            if (d[i] != b.d[i])
                return d[i] < b.d[i];
        return false;
    }
    bool operator>(const bign &b) const { return b < *this; }
    bool operator<=(const bign &b) const { return !(b < *this); }
    bool operator>=(const bign &b) const { return !(*this < b); }
    bool operator!=(const bign &b) const { return b < *this || *this < b; }
    bool operator==(const bign &b) const { return !(b < *this) && !(b > *this); }

    // 将int数组存储的值转换为高精度的字符串形式
    string str() const
    {
        string res;
        for (int i = 0; i < len; i++)
            res = char(d[i] + '0') + res;
        return res;
    }
};

// 可以用“cin >> [bign];”的方式输入
istream &operator>>(istream &in, bign &x)
{
    string s;
    in >> s;
    x = s.c_str();
    return in;
}

// 可以用“cout << [bign];”的方式输出
ostream &operator<<(ostream &out, const bign &x)
{
    out << x.str();
    return out;
}

typedef pair<int, bign> ibign;

ibign p[23];

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        p[i].first = i + 1;
        cin >> p[i].second;
    }
    sort(p, p + n, [](ibign a, ibign b) { return a.second > b.second; });
    printf("%d\n", p[0].first);
    cout << p[0].second << endl;
    return 0;
}
