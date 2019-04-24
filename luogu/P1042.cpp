#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
char a;
int s11a, s21a, s11b, s21b, f21[1000000][2], j; //s11a记录11时w的得分,s11b记录11时l的得分
                                                 //s21a记录21时w的得分，s21b记录21时的l的得分
int main()
{
    while (cin >> a && a != 'E') //输入因为要a=E时才停止
    {
        if (a == 'W') //若为w，s11a++，s21a++
        {
            s11a++; //计数
            s21a++;
        }
        if (a == 'L') //若为l，s21a++，s21b++
        {
            s21b++; //计数
            s11b++;
        }
        //判断是11还是21
        //注意要大于等于11（21），且比对手多2分以上才赢（乒乓球比赛规则）
        if ((s11a >= 11 && s11a - s11b >= 2) || (s11b >= 11 && s11b - s11a >= 2))
        {
            printf("%d:%d\n", s11a, s11b);
            s11a = 0;
            s11b = 0;
        };
        //21的先存起来，f21[J][0]表示第j场w的得分，f21[j][1]表示第j场l的得分
        if ((s21a >= 21 && s21a - s21b >= 2) || (s21b >= 21 && s21b - s21a >= 2))
        {
            f21[j][0] = s21a;
            f21[j][1] = s21b;
            s21a = 0;
            s21b = 0;
            j++;
        };
    }
    printf("%d:%d\n\n", s11a, s11b); //最后一组要出来输出
    for (int i = 0; i < j; i++)
        printf("%d:%d\n", f21[i][0], f21[i][1]); //输出
    printf("%d:%d", s21a, s21b);                 //同理最后一组也要格外输出，循环内不会输出
    return 0;
}
