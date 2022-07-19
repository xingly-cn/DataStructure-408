//
// 09.线性表元素递增, 用最少时间找x, 找到则与他后面一个元素交换, 否则插入表仍使表递增
// Created by 方糖 on 2022/7/6.
//
#include "bits/stdc++.h"
using namespace std;

int A[100] = {1, 2, 4, 4, 5};
int n = 5;  // 本次模拟数据是5个, 所以这里是5 （考试中无需关心此变量, 直接给出即可）

void SearchChangeInsert(int *A, int x) {
    int left = 0, right = n - 1, mid = 0;
    while(left <= right) {     // 二分查找x
        mid = (left + right) >> 1;
        if (A[mid] == x) break;
        else if (A[mid] > x) right = mid - 1;
        else left = mid + 1;
    }
    if (A[mid] == x && mid != n - 1) {      // 只有mid不为最后一个元素, 才与后一个元素替换
        int t = A[mid]; A[mid] = A[mid + 1]; A[mid + 1] = t;
    }
    // 因为如果 A[mid] == x, 说明严格 left <= right , 如果 left > right 说明没找到哦啊
    if (left > right) {
        for (int k = n - 1 ; k >= left; k--) {    // 大于x的部分后移, 此时i停止的位置就是大于x的第一个位置
            A[k + 1] = A[k];
        }
        A[left] = x;
        n++;
    }
}

int main() {

    cout << "原：";
    for (int i = 0 ; i < n ; i++) cout << A[i] << " ";

    SearchChangeInsert(A, 3);   // 这里x改成就是插入的操作

    cout << endl << "改：";
    for (int i = 0 ; i < n ; i++) cout << A[i] << " ";

    return 0;
}