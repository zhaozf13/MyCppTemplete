#include <iostream>
#include<stdlib.h>
#include<time.h>

#define random(x) (rand()%x)

using namespace std;

void my_swap(int* a, int i, int j){
    int cur = a[i];
    a[i] = a[j];
    a[j] = cur;
}

int* partition(int* a, int left, int right){
    int less = left - 1;
    int more = right;
    while(left < more){
        if(a[left] < a[right]){
            my_swap(a, ++less, left++);}
        else if(a[left] == a[right]){
            left++;}
        else{
            my_swap(a, --more, left);
        }
    }
    my_swap(a, more, right);
    int* p = new int[2];
    p[0] = less + 1;
    p[1] = more;
    return p;
}


void quickSort(int* a, int left, int right){
    if(left < right){
        srand((int)time(0));
        my_swap(a, left+random(right-left+1), right);
        int *p = partition(a, left, right);
        quickSort(a, left, p[0]-1);
        quickSort(a, p[1]+1, right);
        if(p){
            delete[] p;
        }
    }
}


void QuickSort(int* a, int len){
    if(a == NULL || len < 2){
        return;
    }
    quickSort(a, 0, len-1);
}

int main()
{
    int a[5] = {4,7,1,2, 6};
    int len = sizeof(a)/sizeof(a[0]);
    QuickSort(a, len);
    for(int i = 0; i < len; i++){
        cout << a[i];
    }
    return 0;
}
