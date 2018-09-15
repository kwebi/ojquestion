//
// Created by 弱冠 on 2018/7/17.
//

#include <cstdio>
typedef struct node{
    int a;
    int b;
}Node;

int main() {
    freopen("../data.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        int array[9][9];
        int tmp[9][9]={0};
        for (int j=0;j<9;j++) {
            for (int k=0;k<9;k++) {
                scanf("%d",&array[j][k]);
            }
        }
        for (int j=0;j<9;j++) {
            for (int k=0;k<9;k++) {
                tmp[j][array[j][k]-1]=1;
            }
        }
        for (int j=0;j<9;j++) {
            for (int k=0;k<9;k++) {
                tmp[array[j][k]-1][k]=1;
            }
        }
        int flag = 1;
        for (int j=0;j<9;j++) {
            for (int k=0;k<9;k++) {
                if (tmp[j][k]==0) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0) {
                break;
            }
        }
        Node node1[10];
        for (int j=1;j<=9;j++) {
            if (j<=3) {
                node1[j].a=0;
                node1[j].b=j-1;
            }
            if (j<=6&& j>3) {
                node1[j].a=1;
                node1[j].b=(j-1)%3;
            }
            if (j<=9&&j>6) {
                node1[j].a=2;
                node1[j].b=(j-1)%3;
            }
        }
        int tmp1[9][9]={0};
        for (int j=0;j<9;j++) {
            for (int k=0;k<9;k++) {
                tmp1[(j/3)*3+node1[array[j][k]].a][(k/3)*3+node1[array[j][k]].b] = 1;
            }
        }
        for (int j=0;j<9;j++) {
            for (int k=0;k<9;k++) {
                if (tmp1[j][k]==0) {
                    flag =0;
                    break;
                }
            }
            if (flag == 0) {
                break;
            }
        }
        if (flag == 0) {
            printf("Wrong\n");
        } else{
            printf("Right\n");
        }
    }
    return 0;
}