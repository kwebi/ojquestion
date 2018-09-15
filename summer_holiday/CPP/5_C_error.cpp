//
// Created by 弱冠 on 2018/7/19.
//
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;

ll my_pow(int x,ll a) {
    ll res = 1;
    for (ll i=0;i<a;i++){
        res *= x;
    }
    return res;
}

ll my_log(int x, ll a) {
    ll i;
    for (i=0; i<a;i++) {
        if (my_pow(x, i) >= a) {
            break;
        }
    }
    return i;
}

int main() {
    long long x;
    scanf("%lld", &x);
    ll count = 0;
    ll max_a = my_log(3,x);
    ll max_b = my_log(5,x);
    ll max_c = my_log(7,x);
    for (ll i = 0; i < max_a+1; i++) {
        for (ll j =0;j< max_b+1;j++) {
            for (ll k=0;k<max_c+1;k++) {
                ll res = my_pow(3,i)*my_pow(5,j)*my_pow(7,k);
                if (res <= x && res != 1) {
                    count++;
                }
            }
        }
    }
    printf("%lld\n",count);
    return 0;
}