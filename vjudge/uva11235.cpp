#include<stdio.h>
#include<vector>
using namespace std;

typedef pair<int,int> pii;



const int maxn=1e5+5;
int a[maxn];

pii sgtr[maxn<<2];

int main() {
    do {
        int n,q;
        scanf("%d",&n);
        if(n==0)break;
        scanf("%d",&q);
        int cnt=1;
        for(int i=1; i<=n; i++) {
            scanf("%d",&a[i]);
            pii[cnt].second=a[i];
            if(i!=1){
                if(a[cnt]==a[i]) pii[cnt].first++;
            }
        }
        for(int t=1;t<=q;t++) {
            int i,j;
            scanf("%d%d",&i,&j);

        }
    }while(1);
    return 0;
}
