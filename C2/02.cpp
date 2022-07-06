//
// 02.将顺序表元素翻转，要求空间复杂度为O(1) - 题目的意思就是不使用额外空间，原地翻转
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

void reverseList(SqList &list) {
    int i = 0, j = list.length - 1;
    while(i < j) {  // 双指针，首尾数据互换
        int t = list.data[i];
        list.data[i] = list.data[j];
        list.data[j] = t;
        i++, j--;
    }
}

int main() {

    // 模拟数据
    add({5,4,3,2,1});

    cout << "原：";
    for (int i = 0 ; i < sqList.length ; i++) cout << sqList.data[i] << " ";

    reverseList(sqList);

    cout << endl << "反：";
    for (int i = 0 ; i < sqList.length ; i++) cout << sqList.data[i] << " ";

    return 0;
}