//
// Created by 弱冠 on 2018/7/20.
//

#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;

ll foo(ll n) {
    if (n == 0) {
        return 1;
    }
    if (n ==1) {
        return 0;
    }
    if (n > 1) {
        return foo(n/2)*2 + foo(n%2);
    }
}
int main() {
    ll n;
    scanf("%lld",&n);
    ll res;
    res=foo(n);
    printf("%lld",res);
    return 0;
}