//
// Created by apple on 2023/5/7.
//
#include <iostream>
using namespace std;

//�ѡ������

// ����̰���㷨
// s[]Ϊ��ʼʱ�䣬f[]Ϊ����ʱ�䣬A[]Ϊ������飬nΪ�����
void Iterative_GreedySelector(int s[], int f[], bool A[], int n)
{
    A[0] = true;
    int j = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] >= f[j])
        {
            A[i] = true;
            j = i;
        }
        else
        {
            A[i] = false;
        }
    }

}
// ������ĺ�����װΪ��������ĺ�����
void Iterative_GreedySelector2(int s[], int f[], int n)
{
    bool A[n];
    Iterative_GreedySelector(s, f, A, n);
    for (int i = 0; i < n; i++)
    {
        if(A[i])
        {
            printf("%d ", i+1);
        }

    }
    printf("\n");
}
// �ݹ�̰���㷨
// s[]Ϊ��ʼʱ�䣬f[]Ϊ����ʱ�䣬kΪ��ǰ���nΪ�����
void Recursive_ActivitySelector(int s[], int f[], int k, int n)
{
    int m = k + 1;
    while (m <= n && s[m] < f[k])
    {
        m++;
    }
    if (m <= n)
    {
        printf("%d ", m+1);
        Recursive_ActivitySelector(s, f, m, n);
    }

}

// ������ĺ�������һ���µĺ�����ʹ������Ļ���а�����һ���
void Recursive_ActivitySelector2(int s[], int f[], int k, int n)
{
    printf("%d ", k+1);
    Recursive_ActivitySelector(s, f, k, n);
}




int main()
{
    int const n = 10;
    int s[n] = {1 ,3 ,0 ,5, 3, 5 ,6 ,8 ,8 ,2};
    int f[n] = {4, 5, 6, 7, 9 ,9 ,10 ,11, 12, 13};
    Iterative_GreedySelector2(s, f, n);
    Recursive_ActivitySelector2(s, f, 0, n-1);


}

