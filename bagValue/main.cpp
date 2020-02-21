#include <iostream>

using namespace std;

//01背包问题1：有 N 件物品和一个容量为 V 的背包。第 i 件物品的体积是 C[i]，价值是 W[i]。
//求解将哪些物品装入背包可使价值总和最大。求出最大总价值
//物品只能被选中1次或0次，因此为01背包问题

int zeroOneBag1(int V, int* C, int* W, int n){
    int** Value;
    //动态创建二维数组
    Value = new int*[n+1];//这里是m
    for (int i = 0; i < n+1; ++i) {
        Value[i] = new int[V+1]();//这里是n
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

//01背包问题2:简化版本：考虑前 i 个问题的状态只会依赖于前 i - 1 个问题的状态，
//也就是 dp[i][...] 只会依赖于 dp[i - 1][...]，另外一点就是当前考虑的背包体积只会用到比其小的体积
//基于这些信息，我们状态数组的维度可以少开一维，但是遍历的方向上需要从后往前遍历，从而保证子问题需要用到的数据不被覆盖

int zeroOneBag2(int V, int* C, int* W, int n){
    int* Value2 = new int[V+1]();//new一个数组，后面加（）表示初始化为0，不加（）表示未初始化
    //背包为空时为0
    Value2[0] = 0;
    for(int i = 0; i < n; ++i){
        for(int j = V; j >= C[i]; --j){//--j是为了前面的不会累积到后面，意思是只能取一次
            Value2[j] = Value2[j]>=(Value2[j-C[i]]+W[i]) ? Value2[j] : (Value2[j-C[i]]+W[i]);
        }
    }
    int maxValue = Value2[V];
    return maxValue;
    delete[] Value2;
}

//完全背包问题3：物品可以被选多次或者 0 次，这类背包问题和 01 背包问题很类似
//略微的不同在于，在完全背包问题中，状态 dp[i][j] 依赖的是 dp[i - 1][j] 以及 dp[i][k] k < j
int completeBag3(int V, int* C, int* W, int n){
    int** Value;
    //动态创建二维数组
    Value = new int*[n+1];//这里是m
    for (int i = 0; i < n+1; ++i) {
        Value[i] = new int[V+1]();//这里是n
    }
    Value[0][0] = 0;
    for(int i=1; i <= n; ++i){
        for(int j=1; j <= V; ++j){
                //不取该物品
                Value[i][j] = Value[i-1][j];
                //取该物品，是在考虑过或取过该物品的基础上取
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

//完全背包问题4：简化版本
int completeBag4(int V, int* C, int* W, int n){
    int* Value2 = new int[V+1]();//new一个数组，后面加（）表示初始化为0，不加（）表示未初始化
    //背包为空时为0
    Value2[0] = 0;
    for(int i = 0; i < n; ++i){
        for(int j = C[i]; j <= V; ++j){//对比01背包问题，++j是为了能累积前面的结果，即可以多次取一个物品
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
