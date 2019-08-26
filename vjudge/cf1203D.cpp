#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

bool check(string s,string t) {
	int cnt=0;
	for(int j=0; j<t.size(); j++) {
		int pre=0;
		for(int i=pre; i<s.size(); i++) {
			if(s[i]==t[j]) {
				cnt++;
				pre=i+1;break;
			}
		}
	}
	if(cnt==t.size())return 1;
	return 0;
}

int main() {
	string s,t;
	cin>>s>>t;
	int ans=0;
	for(int i=0;i<s.size();i++){
		for(int j=1;j+i<=s.size();j++){
			string tmp;
			if(i>0)tmp=s.substr(0,i);
			if(check(tmp+s.substr(i+j),t)){
				ans=max(ans,j);
			}
		}
	}
	printf("%d",ans);
	return 0;
}
