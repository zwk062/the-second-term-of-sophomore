#include <iostream>
using namespace std;

//定义宏
#define N 5

// 子集合问题的回溯算法
void subset(int A[],int d,int B[],int i) {
   //求出数组B中元素的和
    int sum = 0;
    int sum1 = 0;
    for(int j = 0; j < i; j++) {
        sum += B[j];
    }
  //如果数组B中元素的和等于d，则输出数组B中的元素
    if(sum == d) {
        for(int j = 0; j < i; j++) {
            if(B[j] != 0)
            {
                cout << B[j] << " ";
            }
        }
        cout << endl;
        return;
    }
    //对A中剩余的元素求和
    for(int j = i; j < N; j++) {
        sum1 += A[j];
    }
    if(i >= N || sum + A[i] > d || sum + sum1 < d) {
        return;
    }
    //将B数组和A[i]元素组合成新的数组
    B[i] = A[i];
    subset(A,d,B,i+1);
    B[i] = 0;
    subset(A,d,B,i+1);
    
}
int main() {
    int A[N] = {2,2, 4, 5,6};
    int d = 10;
    int B[N] = {0};

    subset(A,d,B,0);

}
