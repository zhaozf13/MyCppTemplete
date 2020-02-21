// AddMinusMutiDivideByBit.cpp : 
// 用位运算实现加减乘除，但用户要保证给的数字不能超出范围

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

//加法
int addByBit(int a, int b) {
    int sum = a;
    while (b != 0) {
        sum = a ^ b;      //无进位相加
        b = (a & b) << 1; //进位结果
        a = sum;
    }
    return sum;
}

//取相反数,x=~x+1
int negNum(int n) {
    return addByBit(~n, 1);
}

//减法
int minusByBit(int a, int b) {
    return addByBit(a, negNum(b));
}

//乘法
int multiByBit(int a, int b) {
    int res = 0;
    unsigned int temp_unsign = b;
    while (temp_unsign != 0) {
        if ((temp_unsign & 1) != 0) {
            res = addByBit(res, a);
        }
        a <<= 1;
        temp_unsign >>= 1;  //这一步要无符号右移，即前面要补0，C++中没有无符号右移，所以要先转换成无符号数再右移
    }
    return res;
}

//判断是否是负数
bool isNeg(int n) {
    return n < 0;
}

//除法
int divByBit(int a, int b) {
    int x = isNeg(a) ? negNum(a) : a;
    int y = isNeg(b) ? negNum(b) : b;
    int res = 0;
    for (int i = 31; i > -1; i = minusByBit(i, 1)) {
        if ((x >> i) >= y) {    //x依次右移，当>=y时说明该位为1，然后要减去y，继续右移
            res |= (1 << i);
            x = minusByBit(x, y << i);
        }
    }
    return isNeg(a) ^ isNeg(b) ? negNum(res) : res;
}

int divideByBit(int a, int b) {
    try {
        if (b == 0) {
            throw "divisor is zero";
        }
        if (a == INT_MIN && b == INT_MIN) {
            return 1;
        }
        else if (b == INT_MIN) {
            return 0;
        }
        else if (a == INT_MIN) {
            int res = divByBit(addByBit(a, 1), b);
            return addByBit(res, divByBit(minusByBit(a, multiByBit(res, b)), b));
        }
        else {
            return divByBit(a, b);
        }
    }
    catch (char* e) {
        //cout << e << endl;
        printf("%s", e);
    }
   
}

int main()
{
    int a = INT_MIN;
    int b = 1;
    cout << addByBit(a, b) << endl;
    cout << minusByBit(a, b) << endl;
    cout << multiByBit(a, b) << endl;
    cout << divideByBit(a, b) << endl;
    //cout << a / b << endl;
    return 0;
}


