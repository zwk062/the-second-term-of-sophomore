#include <iostream>
using namespace std;

//�����
#define N 5

// �Ӽ�������Ļ����㷨
void subset(int A[],int d,int B[],int i) {
   //�������B��Ԫ�صĺ�
    int sum = 0;
    int sum1 = 0;
    for(int j = 0; j < i; j++) {
        sum += B[j];
    }
  //�������B��Ԫ�صĺ͵���d�����������B�е�Ԫ��
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
    //��A��ʣ���Ԫ�����
    for(int j = i; j < N; j++) {
        sum1 += A[j];
    }
    if(i >= N || sum + A[i] > d || sum + sum1 < d) {
        return;
    }
    //��B�����A[i]Ԫ����ϳ��µ�����
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
