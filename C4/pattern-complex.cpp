// 1. 暴力模式匹配算法
// Created by 方糖 on 2022/7/29.
//
#include "bits/stdc++.h"
using namespace std;

int getIndex(string s, string p) {
    int i = 0, j = 0;
    while(i < s.length() && j < p.length()) {
        if (s[i] == p[j]) i++,j++;
        else {
            i = i - j + 2;
            j = 0;
        }
    }
    if (j >= p.length()) return i - p.length();
    return 0;
}

int main() {

    cout << getIndex("abcsajdhaj", "ajd");

    return 0;
}
