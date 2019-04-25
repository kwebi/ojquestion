#include <stdio.h>

using namespace std;

int a[100005];

void swap(int arr[], int i, int j)
{
    int temp;

    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void qsort(int a[], int l, int r)
{
    int mid = a[(l + r) / 2]; //中间数
    int i = l, j = r;
    do
    {
        while (a[i] < mid)
            i++; //查找左半部分比中间数大的数
        while (a[j] > mid)
            j--;    //查找右半部分比中间数小的数
        if (i <= j) //如果有一组不满足排序条件（左小右大）的数
        {
            swap(a, i, j); //交换
            i++;
            j--;
        }
    } while (i <= j); //这里注意要有=
    if (l < j)
        qsort(a, l, j); //递归搜索左半部分
    if (i < r)
        qsort(a, i, r); //递归搜索右半部分
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    qsort(a, 0, n - 1);
    if (n > 0)
        printf("%d", a[0]);
    for (int i = 1; i < n; ++i)
        printf(" %d", a[i]);
    printf("\n");
    return 0;
}
