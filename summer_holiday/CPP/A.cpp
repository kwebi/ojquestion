//
// Created by 弱冠 on 2018/7/17.
//
#include <cstdio>
#include <cstring>

int main() {
    char str[1000];
    scanf("%s",str);
    int len=strlen(str)-1;
    int a0 = (int)('0');
    int a9 = (int)('9');
    int a = (int)('a');
    int z = (int)('z');
    int A = (int)('A');
    int Z=(int)('Z');
    int index[1000];
    int index_num[1000];
    char ch;
    int j=1;
    int i_n=0;
    int sum=0;
    int i_sum=0;
    for (int i=0;i<len;i++) {
        if (str[i] == '=') {
            index[0] = i;
        }
        if ((str[i] >= a&& str[i] <= z) ||(str[i] >= A&&str[i]<=Z)) {
            ch = str[i];
            index[j++]=i;
        }
        if (str[i]>=a0&&str[i]<=a9&&!(str[i+1] >= a&& str[i+1] <= z) ||(str[i+1] >= A&&str[i+1]<=Z)) {
            index_num[i_n++]=i;
        }
    }
    for (int k = 1; k<j;k++) {
        if (index[k] < index[0] && index[k] !=0){
            if (str[index[k]-1] == '-') {
                sum += -1;
            }
            else {
                sum += (int)(str[index[k]-1])-'0';
            }
        }
        else if (index[k] ==0 || index[k] == index[0]+1) {
            sum += index[k]>index[0]?-1:1;
        }
        else if (index[k]>index[0] && index[k] != index[0]+1) {
            if (str[index[k]-1] == '-') {
                sum -= -1;
            }
            else {
                sum -= (int)(str[index[k]-1])-'0';
            }
        }
    }
    for(int k=0;k<i_n;k++) {
        int num = str[k] - '0';
        if (index_num[k]<index[0]&&index_num[k]!=0) {
            if (str[index_num[k]-1] == '-') {
                i_sum += -1*num;
            }
            else {
                i_sum += num;
            }
        }
        else if (index_num[k] ==0 || index_num[k] == index[0]+1) {
            i_sum += index_num[k]>index[0]?-1*num:num;
        }
        else if (index_num[k]>index[0] && index_num[k] != index[0]+1) {
            if (str[index_num[k]-1] == '-') {
                i_sum -= -1*num;
            }
            else {
                i_sum -= num;
            }
        }
    }
    double res = (-1.000)*i_sum/sum;
    printf("%c=%.3lf\n",ch,res);
    return 0;
}

