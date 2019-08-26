#include<algorithm>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;

const int N = 1005;
int book[N];

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &book[i]);
    }
    for (int i = 0; i < q; ++i)
    {
        vector<int> res;
        int len, reader;
        scanf("%d%d", &len, &reader);
        for (int i = 0; i < n; ++i)
        {
            int mod = int(pow(10, len));
            if (book[i] % mod==reader)
            {
                res.push_back(book[i]);
            }
        }
        if(res.empty())
            printf("-1\n");
        else{
            sort(res.begin(),res.end());
            printf("%d\n",res[0]);
        }
    }

    return 0;
}
