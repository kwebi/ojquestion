#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;


int main(){
	int T;
    scanf("%d",&T);
    while(T--){
    	int b,p,f,h,c;
    	scanf("%d%d%d%d%d",&b,&p,&f,&h,&c);
    	b/=2;
    	int t1=min(p,b);
    	int t2=min(f,b);
    	int ans=0;
    	for(int i=0;i<=t1;i++){
    		ans=max(ans,h*i+c*min(f,b-i));
		}
		for(int i=0;i<=t2;i++){
			ans=max(ans,c*i+min(p,b-i));
		}
		printf("%d\n",ans);
	}
	return 0;
}


