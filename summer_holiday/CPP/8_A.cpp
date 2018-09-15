//
// Created by 弱冠 on 2018/7/20.
//
#include <cstdio>
#include <stack>
#include <cmath>
using namespace std;
typedef long long ll;

ll foo(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else if (n > 1) {
        return foo(n-1) + foo(n-2);
    }
}
ll arr[100005];
int main() {
    int n;
    scanf("%d",&n);
    ll res = 0;
    arr[0] =0;
    arr[1] =1;
    for (int i=2;i<=n;i++) {
        arr[i] = arr[i-1]%(int)(1e9+7)+arr[i-2]%(int)(1e9+7);
    }
    printf("%lld\n",arr[n]%(int)(1e9+7));
    return 0;
}
