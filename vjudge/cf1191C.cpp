#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxm = 1e5 + 5;
ll p[maxm];

int main()
{
	ll n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		scanf("%lld", &p[i]);
	}
	sort(p, p + m);
	ll x = k;
	ll t = 0;
	ll ans = 1;
	for (int i = 0; i < m;) {
		if (p[i] <= x) {
			t++;
			i++;
		}
		else {
			if (t == 0) {
				ll y = ceil((p[i] - x) * 1.0 / k);
				x += k * y;
				continue;
			}
			x += t;
			t = 0;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}