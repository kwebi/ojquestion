#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int a[1010],b[1010];
int cnt[1010];

pii ans[1010];
int tol=0;
int vis[1010];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++){
        scanf("%d%d",&a[i],&b[i]);
        if(!(a[i]==n||b[i]==n)){
            printf("NO\n");return 0;
        }
        if(a[i]!=n)cnt[a[i]]++;
        else cnt[b[i]]++;
    }
    for(int i=1;i<n;i++){
        if(cnt[i]==1){
            ans[tol++]=pii(i,n);
            cnt[i]--;
            vis[i]=1;
        }
    }
    for(int i=1;i<n;i++){
        int now=i;
        while(cnt[i]>0){
            if(i==now)vis[i]=1;
            int j=now;
            if(cnt[i]==1){
                ans[tol++]=pii(j,n);
                cnt[i]--;
                continue;
            }
            //printf("j:%d\n",j);
            while(j>0&&vis[j])j--;
            if(j<=0||vis[j]){
                printf("NO\n");return 0;
            }
            vis[j]++;
            ans[tol++]=pii(j,now);
            //printf("%d %d\n",j,now);
            now=j;
            cnt[i]--;
        }
    }
    printf("YES\n");
    for(int i=0;i<tol;i++){
        printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return 0;
}

