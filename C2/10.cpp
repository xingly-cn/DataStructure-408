// 10.n个整数放入数组R中, 将R的元素循环左移p个位置
// Created by 方糖 on 2022/7/19.
//
#include "bits/stdc++.h"
using namespace std;

int a[6] = {1,2,3,4,5,6};
int n = 6;  // 答题中只需要n即可, 我这里运行代码需要给定一个具体的n

void Converse (int (&a)[6], int p) {
    int b[p];
    for (int i = 0 ; i < p ; i++) { // 将前p个元素保存在b数组里
        b[i] = a[i];
    }
    for (int i = 0 ; i < n - p ; i++) a[i] = a[i + p];  // 将p后面的元素左移
    for (int i = n - p , j = 0; j < p ; i++, j++) {     // 将数组b的元素放在R的后续单元里
        a[i] = b[j];
    }
}

int main() {

    cout << "原：";
    for (auto i : a) cout << i << " ";

    Converse(a, 2);

    cout << endl << "移：";
    for (auto i : a) cout << i << " ";

    return 0;
}