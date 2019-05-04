#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int a[1000] = {0}, b[1000] = {0}, c[1000] = {0}, d[1000] = {0}, n, s = 0;
//a存行
//b存列
//c存左下到右上的对角线（行+列的和相同）
//d存右下到左上的对角线（行-列的差相同）
//清零数组

void print()
{
    ++s;
    if (s <= 3)
    {
        for (int i = 1; i <= n; ++i)
            cout << a[i] << " ";
        cout << endl;
    }
}

void search(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (b[j] == 0 && c[i + j] == 0 && d[i - j + n] == 0)
        {
            a[i] = j;
            b[j] = 1;
            c[i + j] = 1;
            d[i - j + n] = 1;
            if (i == n)
                print();
            else
                search(i + 1);
            b[j] = 0;
            c[i + j] = 0;
            d[i - j + n] = 0;
        }
    }
}

int main()
{

    cin >> n;
    search(1);
    cout << s << endl;
    return 0;
}