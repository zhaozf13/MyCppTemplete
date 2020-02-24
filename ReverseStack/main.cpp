#include <iostream>
#include <stack>

using namespace std;

//���õݹ麯������һ��ջ
//1.����ʵ��һ���������ջ��Ԫ�ط��ز��Ƴ�
int getAndremoveLastElement(stack<int>& s){//ע��Ҫ��&���ã��Ż��ú�����ı�stack�����ı���״̬
    int result = s.top();
    s.pop();
    if(s.empty()){
        return result;//��ջ�׵�ʱ����ѹ�����ֱ�ӷ���
    }else{
        int last = getAndremoveLastElement(s);
        s.push(result);//����ջ��ʱ��Ҫѹ��
        return last;
    }
}
//2.ʵ������
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
