// GetMedian.cpp : 
// 获得数据流中的中位数
// 主要思想：维持一个大根堆（左半部分）和一个小根堆（右半部分），当为偶数时，中位数为大根堆堆顶和小根堆堆顶的平均值；当为奇数时，中位数为小根堆堆顶

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solution {
private:
    vector<int> max;//左半部分维持大根堆
    vector<int> min;//右半部分维持小根堆
public:
    void Insert(int num) {
        if (((max.size() + min.size()) & 1) == 0) {
            //此时总数为偶数，原计划加入到小根堆上，但要保证大根堆堆顶要小于小根堆堆顶
            if (max.size() > 0 && num < max[0]) {
                //先添加到大根堆
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<int>());

                //把大根堆最大值移动到小根堆里去
                num = max[0];
                pop_heap(max.begin(), max.end(), less<int>());//这个函数将最大值放到了末尾
                max.pop_back();

                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<int>());
            }
            else {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<int>());
            }
        }
        else {
            //总数为奇数，所以直接放到大根堆上，但要考虑是否大于小根堆堆顶
            if (min.size() > 0 && num > min[0]) {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<int>());

                num = min[0];
                pop_heap(min.begin(), min.end(), greater<int>());
                min.pop_back();

                max.push_back(num);
                push_heap(max.begin(), max.end(), less<int>());
            }
            else {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<int>());
            }
        }
    }

    double GetMedian() {
        double median = 0.0;
        if ((max.size() + min.size()) == 0) {
            return 0;
        }
        if (((max.size() + min.size()) & 1) == 0) {
            median = ((double)max[0] + (double)min[0]) / 2;
        }
        else {
            median = min[0];
        }
        return median;
    }
};

int main()
{
    solution sol;
    sol.Insert(1);
    sol.Insert(3);
    sol.Insert(6);
    sol.Insert(4);
    sol.Insert(9);
    printf("%f\n", sol.GetMedian());
}

