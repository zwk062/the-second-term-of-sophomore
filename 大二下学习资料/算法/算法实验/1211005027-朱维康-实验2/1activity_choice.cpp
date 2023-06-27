//
// Created by apple on 2023/5/7.
//
#include <iostream>
using namespace std;

//活动选择问题

// 迭代贪心算法
// s[]为开始时间，f[]为结束时间，A[]为结果数组，n为活动个数
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
// 将上面的函数封装为包含输出的函数。
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
// 递归贪心算法
// s[]为开始时间，f[]为结束时间，k为当前活动，n为活动个数
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

// 把上面的函数加入一个新的函数，使得输出的活动序列包含第一个活动
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

