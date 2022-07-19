// 11.找出数组A, 数组B合在一起的中位数
// Created by 方糖 on 2022/7/19.
//
#include "bits/stdc++.h"
using namespace std;

int a[5] = {11,13,15,17,19};
int b[5] = {2,4,6,8,20};
int n = 5;
// 1 1 2 2 3 4 4 4 5 5 中位数：3.5


int FindMid (int a[], int b[], int n) {
    int c[2 * n];
    int i = 0, j = 0, k = 0;
    // 此题类似第7题, 由于两个数组是升序, 故将其合并为一个数组, 取其中位数就十分简单了
    while (i < n && j < n) {
        if (a[i] <= b[j]) c[k++] = a[i++];
        else c[k++] = b[j++];
    }
    while (i < n) c[k++] = a[i++];
    while (j < n) c[k++] = b[j++];
    return (c[2 * n / 2 - 1] + c[2 * n / 2]) / 2;   // 两个数组长度相同, 故必是偶数, 故中位数是中间两个平均数
}

int main() {


    cout << FindMid(a, b, n);


    return 0;
}