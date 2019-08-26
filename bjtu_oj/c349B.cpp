#include<bits/stdc++.h>
using namespace std;

long long a[10];
const int mod=1e9+7;

int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    a[1]=x;
    a[2]=y;
    a[1]=(a[1]+mod)%mod;
    a[2]=(a[2]+mod)%mod;
    int n;
    scanf("%d",&n);
    for(int i=3;i<=6;i++){
        a[i]=(a[i-1]-a[i-2]+mod)%mod;
    }
    int t;
    if((n%6)==0){
        t=6;
    }else {
        t=n%6;
    }
    cout <<a[t]<<endl;
	return 0;
}
