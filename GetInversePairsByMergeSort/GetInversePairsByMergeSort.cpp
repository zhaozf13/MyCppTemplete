// GetInversePairsByMergeSort.cpp : 
// 获取一个数组中的逆序对数目
// 先把数组分隔成子数组，统计出子数组内部的逆序对的数目，然后在统计出两个相邻子数组之间的逆序对的数目。合并完两个已排序的子数组后，要更新数组。
// 详见：https://blog.csdn.net/SCS199411/article/details/92005290?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //主函数
    int InversePairs(vector<int> data) {
        int size = data.size();
        if (size < 2) {
            return 0;
        }
        vector<int> copy;
        for (int i = 0; i < size; i++) {
            copy.push_back(data[i]);
        }
        int result = getCount(data,copy, 0, size - 1);
        return result;

    }
    //计算逆序对函数
    int getCount(vector<int> &data, vector<int> &copy, int begin, int end) {
        if (begin == end)
            return 0;
        int length = (end - begin) / 2;
        //递归，归并排序，并计算逆序对数
        int leftCount = getCount(data,copy, begin, begin+length) % 1000000007;
        int rightCount = getCount(data,copy, begin+length+1, end) % 1000000007;
        //记录交叉的逆序对数
        int crossCount = 0;
        //i:前半部分的下标，j:后半部分下标，index:辅助数组的下标
        int i = begin+length, j = end, index = end;
        while (i >= begin&& j >= begin+length+1) {
            if (data[i] > data[j]) {
                copy[index--] = data[i--];
                crossCount += j - begin - length;
                if (crossCount >= 1000000007) {
                    crossCount %= 1000000007;
                }
            }
            //不存在交叉的逆序对，依次将较大的值放进辅助数组
            else {
                copy[index--] = data[j--];
            }
        }
        //以防止某一部分未遍历完
        while (i >= begin) {
            copy[index--] = data[i--];
        }
        while (j >= begin+length+1) {
            copy[index--] = data[j--];
        }
        //更新归并排序后的子数组
        for (int i = begin; i <= end; i++) {
            data[i] = copy[i];
        }
        return (leftCount + rightCount + crossCount) % 1000000007;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}


