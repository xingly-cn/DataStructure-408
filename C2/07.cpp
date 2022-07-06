//
// 07.合并两个有序的顺序表
// Created by 方糖 on 2022/7/6.
//
#include "bits/stdc++.h"
using namespace std;
struct SqList{
    int data[100];
    int length;
    int maxsize = 100;  // 临时增加顺序表最大长度, 前面题目不需要故没有添加
}sqList1, sqList2, sqList3;

void add(SqList &list, vector<int> num) {
    for (auto i : num) {
        list.data[list.length++] = i;
    }
    list.maxsize = 100;
}

bool mergeTwoList(SqList &listA, SqList &listB, SqList &listC) {
    if (listA.length + listB.length > listC.maxsize) {  // 合并后超出顺序表最大长度报错
        return false;
    }
    int i = 0, j = 0, k = 0;
    while(i < listA.length && j < listB.length) {   // 轮流把最小的插入c表
        if (listA.data[i] <= listB.data[j]) {
            listC.data[k++] = listA.data[i++];
        }else {
            listC.data[k++] = listB.data[j++];
        }
    }
    // 如果有链表还没跑完, 将剩余的元素插到c表后面
    while(i < listA.length) listC.data[k++] = listA.data[i++];
    while(j < listB.length) listC.data[k++] = listB.data[j++];
    listC.length = k;   // 修改长度
    return true;
}

int main() {

    // 模拟数据
    add(sqList1,{1,2,3,5});
    add(sqList2,{1,3,4,6});

    cout << "listA：";
    for (int i = 0 ; i < sqList1.length ; i++) cout << sqList1.data[i] << " ";
    cout << endl << "listB：";
    for (int i = 0 ; i < sqList2.length ; i++) cout << sqList2.data[i] << " ";

    mergeTwoList(sqList1, sqList2, sqList3);

    cout << endl << "合：";
    for (int i = 0 ; i < sqList3.length ; i++) cout << sqList3.data[i] << " ";

    return 0;
}