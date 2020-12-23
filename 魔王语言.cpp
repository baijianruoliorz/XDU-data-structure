
#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> t1;
    stack<char> t2;

    int flag = 0; //flag变量用来表示目前扫描指针是在括号内还是括号外
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == ')') {
            flag = 1;
            continue;
        }
        if (s[i] == '(') {
            flag = 0;
            char temp = t2.top(); //temp记录最后一个入栈的元素
            t1.push(temp);
            t2.pop();
            while (t2.empty() == false) {
                t1.push(t2.top());
                t2.pop();
                t1.push(temp);
            }
            continue;
        }
        if (flag == 1) { t2.push(s[i]); } else { t1.push(s[i]); }
    }
    while (!t1.empty()) {
        if (t1.top() == 'A') { cout << "sae"; }
        else if (t1.top() == 'B') {
            cout << "tsaedsae";
        }
        else { cout << t1.top(); }
        t1.pop();
    }
    return 0;
}