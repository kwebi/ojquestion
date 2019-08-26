#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

vector<int> vec;
map<int,bool> pool;
const int maxn=1e5+5;
int cc[maxn];
string s;
int n;

void judge(int i) {
	for(int j=0; j<i; j++) {
		bool f=1;
		for(int k=j; k<n; k+=i) {
			if(s[k]=='P') {
				f=0;
				break;
			}
		}
		if(f) {
			cc[i]=1;
			break;
		}
	}
}

int main() {
	
	cin>>s;
 	n=s.size();

	for(int i=1; i*i<=n; i++) {
		if(n%i==0) {
			judge(i);
			judge(n/i);
		}
	}
	int cnt=0;
	for(int k=1; k<n; k++) {
		cnt+=cc[__gcd(k,n)];
	}
	printf("%d",cnt);
	return 0;
}

