#include<stdio.h>
#include<math.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Po
{
	double x, y;
	double r;
};

Po a[10];
const double PI = 3.141592654;
vector<Po> vp;
bool vis[10];
double mx, my, mx1, my1;
int n;
double ans = 0;

double mabs(double md) {
	return md > 0 ? md : -md;
}
double mabs(int md) {
	return md > 0 ? md : -md;
}

double mdistance(Po p1, Po p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double marea(Po p) {
	double r = min(mabs(mx - p.x), mabs(mx1 - p.x));
	r = min(mabs(my - p.y),min(r, mabs(my1 - p.y)));

	for (long long i = 0; i < vp.size(); i++) {
		r = min(mdistance(p, vp[i]) - vp[i].r, r);
		if (r < 0) {
			r = 0;
			break;
		}
	}
	return r;
}


void dfs(double res) {
	ans = max(ans, res);
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			double r = marea(a[i]);
			double ma = PI * r * r;
			a[i].r = r;
			Po p = a[i];
			vis[i] = 1;
			vp.push_back(p);
			dfs(res + ma);
			vp.pop_back();
			vis[i] = 0;
		}
	}
}

int main() {
	scanf("%d", &n);
	scanf("%lf%lf%lf%lf", &mx, &my, &mx1, &my1);
	for (int i = 0; i < n; i++) {
		scanf("%lf%lf", &a[i].x, &a[i].y);
	}
	dfs(0);
	double t=abs(mx-mx1)*abs(my-my1);
	printf("%d\n",int(t-ans+0.5));
	return 0;
}
