#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        stack<string> str_stack;
        stack<int> num_stack;

        string cur_str = "";
        int cur_num = 0;
        for(char c:s) {
            if(isdigit(c)) {
                cur_num = cur_num * 10 + (c - '0');
            } else if(c == '[') {
                if(cur_num == 0) cur_num = 1;
                str_stack.push(cur_str);
                num_stack.push(cur_num);

                cur_str = "";
                cur_num = 0;
            } else if(c == ']') {
                int num = num_stack.top();
                num_stack.pop();

                string str = str_stack.top();
                str_stack.pop();

                string tmp = "";
                for(int i = 0; i < num; i++) {
                    tmp += cur_str;
                }

                cur_str = str + tmp;
            } else {
                cur_str += c;
            }
        }

        cout << cur_str << "\n";
    }
}

