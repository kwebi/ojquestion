#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N=2e4+7;
int a[N];

int main(){
    int n;
    scanf("%d",&n);
    int u=0,d=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]%2==0)printf("%d\n",a[i]/2);
        else {
            if(u>=d){
                printf("%d\n",int(floor(a[i]/2.0)));
                d++;
            }else {
                printf("%d\n",int(ceil(a[i]/2.0)));
                u++;
            }
        }
    }
    return 0;
}

