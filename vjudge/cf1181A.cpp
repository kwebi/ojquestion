#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

int main() {
    ll x,y,z;
    cin >>x>>y>>z;
    ll t1=x%z;
    ll t2=y%z;
    ll r1=x/z+y/z,r2=0;
    if(t1+t2>=z) {
        if(t1>=t2) {
            r2=z-t1;
            r1=(x+r2)/z+(y-r2)/z;
        } else {
            r2=z-t2;
            r1=(x-r2)/z+(y+r2)/z;
        }
    }
    cout << r1 <<' '<<r2<<endl;

    return 0;
}
