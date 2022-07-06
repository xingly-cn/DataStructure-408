//
// 01.顺序表中删除最小值元素，并返回被删除的元素，空出的元素用最后一个元素填补，顺序表为空抛出异常
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

int del_min(SqList &list, int minValue) {
    if (list.length == 0) return -1;    // 顺序表为空报错
    minValue = sqList.data[0];
    int pos = 0;
    for (int i = 0 ; i < list.length ; i++) {   // 找到最小值的pos下标
        if (minValue >= list.data[i]) {
            minValue = list.data[i];
            pos = i;
        }
    }
    list.data[pos] = list.data[list.length - 1];    // 覆盖最小值
    list.length--;  // 不要忘记删除后长度减一
}

int main() {

    // 模拟数据
    add({5,4,1,2,3});

    cout << "原：";
    for (int i = 0 ; i < sqList.length ; i++) cout << sqList.data[i] << " ";

    int minValue;
    del_min(sqList, minValue);

    cout << endl << "删：";
    for (int i = 0 ; i < sqList.length ; i++) cout << sqList.data[i] << " ";

    return 0;
}