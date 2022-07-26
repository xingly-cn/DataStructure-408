// 2.栈应用 - 括号匹配
// Created by 方糖 on 2022/7/26.
//
#include "bits/stdc++.h"
using namespace std;

bool check(vector<char> r, int n) {
    stack<char> st;
    for (int i = 0 ; i < n ; i++) {
        if (r[i] == '[' || r[i] == '(') st.push(r[i]);
        else {
            if (st.empty()) return false;
            if (r[i] == ')') {
                if (st.top() == '(') st.pop();
                else return false;
            }
            if (r[i] == ']') {
                if (st.top() == '[') st.pop();
                else return false;
            }
        }
    }
    return true;
}

int main() {

    cout << check({'[','[',']','(',')',']'}, 6) << endl;
    cout << check({'[','[',')','(',')',']'}, 6);

    return 0;
}

