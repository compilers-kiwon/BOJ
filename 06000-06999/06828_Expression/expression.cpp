#include <iostream>
#include <string>
#include <stack>

using namespace std;

void parse(const string& str, stack<string>& st) {
    string cur;

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == ' ') {
            st.push(cur);
            cur.clear();
        } else {
            cur.push_back(str[i]);
        }
    }
}

bool input(stack<string>& st) {
    string str;

    getline(cin, str);

    if (str == "0") {
        return false;
    }

    str.push_back(' ');
    parse(str, st);

    return true;
}

string simulate(stack<string>& prefix) {
    stack<string> postfix;

    for (; !prefix.empty(); prefix.pop()) {
        if (prefix.top() == "+" || prefix.top() == "-") {
            string op1, op2;

            op1 = postfix.top(); postfix.pop();
            op2 = postfix.top(); postfix.pop();
            postfix.push(op1 + op2 + prefix.top());
        } else {
            postfix.push(prefix.top());
        }
    }
    
    string ret;

    for (int i = 0; i < postfix.top().length(); ++i) {
        ret.push_back((postfix.top())[i]);
        ret.push_back(' ');
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        stack<string> in;

        if (input(in) == false) {
            break;
        }

        cout << simulate(in) << '\n';
    }

    return 0;
}