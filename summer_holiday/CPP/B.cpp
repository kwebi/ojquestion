//
// Created by 弱冠 on 2018/7/17.
//

//
#include<bits/stdc++.h>
using namespace std;
int main(){
    double p,q;
    cin>>p>>q;
    p/=100;
    q/=100;
    for(int i=1;i;i++){
        if(int(i * q-0.000001) - int(i * p+0.000001) >= 1){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}