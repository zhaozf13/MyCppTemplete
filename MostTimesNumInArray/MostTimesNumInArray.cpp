// MostTimesNumInArray.cpp : 
// 给定一个数组a,长度为N,元素取值范围为[1, N]
// 统计各个元素出现的次数，要求时间复杂度为O(N),空间复杂度为O(1),可以改变原来的数组结构
// 解题思路：
// 1.从a[0]开始遍历，每遍历到一个元素，将a[i]-1记为index，作为下标值，令该下标对应的元素值为元素a[i]出现的次数
// 2.若下标index为负值，说明该元素已处理过，跳过
// 3.判断，若a[index]为正，则赋a[index]初值为-1；若为负，则a[index]--
// 4.最后数组中存储的元素即为统计次数，而该元素对应的下标即为元素值


#include <iostream>
#include <string>

#define N 4

using namespace std;

void PrintArr(int* arr)
{
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	//int* a = new int[2] {1, 1};
	int a[] = { 1,2,1,2 };
	int i = 0;

	while (i < N)
	{
		int index = a[i] - 1;
		if (index < 0)   //表示该元素已经处理过了,跳过
		{
			i++;
			continue;
		}
		else if (a[index] > 0)  //第一次处理一个值
		{
			a[i] = a[index]; //暂存新元素,意思就是先存下刚遍历到的元素，然后再循环下一次的时候再进行判断
			a[index] = -1;   //遇到新元素第一次，初值赋为-1
		}
		else
		{
			a[i] = 0;  //没有新的元素要处理，置0
			a[index]--; //重复元素，所以要--
		}
		PrintArr(a);
	}
	for (int j = 0; j < N; ++j)
	{
		cout << j + 1 << ", " << -a[j] << "\t";
	}
	cout << endl;
}

