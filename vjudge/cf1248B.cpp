#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

template<class T>
T sq(const T& x){return x*x;}

const int N=1e5+7;
int a[N];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    ll h=0,w=0;
    for(int i=1,j=n;i<=j;i++,j--){
        if(i==j){
            w+=a[i];
            continue;
        }
        w+=a[j];
        h+=a[i];
    }
    printf("%lld",sq(h)+sq(w));
    return 0;
}

