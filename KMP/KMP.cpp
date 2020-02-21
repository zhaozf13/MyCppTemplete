// KMP.cpp : KMP算法，求str2在str1中匹配的位置
// 包括两个函数：
// 1.主函数用于KMP
// 2.获取str2的nextarr数组，该数组的每个位置表示该处字符前面字符串的头尾最长匹配长度

#include <iostream>
#include <string>

using namespace std;

//获取nextArray数组的信息
int* getNextArray(string& m, int m_len) {
    int* next = new int[m_len];
    if (m_len == 1) {
        next[0] = -1;
        return next;
        delete[] next;
    }
    next[0] = -1;
    next[1] = 0;
    int i = 2;
    int cn = 0;
    while (i < m_len) {
        if (m[i - 1] == m[cn]) {
            next[i++] = ++cn;
        }
        else if (cn > 0) {
            cn = next[cn];
        }
        else {
            next[i++] = 0;
        }
    }
    return next;
    delete[] next;
}

//主函数
int getIndexof(string& s, string& m, int s_len, int m_len) {
    string *ptr1 = &s, *ptr2 = &m;
    if (ptr1 == NULL || ptr2 == NULL || m_len < 1 || s_len < m_len) {
        return -1;
    }
    int i1 = 0;
    int i2 = 0;
    int *next = getNextArray(m, m_len);
    while (i1 < s_len && i2 < m_len ) {
        if (s[i1] == m[i2]) {//能匹配上就同时++
            i1++;
            i2++;
        }
        else if (next[i2] == -1) {//i2跳到0了，即需要重新开始了
            i1++;
        }
        else {//往前跳的过程
            i2 = next[i2];
        }
    }
    return i2 == m_len ? i1 - i2 : -1;//匹配上了就是i2=len，没匹配上就是返回-1   
}



int main()
{
    /*
    用于匹配子串的问题
    string str1 = "aabstaabaabku";
    int len1 = str1.length();
    string str2 = "aabaab";
    int len2 = str2.length();
    int res = getIndexof(str1, str2, len1, len2);
    cout << res << endl;
    */

    //这部分测试是获得重复子串，但并不位于头也不位于尾，若存在则输出，若不存在则输出"Just a legend"（牛客算法提升班第二节第一题）
    string result = "Just a legend";
    while (1) {
        string str;
        cin >> str;
        string addstr;
        addstr = str + '#';
        int len = addstr.length();
        int* next = getNextArray(addstr, len);
        if (next[len - 1] == 0) {
            cout << result;
            break;
        }
        string substr;
        for (int i = 0; i < next[len - 1]; i++) {
            substr += str[i];
            str[i] = '#';
        }
        int sublen = substr.length();
        int index = getIndexof(str, substr, len-1, sublen);
        if (index == 0 || index == (len -1 - sublen)) {
            cout << result;
        }
        else {
            cout << substr;
        }
    }
}


