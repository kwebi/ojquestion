#include<bits/stdc++.h>
using namespace std;

int a[105];
int n;
int msum=0;
vector<int> ans;
bool vis[105];
bool flag=0;


int main() {

    cin >>n;

    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
        msum+=a[i];
    }
    ans.push_back(1);
    int _s=a[0];
    for(int i=1; i<n; i++) {
        if(a[i]*2<=a[0]) {
            if(_s<=msum/2) {
                ans.push_back(i+1);
                _s+=a[i];
            } else {
                flag=1;
                break;
            }
        }
    }
    if(!flag&&_s<=msum/2){
        printf("0\n");
    }
    else {
        cout << ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            printf("%d ",ans[i]);
        }
    }

    return 0;
}
