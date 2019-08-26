#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int main() {
	int k;
	scanf("%d",&k);
	string s;
	int t=k;
	int ti=1;
	char c='a';
	while(t>0) {
		s.push_back(c);
		while(t-ti>0) {
			s.push_back(c);
			t-=ti;
			ti++;
		}
		c++;
		if(t==1) {
			s.push_back(c);
			s.push_back(c);
			t--;
			break;
		}
		ti=1;
	}
	if(k==0){
		printf("a");return 0;
	}
	cout<<s<<endl;

	return 0;
}
