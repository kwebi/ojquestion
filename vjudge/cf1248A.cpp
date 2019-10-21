#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

template <class T>
T sq(const T& x) { return x * x; }

const int N = 1e5 + 7;
int p[N];
int q[N];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        ll t1=0,t2=0,t3=0,t4=0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &p[i]);
            if(p[i]%2==0){
                t2++;
            }else t1++;
        }
        int m;
        scanf("%d", &m);
        for (int i = 1; i <= m; i++){
            scanf("%d", &q[i]);
            if(q[i]%2==0){
                t4++;
            }else t3++;
        }
        printf("%lld\n",1LL*t1*t3+1LL*t2*t4);
    }
    return 0;
}
