#include <vector>
#include <stdio.h>
using namespace std;

const int MAXN = 5e5 + 5;

struct Node
{
    int num;
    int i;
    bool operator<(Node b)
    {
        return this->num < b.num;
    }
    bool operator<=(Node b)
    {
        return this->num <= b.num;
    }
    bool operator>(Node b)
    {
        return this->num > b.num;
    }
    bool operator==(Node b)
    {
        return this->num == b.num;
    }
    bool operator!=(Node b)
    {
        return this->num != b.num;
    }
    Node operator=(Node b)
    {
        this->num = b.num;
        this->i = b.i;
        return *this;
    }
};

Node a[MAXN];
Node tmpa[MAXN];

long long ans = 0;
void merge(Node a[], int left, int mid, int right, Node tmpa[]);
void sort(Node a[], int left, int right, Node tmpa[])
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        sort(a, left, mid, tmpa);
        sort(a, mid + 1, right, tmpa);
        merge(a, left, mid, right, tmpa);
    }
}

void merge(Node a[], int left, int mid, int right, Node tmpa[])
{
    int i = left;
    int j = mid + 1;
    int t = left;
    while (i <= mid && j <= right)
    {
        if (a[i] <= a[j])
        {
            tmpa[t] = a[i];
            ++i;
            ++t;
        }
        else if (a[i] > a[j])
        {
            tmpa[t] = a[j];
            ans += (mid - i + 1); //关键点
            ++j;
            ++t;
        }
    }
    while (i <= mid)
    {
        tmpa[t] = a[i];

        ++t;
        ++i;
    }
    while (j <= right)
    {
        tmpa[t] = a[j];
        ++t;
        ++j;
    }
    t = left;
    while (left <= right)
    {
        a[left] = tmpa[t];
        left++;
        t++;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i].num);
        a[i].i = i;
    }
    sort(a, 1, n, tmpa);
    printf("%lld\n", ans);
    return 0;
}
