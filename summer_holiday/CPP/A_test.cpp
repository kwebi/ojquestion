//
// Created by 弱冠 on 2018/7/17.
//

#include <stdio.h>
#define M 200
int main(void)
{
    char equation[M]; //接收一元一次方程
    int i=0; //用于遍历字符数组
    int type=1; //用于判断数据类型，是纯数字还是字母的数量
    int ntmp=0; //用于接收当前某类型的总和
    int ntype = 1; //判断是+还是-
    int sAlphabet=0,sNum=0; //字母的总和和数字的总和
    char stmp,alpha;//接受每一位的字符,接收未知数
    int local=1; //判断字符的遍历位于等号的左边还是右边
    double result=0;
    scanf("%s",equation);
    while((stmp = equation[i++])!='\0')
    {
        if(stmp>='0'&&stmp<='9')
        {
            ntmp = ntmp*10+(stmp-'0');
        }
        else if(stmp>='a'&&stmp<='z')
        {
            type = 0;
            alpha = stmp;
            if(ntmp==0)
            {
                ntmp=1;
            }
        }
        else if(stmp=='+'||stmp=='-')
        {
            if(type)
            {
                sNum+=(ntmp*ntype*local);
            }
            else
            {
                sAlphabet+=(ntmp*ntype*local);
            }
            type = 1;
            ntmp=0;
            ntype = (stmp=='+'?1:-1);
        }
        else if(stmp=='=')
        {
            if(type)
            {
                sNum+=(ntmp*ntype*local);
            }
            else
            {
                sAlphabet+=(ntmp*ntype*local);
            }
            type = 1;
            ntmp=0;
            ntype = 1;
            local = -1;
        }
    }
    if(type)
    {
        sNum+=(ntmp*ntype*local);
    }
    else
    {
        sAlphabet+=(ntmp*ntype*local);
    }
    result = -(double)sNum/(double)sAlphabet;
    printf("%c=%-.3lf\n",alpha,result);
    return 0;
}