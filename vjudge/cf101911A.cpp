#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int N=2e5+7;
int a[N];
unordered_map<int,int> pos;
set<int> Set;
int ans[N];

int main()
{
    int n,m,d;
    scanf("%d%d%d",&n,&m,&d);
    for(int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
        pos[a[i]]=i;
        Set.insert(a[i]);
    }
    int cnt=1;
    while(Set.size()) {
        set<int>::iterator it=Set.begin();
        do {
            int t=*(it);
            ans[pos[t]]=cnt;
            Set.erase(t);
            it=Set.lower_bound(t+1+d);
        } while(it!=Set.end());
        cnt++;
    }
    printf("%d\n",cnt-1);
    for(int i=1;i<=n;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}

