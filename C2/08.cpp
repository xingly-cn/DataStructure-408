//
// 08.A[m+n]中保存了两个线性表,a和b, 现在要求更换a和b的顺序
// Created by 方糖 on 2022/7/6.
//
#include "bits/stdc++.h"
using namespace std;

void reverseArray(int *A, int left, int right, int arraySize) {     // 翻转数组A 中 [left,right) 的数据
    if (left >= right || right >= arraySize) {  // 范围越界结束
        return ;
    }
    int i = left, j = right - 1;
    while(i < j) {
        int t = A[i];
        A[i] = A[j];
        A[j] = t;
        i++, j--;
    }
}

void changePosition(int *A, int m, int n, int arraySize) {
    reverseArray(A, 0, n + m, arraySize);       // 翻转整个数组
    reverseArray(A, 0, n, arraySize);           // 翻转b表的n个元素
    reverseArray(A, n, n + m, arraySize);       // 翻转a表的m个元素
}

int main() {

    // 模拟数据
    int A[100] = {1, 2, 3, 4, 5}, m = 3 , n = 2;
    int arraySize = 5;  // 本次模拟数据是5个, 所以这里是5 （考试中无需关心此变量, 直接给出即可）

    cout << "原：";
    for (int i = 0 ; i < arraySize ; i++) cout << A[i] << " ";

    changePosition(A, m, n, 5);

    cout << endl << "改：";
    for (int i = 0 ; i < arraySize ; i++) cout << A[i] << " ";

    return 0;
}