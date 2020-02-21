#include <iostream>

using namespace std;

//01��������1���� N ����Ʒ��һ������Ϊ V �ı������� i ����Ʒ������� C[i]����ֵ�� W[i]��
//��⽫��Щ��Ʒװ�뱳����ʹ��ֵ�ܺ�����������ܼ�ֵ
//��Ʒֻ�ܱ�ѡ��1�λ�0�Σ����Ϊ01��������

int zeroOneBag1(int V, int* C, int* W, int n){
    int** Value;
    //��̬������ά����
    Value = new int*[n+1];//������m
    for (int i = 0; i < n+1; ++i) {
        Value[i] = new int[V+1]();//������n
    }
    Value[0][0] = 0;
    for(int i=1; i <= n; ++i){
        for(int j=1; j <= V; ++j){
                Value[i][j] = Value[i-1][j];
                if((C[i-1] <= j) && (Value[i][j]<(Value[i-1][j-C[i-1]]+W[i-1]))){
                    Value[i][j] = Value[i-1][j-C[i-1]]+W[i-1];
                }
        }
    }
    int maxValue = Value[n][V];
    return maxValue;
    for (int i = 0; i < n; ++i)
    {
        delete[] Value[i];
    }
    delete[] Value;
}

//01��������2:�򻯰汾������ǰ i �������״ֻ̬��������ǰ i - 1 �������״̬��
//Ҳ���� dp[i][...] ֻ�������� dp[i - 1][...]������һ����ǵ�ǰ���ǵı������ֻ���õ�����С�����
//������Щ��Ϣ������״̬�����ά�ȿ����ٿ�һά�����Ǳ����ķ�������Ҫ�Ӻ���ǰ�������Ӷ���֤��������Ҫ�õ������ݲ�������

int zeroOneBag2(int V, int* C, int* W, int n){
    int* Value2 = new int[V+1]();//newһ�����飬����ӣ�����ʾ��ʼ��Ϊ0�����ӣ�����ʾδ��ʼ��
    //����Ϊ��ʱΪ0
    Value2[0] = 0;
    for(int i = 0; i < n; ++i){
        for(int j = V; j >= C[i]; --j){//--j��Ϊ��ǰ��Ĳ����ۻ������棬��˼��ֻ��ȡһ��
            Value2[j] = Value2[j]>=(Value2[j-C[i]]+W[i]) ? Value2[j] : (Value2[j-C[i]]+W[i]);
        }
    }
    int maxValue = Value2[V];
    return maxValue;
    delete[] Value2;
}

//��ȫ��������3����Ʒ���Ա�ѡ��λ��� 0 �Σ����౳������� 01 �������������
//��΢�Ĳ�ͬ���ڣ�����ȫ���������У�״̬ dp[i][j] �������� dp[i - 1][j] �Լ� dp[i][k] k < j
int completeBag3(int V, int* C, int* W, int n){
    int** Value;
    //��̬������ά����
    Value = new int*[n+1];//������m
    for (int i = 0; i < n+1; ++i) {
        Value[i] = new int[V+1]();//������n
    }
    Value[0][0] = 0;
    for(int i=1; i <= n; ++i){
        for(int j=1; j <= V; ++j){
                //��ȡ����Ʒ
                Value[i][j] = Value[i-1][j];
                //ȡ����Ʒ�����ڿ��ǹ���ȡ������Ʒ�Ļ�����ȡ
                if((C[i-1] <= j) && (Value[i][j]<(Value[i-1][j-C[i-1]]+W[i-1]))){
                    Value[i][j] = Value[i][j-C[i-1]]+W[i-1];
                }
        }
    }
    int maxValue = Value[n][V];
    return maxValue;
    for (int i = 0; i < n; ++i)
    {
        delete[] Value[i];
    }
    delete[] Value;
}

//��ȫ��������4���򻯰汾
int completeBag4(int V, int* C, int* W, int n){
    int* Value2 = new int[V+1]();//newһ�����飬����ӣ�����ʾ��ʼ��Ϊ0�����ӣ�����ʾδ��ʼ��
    //����Ϊ��ʱΪ0
    Value2[0] = 0;
    for(int i = 0; i < n; ++i){
        for(int j = C[i]; j <= V; ++j){//�Ա�01�������⣬++j��Ϊ�����ۻ�ǰ��Ľ���������Զ��ȡһ����Ʒ
            Value2[j] = Value2[j]>=(Value2[j-C[i]]+W[i]) ? Value2[j] : (Value2[j-C[i]]+W[i]);
        }
    }
    int maxValue = Value2[V];
    return maxValue;
    delete[] Value2;
}

int main()
{
    int n = 4;
    int V = 10;
    int C[4] = {2,3,5,7};
    int W[4] = {2,5,2,5};
    int maxValue1 = zeroOneBag1(V, C, W, n);
    cout << maxValue1 << endl;
    int maxValue2 = zeroOneBag2(V, C, W, n);
    cout << maxValue2 << endl;
    int maxValue3 = completeBag3(V, C, W, n);
    cout << maxValue3 << endl;
    int maxValue4 = completeBag4(V, C, W, n);
    cout << maxValue4 << endl;
    return 0;
}
