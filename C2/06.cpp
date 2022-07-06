//
// 06.顺序表删除重复的元素, 即去重
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

bool delCommonValue(SqList &list) {
    //ToDo 408考试不允许使用STL, 后期会修改算法
    unordered_map<int,bool> q;
    int k = 0;
    for (int i = 0 ; i < list.length ; i++) {
        if (!q[list.data[i]]) { // 当前元素未出现过
            list.data[k++] = list.data[i];
            q[list.data[i]] = true;    // 标记出现了
        }
    }
    list.length = k;    // 更改长度
}

int main() {

    // 模拟数据
    add({1,2,3,3,2,5,3});

    cout << "原：";
    for (int i = 0 ; i < sqList.length ; i++) cout << sqList.data[i] << " ";

    delCommonValue(sqList);

    cout << endl << "删：";
    for (int i = 0 ; i < sqList.length ; i++) cout << sqList.data[i] << " ";

    return 0;
}