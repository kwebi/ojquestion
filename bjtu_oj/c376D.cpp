#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

set<int> sw;
set<int> sh;
multiset<int> ssw,ssh;

int main(){
	int w,h,n;
	scanf("%d%d%d",&w,&h,&n);
	sw.insert(w);
	sw.insert(0);
	sh.insert(h);
	sh.insert(0);
	ssw.insert(w);
	ssh.insert(h);
	char s[5];
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		int b;
		scanf("%d",&b);
		char c=s[0];
		if(c=='H'){
			sh.insert(b);
			auto l=sh.find(b);
			auto r=sh.find(b);
			l--,r++;
			ssh.erase(ssh.find(*r-*l));
			ssh.insert(b-*l);
			ssh.insert(*r-b);
		}else {
			sw.insert(b);
			auto l=sw.find(b);
			auto r=sw.find(b);
			l--,r++;
			ssw.erase(ssw.find(*r-*l));
			ssw.insert(b-*l);
			ssw.insert(*r-b);
		}
		printf("%I64d\n",1LL*(*ssh.rbegin())*(*ssw.rbegin()));
	}
	return 0;
}


