//
// Created by 方糖 on 2022/7/17.
//
#include "bits/stdc++.h"
using namespace std;

struct SqList {
    int data[50];
    int length = 0;
}List;

bool insert(SqList &list, int i, int x) {
    if (i < 1 || i > list.length + 1) return false;
    if (list.length >= 50) return false;
    for (int j = list.length ; j >= i ; j--) list.data[j] = list.data[j] = list.data[j - 1];
    list.data[i - 1] = x;
    list.length ++;
    return true;
}

int find(SqList list, int x) {
    for (int i = 0 ; i < list.length ; i++) {
        if (list.data[i] == x) return i + 1;
    }
    return 0;
}

bool del(SqList &list, int i, int &x) {
    if (i < 1 || i > list.length + 1) return false;
    x = list.data[i - 1];
    for (int j = i ; j < list.length ; j++) list.data[j - 1] = list.data[j];
    list.length--;
    return true;
}

int main() {

    insert(List, 1, 1);
    insert(List, 2, 2);
    insert(List, 3, 3);
    insert(List, 2, 4);

    int x = 0;
    del(List,3, x);

    for (int i = 0 ; i < List.length ; i++) cout << List.data[i];


    cout << find(List, 4) << endl;

    return 0;
}