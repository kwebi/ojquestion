#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

bool check(char c){
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
		return 1;
	}
	return 0;
}

int a[100100],cnt;

int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(check(s[i])){
			a[++cnt]=i;
		}
	}
	if(!check(s[0])&&cnt!=0){
		printf("0");return 0;
	}
	if(cnt==0){
		printf("1");
	}else if(cnt==1){
		printf("%d",s.size());
	}else {
		printf("%d",a[(cnt+1)/2+1]-a[(cnt+1)/2]);
	}
	return 0;
}
