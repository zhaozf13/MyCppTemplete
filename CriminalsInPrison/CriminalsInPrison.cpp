/* S 城现有两座监狱，一共关押着N 名罪犯，编号分别为1~N。他们之间的关系自然也极

不和谐。很多罪犯之间甚至积怨已久，如果客观条件具备则随时可能爆发冲突。我们用“怨

气值”（一个正整数值）来表示某两名罪犯之间的仇恨程度，怨气值越大，则这两名罪犯之

间的积怨越多。如果两名怨气值为c 的罪犯被关押在同一监狱，他们俩之间会发生摩擦，并

造成影响力为c 的冲突事件。

每年年末，警察局会将本年内监狱中的所有冲突事件按影响力从大到小排成一个列表，

然后上报到S 城Z 市长那里。公务繁忙的Z 市长只会去看列表中的第一个事件的影响力，

如果影响很坏，他就会考虑撤换警察局长。

在详细考察了N 名罪犯间的矛盾关系后，警察局长觉得压力巨大。他准备将罪犯们在

两座监狱内重新分配，以求产生的冲突事件影响力都较小，从而保住自己的乌纱帽。假设只

要处于同一监狱内的某两个罪犯间有仇恨，那么他们一定会在每年的某个时候发生摩擦。那

么，应如何分配罪犯，才能使Z 市长看到的那个冲突事件的影响力最小？这个最小值是少？
*/

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 20010;
const int maxm = 100100;

int p[maxn * 2];//作为并查集查找两个罪犯是否在同一集合，用到了i的影节点i+n
//定义节点结构体，保存两个罪犯名字和冲突值
struct node
{
    int a, b, v;
}s[maxm];

//定义比较器，按照从大到小排列
int compare(node x, node y) {
    return x.v > y.v;
}

//find函数，用于判断两个罪犯是否在同一集合
int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

int main()
{
    ios::sync_with_stdio(false);//取消cin，cout与stdio的同步
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> s[i].a >> s[i].b >> s[i].v;
    }
    //初始化p
    for (int i = 1; i < n * 2; i++) {
        p[i] = i;
    }
    //将冲突值从大到小排序
    sort(s + 1, s + 1 + m, compare);
    int ans = 0;
    int c, d;
    for (int i = 1; i <= m; i++) {
        c = find(s[i].a);
        d = find(s[i].b);
        if (c == d) {
            ans = s[i].v;
            break;
        }
        p[c] = find(s[i].b + n);
        p[d] = find(s[i].a + n);
    }
    cout << ans << endl;
    return 0;
}
