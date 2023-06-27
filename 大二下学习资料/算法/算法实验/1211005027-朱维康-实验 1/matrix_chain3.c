//
// Created by apple on 2023/4/21.
//
//����c�������������
#include<stdio.h>
#include <limits.h>

int const M=7;
//����p=(p0,p1,...pn),����pi-1��pi�ֱ�Ϊ����Ai������������
//s[i][j]�д洢��Ai...Aj����С�˷�������Ӧ�ķָ��k
//m[i][j]�д洢��Ai...Aj����С�˷�����
//length��ʾ�������ĳ���

void MATRIX_CHAIN_ORDER(int *p,int Length,int m[][M],int s[][M])
{
    int q,n=Length-1;
    for(int i=1;i<=n;i++) m[i][i]=0; //�Խ����ϵ�Ԫ��Ϊ0
    for(int l=2;l<=n;l++)
    {
        for(int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;
            m[i][j]=INT_MAX; //��ʼ��Ϊ���ֵ
            for(int k=i;k<=j-1;k++)
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]; //����Ai...Aj����С�˷�����
                if(q<m[i][j])
                {
                    m[i][j]=q; //������С�˷�����
                    s[i][j]=k; //���·ָ��
                }
            }
        }
    }
}
//����ǰ������MATRIX-CHAIN-ORDER����ı�s
//���й��̴�ӡ�����������ż����ŷ���
void PRINT_OPTIMAL_PARENS(int s[][M],int i,int j)
{
    if(i == j) printf("A%d",i);

    else
    {
        printf("(");
        PRINT_OPTIMAL_PARENS(s,i,s[i][j]); //�ݹ����
        PRINT_OPTIMAL_PARENS(s,s[i][j]+1,j);
        printf(")");
    }
}
int main()
{
    int p[M]={20,100,18,5,200,20,25};
    int m[M][M],s[M][M];
    MATRIX_CHAIN_ORDER(p,M,m,s);
    //�������m��s
    printf("\n");
    printf("m����Ϊ��\n");
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
    printf("s����Ϊ��\n");
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

    printf("���ż����ŷ���Ϊ��\n");
    PRINT_OPTIMAL_PARENS(s,1,6);
    return 0;
}

