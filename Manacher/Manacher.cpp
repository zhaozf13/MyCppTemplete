// Manacher.cpp : 
// 1.求取字符串中的最大回文子串的长度
// 2.通过增加特殊字符的方式将原串扩充，例如加'#'，实际上特殊字符可任意选取
// 3.通过建立回文半径数组来加速回文子串长度的判定过程

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//为原字符串增加特殊字符，扩充后新字符串长度为2*n+1
string manacherStr(string& str, int len) {
    string newstr;
    int len_newstr = 2 * len + 1;
    int index = 0;
    for (int i = 0; i < len_newstr; i++) {
        newstr += (i & 1) == 0 ? '#' : str[index++];
    }
    return newstr;
}

//求取最大回文子串长度
int maxLcpsLength(string& str, int len) {
    string* s = &str;
    if (s == NULL || len == 0) {
        return 0;
    }
    string newstr = manacherStr(str, len);
    int len_newstr = newstr.length();
    //最大回文半径数组
    int* pArr = new int[len_newstr] {0};
    //C记录的是回文子串的中心对称轴的位置
    int C = -1;
    //R记录的是之前扩的所有位置中所达到的最右回文右边界
    int R = -1;
    //max_res记录最大的回文长度
    int max_res = INT_MIN;
    for (int i = 0; i < len_newstr; i++) {
        //R与i比较大小，当i超出R时，即pArr[i]首先为1，然后考虑往外扩
        //当i小于R时，比较i关于C的对称点i'即2*C-1，处的回文半径与i和R的距离，取最小值为一定满足的回文部分，再继续往外扩
        pArr[i] = R > i ? min(pArr[2 * C - i], R - i) : 1;
        while (i + pArr[i]<len_newstr && i - pArr[i]>-1) {//保证不越界
            if (newstr[i + pArr[i]] == newstr[i - pArr[i]]) {//比较往外扩的第一个字符，若相等则pArr[i]++
                //实际上这一步也考虑了三种小情况：
                //1. i'的回文范围在L...R内（i回文半径==i'回文半径）
                //2. i'的回文范围超出了L...R（i的回文半径为R-i)
                //3. i'的回文范围正好压线L（i的回文半径除了R-i，要继续比较后面的）
                //实际上，1和2两种情况这一步一定不会中，为了简化代码才统一写一个if语句
                pArr[i]++;
            }
            else {
                break;
            }
        }
        if (i + pArr[i] > R) {
            R = i + pArr[i];
            C = i;
        }
        max_res = max(max_res, pArr[i]);
    }
    //maxres是求得的加入特殊字符的最大回文半径，-1就是原字符串的最大回文直径
    return max_res - 1;
}


int main()
{
    string str = "dbcacbast";
    string new_str;
    int len = str.length();
    string s = manacherStr(str, len);
    cout << s << endl;
    int result = maxLcpsLength(str, len);
    cout << result << endl;
}

