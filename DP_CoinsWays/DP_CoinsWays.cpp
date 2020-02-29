// DP_CoinsWays.cpp : 
// 给定一个数组arr，每个元素表示货币的面值，每个面值张数不限，问给出一个aim，能凑出aim有多少种方法

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

//递归法
int process1(int* arr, int len, int index, int rest) {
    if (index == len) {
        return rest == 0 ? 1 : 0;
    }
    int ways = 0;
    for (int num_cash = 0; rest - arr[index] * num_cash >= 0; num_cash++) {
        ways += process1(arr, len, index + 1, rest - arr[index] * num_cash);
    }
    return ways;
}

int CoinsWay1(int* arr, int len, int aim) {
    if (arr == NULL || len == 0) {
        return 0;
    }
    return process1(arr, len, 0, aim);
}

//严格表结构
int CoinsWay2(int* arr, int len, int aim) {
    int** dp = new int*[len+1];
    for (int i = 0; i <= len; i++) {
        dp[i] = new int[aim + 1];
    }
    for (int i = 0; i <= len; i++) {
        for (int j = 0; j <= aim; j++) {
            dp[i][j] = 0;
        }
    }
    dp[len][0] = 1;
    int ways = 0;
    for (int index = len - 1; index >= 0; index--) {
        for (int rest = 0; rest <= aim; rest++) {
            ways = 0;
            for (int num_cash = 0; num_cash * arr[index] <= rest; num_cash++) {
                ways += dp[index + 1][rest - num_cash * arr[index]];
            }
            dp[index][rest] = ways;
        }
    }
    int result = dp[0][aim];
    for (int i = 0; i <= len; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    return result;

}

//严格表结构，用斜率优化法，优化dp[index][rest]可以由dp[index][rest-arr[index]]+dp[index+1][rest]获得
//优化法应通过观察来改进
int CoinsWay3(int* arr, int len, int aim) {
    int** dp = new int* [len + 1];
    for (int i = 0; i <= len; i++) {
        dp[i] = new int[aim + 1];
    }
    for (int i = 0; i <= len; i++) {
        for (int j = 0; j <= aim; j++) {
            dp[i][j] = 0;
        }
    }
    dp[len][0] = 1;
    int ways = 0;
    for (int index = len - 1; index >= 0; index--) {
        for (int rest = 0; rest <= aim; rest++) {
            dp[index][rest] = dp[index + 1][rest];
            if (rest - arr[index] >= 0) {
                dp[index][rest] += dp[index][rest - arr[index]];
            }
        }
    }
    int result = dp[0][aim];
    for (int i = 0; i <= len; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    return result;
}




//for test
int* generateRandomArr(int len, int max,int* p_arr_length) {
    *p_arr_length = ((int)rand() % len) + 1;
    //cout << *p_arr_length << endl;
    int* arr = new int[*p_arr_length];
    for (int i = 0; i < *p_arr_length; i++) {
        arr[i] = ((int)rand() % max) + 1;
    }
    return arr;
}


int main()
{
    int len = 10;
    int max = 10;
    int testTime = 10;
    srand((unsigned)time(NULL));
    for (int i = 0; i < testTime; i++) {
        //随机生成数组
        int arr_length = 0;
        int* p_arr_length = &arr_length;
        int* arr = generateRandomArr(len, max, p_arr_length);
        //cout << "arr_length" << arr_length << endl;
        //测试
        int aim = ((int)rand() % 10 * max) + max;
        int res1 = CoinsWay1(arr, arr_length, aim);
        int res2 = CoinsWay2(arr, arr_length, aim);
        int res3 = CoinsWay3(arr, arr_length, aim);
        if (res1 != res2||res2 != res3) {
            cout << "Oooops!" << endl;
            break;
        }
        int* arr = generateRandomArr(len, max, p_arr_length);
        delete[] arr;
    }

    cout << "Hooray!" << endl;
    return 0;
}


