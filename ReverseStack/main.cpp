#include <iostream>
#include <stack>

using namespace std;

//利用递归函数逆序一个栈
//1.首先实现一个函数获得栈底元素返回并移除
int getAndremoveLastElement(stack<int>& s){//注意要加&引用，才会让函数里改变stack后保留改变后的状态
    int result = s.top();
    s.pop();
    if(s.empty()){
        return result;//到栈底的时候不再压入而是直接返回
    }else{
        int last = getAndremoveLastElement(s);
        s.push(result);//不到栈底时需要压入
        return last;
    }
}
//2.实现逆序
void reverse(stack<int>& s){
    if(s.empty()){
        return;
    }
    int i = getAndremoveLastElement(s);
    reverse(s);
    s.push(i);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    reverse(s);
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
