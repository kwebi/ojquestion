#include <bits/stdc++.h>
using namespace std;

struct Num
{
	int n;
	char c;
}a[3];


vector<int> v[30];

int main(){
	cin>>a[0].n>>a[0].c>>a[1].n>>a[1].c>>a[2].n>>a[2].c;
	v[a[0].c-'a'].push_back(a[0].n);
	v[a[1].c-'a'].push_back(a[1].n);
	v[a[2].c-'a'].push_back(a[2].n);
	int ans1=2;
	int ans2=2;
	int ans3=2;
	for(int i=0;i<30;i++){
		if(!v[i].empty()){
			sort(v[i].begin(),v[i].end());
			for(int j=1;j<v[i].size();j++){
				if(v[i][j]-v[i][j-1]==1) ans1--;
				if(v[i][j]-v[i][j-1]==2) ans3=1;
				if(v[i][j]==v[i][j-1]) ans2--;
			}
		}
	}

	printf("%d\n", min(ans1,min(ans3,ans2)));
	return 0;
}