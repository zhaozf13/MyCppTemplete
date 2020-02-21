#include <iostream>
#include <string>

using namespace std;

//�ݹ鷽�������ŵ������
void func(int n, string from, string mid, string to){
    if(n == 1){
        cout << "Move from " << from << " to " << to <<endl;
    }else{
        func(n-1, from, to, mid);
        func(1, from, mid, to);
        func(n-1, mid, from, to);
    }
}

void hanoi(int n){
    if(n > 0){
        func(n, "left", "middle", "right");
    }
}


//�����������飬ֻ����1,2,3�ֱ�����������������ӣ�arr[i]��ʾ��i+1��Բ�̵�λ�ã����arr�����״̬�������ƶ��켣�е�״̬���򷵻��ǵڼ���
//�����ǣ��򷵻�-1
//1.�ݹ鷽�����
int process(int* arr, int i, int from, int mid, int to){
    if(i == -1){
        return 0;
    }
    if(arr[i] != from && arr[i] != to){//��i��Բ�̼Ȳ�����Ҳ�����ң������ܵ�
        return -1;
    }
    if(arr[i] == from){//��i��Բ���������ϣ�˵��hanoi�����б�ʾ�ĵ�һ����û��������꣬��Ҫ����1~i-1��Բ��
        process(arr, i-1, from, to, mid);//��Ϊ��һ����û���꣬��1~i-1Ҫ������
    }else{//��i��Բ���������ϣ�˵����һ�������꣬����2^��i-1)-1,�ڶ���Ҳ���꣬����1,ʣ�µĿ���1~i-1��Բ��
        int rest = process(arr, i-1, mid, from, to);//��Ϊ�ڶ��������ˣ���1~i-1���е���
        if(rest == -1){
            return -1;
        }
        return (1<<i) + rest;//1~iԲ�̴�������ҪS(i)=S(i-1)+1+S(i-1),S(1)+1==2,S(i)=2^i-1;
    }
}

int step1(int* arr, int length){
    if(arr==NULL || length==0){
        return -1;
    }
    return process(arr, length-1, 1, 2, 3);
}

//2.�ǵݹ鷽�����
int step2(int* arr, int length){
    if(arr == NULL || length==0){
        return -1;
    }
    int from = 1;
    int mid = 2;
    int to = 3;
    int i = length-1;
    int res = 0;
    int temp = 0;
    while(i >= 0){
        if(arr[i] != from && arr[i] != to){
            return -1;
        }
        if(arr[i] == to){
            res += 1<<i;
            temp = from;
            from = mid;
        }else{
            temp = to;
            to = mid;
        }
        mid = temp;
        i--;
    }
    return res;
}


int main()
{
    //hanoi(4);
    int arr[2] = {3,3};
    int length = sizeof(arr)/sizeof(arr[0]);
    int *prr = new int[2];
    prr[0] = 3;
    prr[1] = 3;
    cout << step1(arr, length) << endl;
    cout << step2(arr, length) << endl;
    delete[] prr;
    return 0;
}
