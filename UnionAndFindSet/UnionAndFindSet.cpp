// 实现并查集结构
// 1.使用数组形式进行存储，一个数组存储节点的最“头”节点，一个存储该节点下集合的元素个数
// 2.实现两个功能，合并和查找是否是同一集合功能，其中增加一个find函数用于将“路径扁平化”

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class UnionFind {
private:
    //parent记录节点的最“上”节点
    vector<int> parent;
    //rank记录该节点对应的集合里元素的个数
    vector<int> rank;
    //count表示集合的总数
    int count;
public:
    UnionFind(int count) {
        parent.resize(count);//构造parent内元素为count个
        rank.resize(count);
        this->count = count;
        for (int i = 0; i < count; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    ~UnionFind() {
        parent.clear();
        rank.clear();
    }

    //find函数进行路径压缩
    int find(int p) {
        //assert(p >= 0 && p < count);
        if (p != parent[p]) {
            parent[p] = find(parent[p]);
        }
        return parent[p];
    }

    //判断是否是一个集合
    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }

    //合并操作
    void unionElement(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot)
            return;
        if (rank[pRoot] < rank[qRoot]) {
            parent[pRoot] = qRoot;
            rank[qRoot] += rank[pRoot];
        }
        else {
            parent[qRoot] = pRoot;
            rank[pRoot] += rank[qRoot];
        }
        count--;
    }
    
    int cnt() {
        return count;
    }
};

int main()
{
    UnionFind test(5);
    test.unionElement(2, 3);
    test.unionElement(3, 4);
    cout << test.find(4);
    cout << test.cnt();
}
