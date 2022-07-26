// 1.判断出栈序列是否合法
// Created by 方糖 on 2022/7/26.
//
#include "bits/stdc++.h"
using namespace std;

bool check(vector<int> a, vector<int> b) {
    stack<int> st;
    int j = 0, n = a.size();
    for (auto i : a) {
        st.push(i);
        while(!st.empty() && j < n && st.top() == b[j]) {
            st.pop();
            j++;
        }
    }
    return j == n;
}


int main() {

    switch (check({1,2,3,4}, {1,2,3,4})) {
        case true:
            cout << "序列合法";
            break;
        case false:
            cout << "序列非法";
    }

    return 0;
}
