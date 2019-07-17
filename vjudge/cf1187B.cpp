#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 2e5 + 5;
const int maxm = 5e4 + 5;

char str[maxn];
char ts[maxn];
vector<int> V[30];



int main()
{
	int n;
	scanf("%d", &n);
	scanf("%s", str);

	for (int j = 0; j < n; j++) {
		V[str[j] - 'a'].push_back(j);
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%s", ts);
		int tn = strlen(ts);
		map<char, int> mp;
		for (int j = 0; j < tn; j++) {
			mp[ts[j]]++;
		}
		int ans = 0;
		for (auto e : mp) {
			int t=V[e.first - 'a'][e.second - 1];
			ans = max(t+1, ans);

		}
		printf("%d\n", ans);
	}
	return 0;
}
