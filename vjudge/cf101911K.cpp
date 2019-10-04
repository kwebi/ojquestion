#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N=5e3+7;
int a[N];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int cnt=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]>=m){
            cnt++;
        }
    }
    printf("%d\n",max(cnt-(n-cnt),0));

    return 0;
}

