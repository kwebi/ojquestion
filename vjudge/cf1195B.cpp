#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n,k;
    cin>>n>>k;
    double s=(n+k)*2ll+9/2.0;
    double s1=sqrt(s);
    ll t=s1-3/2.0;
    cout << n-t<<endl;
    return 0;
}
