#include <iostream>
#include <string>

using namespace std;

//递归方法解决汉诺塔问题
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


//给定整数数组，只含有1,2,3分别代表左中右三个柱子，arr[i]表示第i+1个圆盘的位置，如果arr代表的状态是最优移动轨迹中的状态，则返回是第几步
//若不是，则返回-1
//1.递归方法解决
int process(int* arr, int i, int from, int mid, int to){
    if(i == -1){
        return 0;
    }
    if(arr[i] != from && arr[i] != to){//第i个圆盘既不在左也不在右，不可能的
        return -1;
    }
    if(arr[i] == from){//第i个圆盘在左柱上，说明hanoi函数中表示的第一步还没走完或走完，需要考察1~i-1个圆盘
        process(arr, i-1, from, to, mid);//因为第一步还没走完，即1~i-1要从左到中
    }else{//第i个圆盘在右柱上，说明第一步已走完，走了2^（i-1)-1,第二步也走完，走了1,剩下的考虑1~i-1个圆盘
        int rest = process(arr, i-1, mid, from, to);//因为第二步走完了，即1~i-1从中到右
        if(rest == -1){
            return -1;
        }
        return (1<<i) + rest;//1~i圆盘从左到右需要S(i)=S(i-1)+1+S(i-1),S(1)+1==2,S(i)=2^i-1;
    }
}

int step1(int* arr, int length){
    if(arr==NULL || length==0){
        return -1;
    }
    return process(arr, length-1, 1, 2, 3);
}

//2.非递归方法解决
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
