//
// Created by 弱冠 on 2018/7/5.
//
#include <cstdio>
void f( long int x, char *p );

int main()
{
    long int x;
    char s[10000] = "";

    scanf("%ld", &x);
    f(x, s);
    printf("%s\n", s);

    return 0;

}

void f(long int x, char *s) {
    if (x < 0) {
        s[0] = '-';
    }
    int i, j;
    char c;
    for (i = (x < 0 ? 0 : -1); x > 0;) {
        s[++i] = (char)(x % 16);
        x /= 16;
    }
    for (j = i; j >= 0; j--) {
        if (s[j] < 10) {
            s[j] += 48;
        }
        else {
            s[j] += 55;
        }
    }
    s[i+1] = '\0';
    for(j=0;j<i;j++,i--) {
        c=s[j];
        s[j]=s[i];
        s[i]=c;
    }
}
