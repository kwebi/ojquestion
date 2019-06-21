#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

const int maxn=105;
int a[maxn];
int sum[maxn];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i]=a[i];
        sum[i]+=sum[i-1];
    }
    priority_queue<int> pque;
    for(int i=1;i<=n;i++){
        pque.push(a[i-1]);
        vector<int> tmp;
        int s=sum[i];
        int ans=0;
        while(s>m){
            int t=pque.top();
            pque.pop();
            tmp.push_back(t);
            s-=t;
            ans++;
        }
        for(int e:tmp) {
            pque.push(e);
        }
        printf("%d ",ans);
    }
    return 0;
}
