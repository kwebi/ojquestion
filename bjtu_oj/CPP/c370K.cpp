#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int a,b;

double F(double x) {
	return b*sqrt(1-x*x/(a*a))*2;
}

double simpson(double a,double b) {
	double c = a + (b-a)/2;
	return (F(a) + 4*F(c) + F(b))*(b-a)/6;
}

double asr(double a,double b,double eps,double A) {
	double c = a + (b-a)/2;
	double L = simpson(a,c), R = simpson(c,b);
	if(fabs(L + R - A) <= 15*eps)return L + R + (L + R - A)/15.0;
	return asr(a,c,eps/2,L) + asr(c,b,eps/2,R);
}

double asr(double a,double b,double eps) {
	return asr(a,b,eps,simpson(a,b));
}
const double eps=1e-6;

int main() {
	int n;
	cin>>n;
	while(n--) {
		cin>>a>>b;
		int l,r;
		cin>>l>>r;
		if(l*r<0)
			printf("%.3lf\n",asr(0,r,eps)+asr(0,-l,eps));
		else
			printf("%.3lf\n",asr(0,max(abs(l),abs(r)),eps)-asr(0,min(abs(l),abs(r)),eps));
	}
	return 0;
}


