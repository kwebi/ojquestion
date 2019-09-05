#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define LC(x) ((x) << 1)
#define RC(x) ((x) << 1 | 1)
const int N = 1e6 + 5;
int n, m;
string s[N];
vector<vector<bool>> b;
vector<vector<bool>> d;
bool flag = 0;
int cnt[N];

int main()
{
    cin >> n >> m;
    b.resize(n), d.resize(n);
    for (int i = 0; i < n; i++) {
        b[i].resize(m, false);
        d[i].resize(m, false);
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    b[0][0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') {
                if (i > 0 && b[i - 1][j] == 1)
                    b[i][j] = true;
                if (j > 0 && b[i][j - 1] == 1)
                    b[i][j] = true;
            }
        }
    }
    if(!b[n-1][m-1]){
        printf("0");return 0;
    }
    d[n-1][m-1]=true;
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(s[i][j]=='.'){
                if(i+1<n&&d[i+1][j]==1){
                    d[i][j]=1;
                }
                if(j+1<m&&d[i][j+1]==1){
                    d[i][j]=1;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(b[i][j]&&d[i][j])cnt[i+j]++;
        }
    }
    bool flag=0;
    for(int i=1;i<n-1+m-1;i++){
        if(cnt[i]==1){flag=1;break;}
    }
    if(flag)printf("1");
    else printf("2");
    return 0;
}
