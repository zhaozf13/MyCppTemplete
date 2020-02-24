// DP_MinCoins.cpp : 
// 题意：给定数组 arr，arr 中所有的值都为正数且不重复。每个值代表一种面值的货币。
// 每种面值的货币可以使用任意张，再给定一个整数 aim，代表要找的钱数，求组成 aim 的最少货币数。
// 动态规划的解法：
// 1.写出暴力递归的解法
// 2.记忆化搜索：new一个缓存数组，用于递归过程中的记录，不考虑依赖关系
// 3.严格表结构：new一个缓存数组，考虑依赖关系，完全抛开原题意，只需将递归改写就好

#include <iostream>
#include <algorithm>

using namespace std;

//1.递归法
int process1(int* arr, int len, int index, int rest) {
    if (rest < 0) {//无法凑出，返回-1
        return -1;
    }
    if (rest == 0) {//凑出了，不再需要硬币
        return 0;
    }
    //rest > 0 分为还有硬币和没有硬币的情况
    if (index == len) {
        return -1;
    }
    int case1 = process1(arr, len, index + 1, rest);                 //没选该硬币
    int case2Next = process1(arr, len, index + 1, rest - arr[index]);//选了该硬币的后续
    if (case1 == -1 && case2Next == -1) {
        return -1;
    }
    else {
        if (case1 == -1) {
            return case2Next + 1;
        }
        if (case2Next == -1) {
            return case1;
        }
        return min(case1, case2Next + 1);
    }
}

int MinCoins1(int* arr, int len, int aim) {
    return process1(arr, len, 0, aim);
}

//2.记忆化搜索
int process2(int* arr, int len, int index, int rest, int** dp) {
    if (rest < 0) {//无法凑出，返回-1
        return -1;
    }
    if (dp[index][rest] != -2) {
        return dp[index][rest];
    }
    if (rest == 0) {//凑出了，不再需要硬币
        dp[index][rest] = 0;
    }
    else if (index == len) {
        dp[index][rest] = -1;
    }
    else {
        int case1 = process2(arr, len, index + 1, rest,dp);                 //没选该硬币
        int case2Next = process2(arr, len, index + 1, rest - arr[index],dp);//选了该硬币的后续
        if (case1 == -1 && case2Next == -1) {
            dp[index][rest] = -1;
        }
        else {
            if (case1 == -1) {
                dp[index][rest] = case2Next + 1;
            }else if (case2Next == -1) {
                dp[index][rest] = case1;
            }
            else {
                dp[index][rest] = min(case1, case2Next + 1);
            }
        }
    }
    return dp[index][rest];
}

int MinCoins2(int* arr, int len, int aim) {
    int** dp = new int* [len + 1];
    for (int i = 0; i < len + 1; i++) {
        dp[i] = new int[aim + 1];
    }
    for (int i = 0; i < len + 1; i++) {
        for (int j = 0; j < aim + 1; j++) {
            dp[i][j] = -2;
        }
    }
    return process2(arr, len, 0, aim, dp);
    for (int i = 0; i < len + 1; i++) {
        delete[] dp[i];
    }
    delete dp;
}

//严格表结构
int MinCoins3(int* arr, int len, int aim) {
    int** dp = new int* [len + 1];
    for (int i = 0; i < len + 1; i++) {
        dp[i] = new int[aim + 1];
    }
    for (int i = 0; i < len + 1; i++) {
        for (int j = 0; j < aim + 1; j++) {
            dp[i][j] = -2;
        }
    }
    for (int index = 0; index < len + 1; index++) {
        dp[index][0] = 0;
    }
    for (int rest = 1; rest < aim + 1; rest++) {
        dp[len][rest] = -1;
    }
    for (int index = len - 1; index >= 0; index--) {
        for (int rest = 1; rest <= aim; rest++) {
            int case1 = dp[index+1][rest];                 //没选该硬币
            int case2Next = -1;//选了该硬币的后续
            if (rest - arr[index] >= 0) {
                case2Next = dp[index + 1][rest - arr[index]];
            }
            if (case1 == -1 && case2Next == -1) {
                dp[index][rest] = -1;
            }
            else {
                if (case1 == -1) {
                    dp[index][rest] = case2Next + 1;
                }
                else if (case2Next == -1) {
                    dp[index][rest] = case1;
                }
                else {
                    dp[index][rest] = min(case1, case2Next + 1);
                }
            }
        }
    }
    return dp[0][aim];
    for (int i = 0; i < len + 1; i++) {
        delete[] dp[i];
    }
    delete dp;
}


int main()
{
    int arr[4] = { 2,3,10,100 };
    int len = sizeof(arr) / sizeof(arr[0]);
    int aim = 5;
    int res1 = MinCoins1(arr, len, aim);
    int res2 = MinCoins2(arr, len, aim);
    int res3 = MinCoins3(arr, len, aim);
    cout << res1 << endl;
    cout << res2 << endl;
    cout << res3 << endl;
    if (res1 == res2 && res2 == res3) {
        cout << "Hooray!" << endl;
    }
    else {
        cout << "Ooops!" << endl;
    }
}

