#include <iostream>
#include <vector>


using namespace std;

class BitMap
{
public:
	BitMap(size_t range)
	{
		//此时多开辟一个空间
		_bits.resize(range / 32 + 1);
		for (vector<int>::iterator it = _bits.begin(); it != _bits.end(); ++it) {
			cout << *it << ' ';
		}
		cout << endl;
	}
	//将x对应的值“描黑”相应的点
	void Set(size_t x)
	{
		int index = x / 32;//确定哪个数据（区间）
		int temp = x % 32;//确定哪个Bit位
		_bits[index] |= (1 << temp);//位操作即可
		for (vector<int>::iterator it = _bits.begin(); it != _bits.end(); ++it) {
			cout << *it << ' ';
		}
		cout << endl;
	}
	//将x对应的值“描白”相应的点
	void Reset(size_t x)
	{
		int index = x / 32;
		int temp = x % 32;
		_bits[index] &= ~(1 << temp);//取反
		for (vector<int>::iterator it = _bits.begin(); it != _bits.end(); ++it) {
			cout << *it << ' ';
		}
		cout << endl;
	}
	bool Test(size_t x)
	{
		int index = x / 32;
		int temp = x % 32;
		if (_bits[index] & (1 << temp))
			return 1;
		else
			return 0;
	}

private:
	vector<int> _bits;
};

void TestBitMap()
{
	BitMap bm(200);
	bm.Set(136);
	bm.Set(1);
	cout << bm.Test(136) << endl;
	bm.Reset(136);
	cout << bm.Test(136) << endl;
}

int main()
{
	TestBitMap();
	return 0;
}
