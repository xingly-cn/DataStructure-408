//
// 03.长度n的线性表L,删除所有为x的值，时间复杂度n空间复杂度1
// Created by 方糖 on 2022/7/6.
//
#include "bits/stdc++.h"
using namespace std;
struct SqList{
    int data[100];
    int maxsize,length;
}sqList;

void add(vector<int> num) {
    for (auto i : num) {
        sqList.data[sqList.length++] = i;
    }
}

void deleteValueAll(SqList &L, int x) {
    int k = 0;  // 记录顺序表元素个数
    for (int i = 0 ; i < L.length ; i++) {
        if (L.data[i] != x) {   // 当前值不是x时, 覆盖第k个数据
            L.data[k++] = L.data[i];
        }
    }
    L.length = k;   // 更改长度
}

int main() {

    // 模拟数据
    add({1,2,3,4,3,5,3,6,3,3});

    cout << "原：";
    for (int i = 0 ; i < sqList.length ; i++) cout << sqList.data[i] << " ";

    deleteValueAll(sqList, 3);

    cout << endl << "删：";
    for (int i = 0 ; i < sqList.length ; i++) cout << sqList.data[i] << " ";

    return 0;
}