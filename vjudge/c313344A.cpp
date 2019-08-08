#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int n;

bool check(int num,map<int,bool>& mp) {
    if(num<1e3)
        return false;
    if(num<1e4) {
        if(mp[0]==1)
            return false;
        mp[0]=1;
    }
    while(num!=0) {
        int t=num%10;
        if(mp[t])
            return false;
        mp[t]=1;
        num/=10;
    }
    return true;
}

int main() {
    int flag=0;
    while(true) {
        cin>>n;
        if(n==0)
            break;

        vector<pii> nm;
        for(int i=1234; i*n<1e5; i++) {
            map<int,bool> mp;

            if(check(i,mp)&&check(i*n,mp)) {
                nm.push_back({i*n,i});
            }
        }
        if(flag++)cout<<endl;

        if(nm.empty()) {
            printf("There are no solutions for %d.\n",n);
        }
        for(auto e:nm) {
            printf("%05d / %05d = %d\n",e.first,e.second,n);
        }

    }
    return 0;
}
