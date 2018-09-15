//
// Created by 弱冠 on 2018/7/20.
//
#include <cstdio>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll arr[1000005]={0};



ll foo(ll n) {
    if (n == 0) {
        return 1;
    }
    else if(n <0) {
        return 0;
    }
    else if (arr[n] >0) {
        return arr[n]%(int)(1e9+7);
    }
    else {
        arr[n] = (foo(n-1)+foo(n-2)+foo(n-3))%(int)(1e9+7);
        return arr[n]%(int)(1e9+7);
    }
}

int main()
{

    scanf("%lld",&n);
    ll res = foo(n);
    printf("%lld",res);
    return 0;
}
