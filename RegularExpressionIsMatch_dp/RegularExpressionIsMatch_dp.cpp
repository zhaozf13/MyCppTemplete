// RegularExpressionIsMatch_dp.cpp : 
// 请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
// 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配

#include <iostream>
#include <string.h>
#include <time.h>
#include <stdio.h>

using namespace std;

//递归法实现
bool match(char* str, char* pattern)
{
    if (*str == '\0' && *pattern == '\0') return true;
    if (*str != '\0' && *pattern == '\0') return false;
    if (*(pattern + 1) != '*') {
        //该字符匹配上则两个都向后移
        if (*str == *pattern || (*str != '\0' && *pattern == '.')) {
            return match(str + 1, pattern + 1);
        }
        else {//没匹配上返回错误
            return false;
        }
    }
    else {
        //匹配上了当前字符，且下一个是*，则可以选择跳过*匹配（即认为*前的字符数目为0），也可以str后移一位，不跳过*
        if (*str == *pattern || (*str != '\0' && *pattern == '.')) {
            return match(str, pattern + 2) || match(str + 1, pattern);
        }
        else {//没匹配上则只能选择跳过* 
            return match(str, pattern + 2);
        }
    }
}

bool isMatch(string s, string p) {
    int slen = s.length();
    int plen = p.length();
    if (slen == 0 && plen == 0) return true;
    if (slen != 0 && plen == 0) return false;
    char* schar = new char[slen + 1];
    strcpy(schar, s.c_str());
    char* pchar = new char[plen + 1];
    strcpy(pchar, p.c_str());
    return match(schar,pchar);
}

//dp法实现
bool isMatchDp(string s, string p) {
    int slen = s.length();
    int plen = p.length();
    if (slen == 0 && plen == 0) return true;
    if (slen != 0 && plen == 0) return false;
    bool** dp = new bool* [slen+1];
    for (int i = 0; i < slen+1; i++) {
        dp[i] = new bool[plen+1];
        memset(dp[i], 0, slen * sizeof(bool));
    }
    dp[0][0] = true;
    for (int i = 0; i < plen; i++) { 
        if (p[i] == '*' && dp[0][i - 1]) {
            dp[0][i + 1] = true; //为了防止第一个字符后就是*的情况，如aab和c*a*b，实际上能够匹配
        }
    }
    

    for (int i = 0; i < slen; i++) {
        for (int j = 0; j < plen; j++) {
            //对于能匹配上的情况
            if (p[j] == '.' || p[j] == s[i]) {
                dp[i + 1][j + 1] = dp[i][j];
            }
            //对于*字符分类讨论
            if (p[j] == '*') {
                if (p[j - 1] != s[i] && p[j - 1] != '.') {//如果和*前的元素不匹配，则跳过#*两个位置，所以是j-1
                    dp[i + 1][j + 1] = dp[i + 1][j - 1];
                }
                else {
                    dp[i+1][j+1] = (dp[i + 1][j] || dp[i][j + 1] || dp[i + 1][j - 1]);
                    /*
                      dp[i+1][j+1] = dp[i][j+1] //多个字符匹配情况，比如###和###b*是否匹配，一旦匹配，看s的末尾是否还有相同的字符###b和###b*的情况
                      dp[i+1][j+1] = dp[i+1][j] //单个字符匹配情况，比如###b和###b，即认为*前的字符只出现一次
                      dp[i+1][j+1] = dp[i+1][j-1] //没有匹配，即认为*前的字符出现0次
                      */
                }
            }
        }
    }
    bool res = dp[slen][plen];
    for (int i = 0; i < slen; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    return res;

}


int main()
{
    clock_t start, end;
    start = clock();
    string s = "aab";
    string p = "c*a*b";
    cout << isMatch(s, p) << endl;
    cout << isMatchDp(s, p) << endl;
    end = clock();
    printf("totile time=%f\n", (float)(end - start) * 1000 / CLOCKS_PER_SEC);
    return 0;
}


