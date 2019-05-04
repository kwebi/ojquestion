#include <string>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

struct Stu
{
    string name;
    int fgrade; //期末成绩
    int cgrade; //班级成绩
    char cadre; //是否干部
    char west;  //是否西部学生
    int paper;  //论文数
    int money;  //奖金
    int order;  //出现顺序
};

int main()
{
    int n;
    scanf("%d", &n);
    Stu s[105];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].name >> s[i].fgrade >> s[i].cgrade >> s[i].cadre >> s[i].west >> s[i].paper;
        s[i].money = 0;
        s[i].order = i;
    }
    for (int i = 0; i < n; ++i)
    {
        if (s[i].fgrade > 90)
            s[i].money += 2000;
        if (s[i].fgrade > 85)
        {
            if (s[i].west == 'Y')
                s[i].money += 1000;
            if (s[i].cgrade > 80)
                s[i].money += 4000;
        }
        if (s[i].fgrade > 80 && s[i].paper >= 1)
            s[i].money += 8000;
        if (s[i].cgrade > 80 && s[i].cadre == 'Y')
            s[i].money += 850;
    }
    sort(s, s + n, [](Stu &a, Stu &b) { return a.money == b.money ? a.order < b.order : a.money > b.money; });
    long long sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += s[i].money;
    }
    cout << s[0].name << endl
         << s[0].money << endl
         << sum << endl;
    return 0;
}