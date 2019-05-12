//http://citel.bjtu.edu.cn/vjudge/contest/view.action?cid=323#overview
#include<cmath>
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    string a, b;
    cin >> a >> b;
    int sum=0;
    for(int i=0;i<a.size();++i)
    {
        int x=a[i]-'0';
        int y=b[i]-'0';
        if(abs(x-y)>5) {
            sum += (10-abs(x-y));
        } else {
            sum += abs(x-y);
        }
    }
    printf("%d\n",sum);
    return 0;
}
