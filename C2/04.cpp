//
// 04.删除值在s,t之间的元素，s,t不合理或表空抛出异常
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

bool deleteBetweenST(SqList &list, int s, int t) {
    if (list.length == 0 || s >= t) {  // 表空或st违法抛出
        return false;
    }
    int k = 0;      // 本题与03思路相同, 只是这题是按照范围删除, 上题是按照值
    for (int i = 0 ; i < list.length ; i++) {
        if (list.data[i] <= s || list.data[i] >= t) {   // 不在st之间的元素, 覆盖第k个数据
            list.data[k++] = list.data[i];
        }
    }
    list.length = k;    // 修改长度
}

int main() {

    // 模拟数据
    add({1,2,3,4,5,6});

    cout << "原：";
    for (int i = 0 ; i < sqList.length ; i++) cout << sqList.data[i] << " ";

    deleteBetweenST(sqList, 3,6);

    cout << endl << "删：";
    for (int i = 0 ; i < sqList.length ; i++) cout << sqList.data[i] << " ";

    return 0;
}