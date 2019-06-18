#include<stdio.h>
#include<iostream>
using namespace std;

const int maxn=1e3+5;
char s[maxn][maxn];
int Up[maxn][maxn];
int Down[maxn][maxn];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        scanf("%s",s[i]+1);
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            Up[i][j]=1;
            if(s[i][j]==s[i-1][j])
                Up[i][j]=Up[i-1][j]+1;
        }
    }
    for(int i=n; i>=1; i--) {
        for(int j=1; j<=m; j++) {
            Down[i][j]=1;
            if(s[i][j]==s[i+1][j])
                Down[i][j]=Down[i+1][j]+1;
        }
    }
    long long ans=0;
    for(int i=2; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(Up[i][j]!=1)
                continue;
            int H=Up[i][j]+Down[i][j]-1;
            int uu=i-1;//旗子上面的部分
            int dd=i+H;//旗子下面的部分
            if(dd>n) continue;
            if(Up[uu][j]>=H&&Down[dd][j]>=H) {
                //计算宽度
                ans+=1;
                int c=1;
                int k;
                for(k=j+1; k<=m; k++) {
                    ++c;
                    if(s[i][k]==s[i][j]&&s[uu][k]==s[uu][j]&&s[dd][k]==s[dd][j]&&Up[i][k]==Up[i][j]&&Down[i][k]==Down[i][j]&&Up[uu][k]>=H&&Down[dd][k]>=H) {
                        ans+=c;
                    } else
                        break;
                }
                j=k-1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
