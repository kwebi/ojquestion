#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<cmath>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;

void print(vector<int>&sum) {
    for(int i=sum.size()-1; i>=0; --i) {
        cout << sum[i];
    }
    cout << endl;
}

int cmp(vector<int>&a,vector<int>&b) {
    if(a.size()>b.size()) {
        return 1;
    } else if(a.size()<b.size()) {
        return -1;
    } else {
        for(int i=a.size()-1; i>=0; --i) {
            if(a[i]>b[i]) {
                return 1;
            } else if(a[i]<b[i])
                return -1;
        }
    }
    return 0;
}

vector<int> add(const char* str,ll len1,ll len2) {
    vector<int> v;
    for(ll i=len1-1, j=len2-1; i>=0||j>=len1; --i,--j) {
        int n1=0,n2=0;
        if(i>=0)
            n1=str[i]-'0';
        if(j>=len1)
            n2=str[j]-'0';

        v.push_back(n1+n2);
    }
    int len=v.size();
    for(ll i=0; i<len; ++i) {
        if(v[i]>=10) {
            if(i==len-1) {
                v.push_back(1);
            } else {
                v[i+1]+=1;
            }
            v[i]-=10;
        }
    }

    return v;
}



int main() {
    int len;
    scanf("%d",&len);
    const int maxn=2e5+5;
    char str[maxn];
    scanf("%s",str);
    vector<int>sum;
    int mid=len/2;
    while(mid>0&&str[mid]=='0') mid--;
    if(mid!=0)
        sum=add(str,mid,len);
    mid=(len+1)/2;
    while(mid<=len-1&&str[mid]=='0') mid++;
    if(mid!=len) {
        vector<int> t=add(str,mid,len);
        if(sum.empty())
            sum=t;
        if(cmp(sum,t)==1)
            sum=t;
    }
    print(sum);
    return 0;
}
