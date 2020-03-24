// StringPermutation.cpp : 
// 获取字符串的全排列
//思路：递归法，问题转换为先固定第一个字符，求剩余字符的排列；求剩余字符排列时跟原问题一样。
//(1) 遍历出所有可能出现在第一个位置的字符（即：依次将第一个字符同后面所有字符交换）；
//(2) 固定第一个字符，求后面字符的排列（即：在第1步的遍历过程中，插入递归进行实现）。
//需要注意的几点：
//(1) 先确定递归结束的条件，例如本题中可设begin == str.size() - 1;
//(2) 形如 aba 或 aa 等特殊测试用例的情况，vector在进行push_back时是不考虑重复情况的，需要自行控制，通过find函数来判定；
//(3) 输出的排列可能不是按字典顺序排列的，可能导致无法完全通过测试用例，考虑输出前排序，或者递归之后取消复位操作。
//参考代码如下：

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> Permutation(string str)
    {
        vector<string> result;
        if (str.empty()) return result;

        Permutation(str, result, 0);

        // 此时得到的result中排列并不是字典顺序，可以单独再排下序
        sort(result.begin(), result.end());

        return result;
    }

    void Permutation(string str, vector<string> &result, int begin)
    {
        if (begin == str.size() - 1) // 递归结束条件：索引已经指向str最后一个元素时
        {
            if (find(result.begin(), result.end(), str) == result.end())//没找到的意思
            {
                // 如果result中不存在str，才添加；避免aa和aa重复添加的情况
                result.push_back(str);
            }
        }
        else
        {
            // 第一次循环i与begin相等，相当于第一个位置自身交换，关键在于之后的循环，
            // 之后i != begin，则会交换两个不同位置上的字符，直到begin==str.size()-1，进行输出；
            for (int i = begin; i < str.size(); ++i)
            {
                swap(str[i], str[begin]);
                Permutation(str, result, begin + 1);
                swap(str[i], str[begin]); // 复位，用以恢复之前字符串顺序，达到第一位依次跟其他位交换的目的
            }
        }
    }

    void swap(char& fir, char& sec)
    {
        char temp = fir;
        fir = sec;
        sec = temp;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}


