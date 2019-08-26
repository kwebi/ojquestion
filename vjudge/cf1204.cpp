#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

char s[10000];

int main(){
	scanf("%s",s);
	int n=strlen(s);
	bool f=0;
	for(int i=1;i<n;i++){
		if(s[i]=='1'){
			f=1;break;
		}
	}
	int ans=0;
	for(int i=n-1;i>=0;i-=2){
		if(i==0&&!f)continue;
		ans++;
	}
	printf("%d",ans);
	return 0;
}


