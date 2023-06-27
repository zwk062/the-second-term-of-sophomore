//
// Created by apple on 2023/4/21.
//
//导入c语言输入输出库
#include<stdio.h>
#include <limits.h>

int const M=7;
//给定p=(p0,p1,...pn),其中pi-1和pi分别为矩阵Ai的行数和列数
//s[i][j]中存储了Ai...Aj的最小乘法次数对应的分割点k
//m[i][j]中存储了Ai...Aj的最小乘法次数
//length表示矩阵链的长度

void MATRIX_CHAIN_ORDER(int *p,int Length,int m[][M],int s[][M])
{
    int q,n=Length-1;
    for(int i=1;i<=n;i++) m[i][i]=0; //对角线上的元素为0
    for(int l=2;l<=n;l++)
    {
        for(int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;
            m[i][j]=INT_MAX; //初始化为最大值
            for(int k=i;k<=j-1;k++)
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]; //计算Ai...Aj的最小乘法次数
                if(q<m[i][j])
                {
                    m[i][j]=q; //更新最小乘法次数
                    s[i][j]=k; //更新分割点
                }
            }
        }
    }
}
//给定前述过程MATRIX-CHAIN-ORDER输出的表s
//下列过程打印矩阵链的最优加括号方案
void PRINT_OPTIMAL_PARENS(int s[][M],int i,int j)
{
    if(i == j) printf("A%d",i);

    else
    {
        printf("(");
        PRINT_OPTIMAL_PARENS(s,i,s[i][j]); //递归调用
        PRINT_OPTIMAL_PARENS(s,s[i][j]+1,j);
        printf(")");
    }
}
int main()
{
    int p[M]={20,100,18,5,200,20,25};
    int m[M][M],s[M][M];
    MATRIX_CHAIN_ORDER(p,M,m,s);
    //输出矩阵m和s
    printf("\n");
    printf("m矩阵为：\n");
    for(int i=1;i<M;i++)
    {
        for(int j=1;j<M;j++)
        {
            if(i<=j)
            {
                printf("%5d\t",m[i][j]);
            }
            else
            {
                printf("%5s\t"," ");
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("s矩阵为：\n");
    for(int i=1;i<M-1;i++)
    {
        for(int j=2;j<M;j++)
        {
            if(i<j)
            {
                printf("%5d\t",s[i][j]);
            }
            else
            {
                printf("%5s\t"," ");
            }
        }
        printf("\n");
    }

    printf("最优加括号方案为：\n");
    PRINT_OPTIMAL_PARENS(s,1,6);
    return 0;
}

