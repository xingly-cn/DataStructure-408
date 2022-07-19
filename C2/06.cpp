//
// 06.顺序表删除重复的元素, 即去重
// Created by 方糖 on 2022/7/6.
//
#include "bits/stdc++.h"
using namespace std;
struct SqList{
    int data[100];
    int length;
}sqList;

void add(vector<int> num) {
    for (auto i : num) {
        sqList.data[sqList.length++] = i;
    }
}

bool delCommonValue(SqList &list) {
    if (list.length == 0) return false;
    int t = list.data[0];
    int k = 1;
    for (int i = 1 ; i < list.length ; i++) {
        while (i < list.length && list.data[i] == t) i++;
        list.data[k++] = list.data[i];  // 与 t 不同的元素赋值给 第 k 位
        t = list.data[i];
    }
    list.length = k - 1;
}

int main() {

    // 模拟数据
    add({1,2,2,3,3,3});

    cout << "原：";
    for (int i = 0 ; i < sqList.length ; i++) cout << sqList.data[i] << " ";

    delCommonValue(sqList);

    cout << endl << "删：";
    for (int i = 0 ; i < sqList.length ; i++) cout << sqList.data[i] << " ";

    return 0;
}