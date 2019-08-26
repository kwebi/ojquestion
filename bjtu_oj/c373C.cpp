#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e6+5;
int dp[maxn];
int sum[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	while(cin>>q){
		int cnt=0;
		stack<int> lstk,rstk;
		while(q--){
			string s;
			cin>>s;
			if(s[0]=='I'){
				++cnt;
				int c;cin>>c;
				sum[cnt]=sum[cnt-1]+c;
				dp[cnt]=cnt==1?sum[1]:max(dp[cnt-1],sum[cnt]);
				lstk.push(c);
			}else if(s[0]=='Q'){
				int c;cin>>c;
				cout<<dp[c]<<'\n';
			}else if(s[0]=='L'){
				if(lstk.empty())continue;
				int t=lstk.top();lstk.pop();
				rstk.push(t);
				cnt--;
			}else if(s[0]=='R'){
				if(rstk.empty())continue;
				int t=rstk.top();rstk.pop();
				lstk.push(t);
				cnt++;
				sum[cnt]=sum[cnt-1]+t;
				dp[cnt]=cnt==1?sum[1]:max(dp[cnt-1],sum[cnt]);
			}else if(s[0]=='D'){
				lstk.pop();cnt--;
			}
		}
	}
	return 0;
}
