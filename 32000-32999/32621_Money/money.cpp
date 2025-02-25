#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int NONE = 0;
const int NUM_OF_NUMBERS = 2;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void get_numbers(const string& s, vector<string>& n) {
    string num;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '+') {
            n.push_back(num);
            num.clear();
        } else {
            num.push_back(s[i]);
        }
    }
}

int parse_num(const string& s) {
    int ret = 0;

    if (s.empty()) {
        return NONE;
    }

    if (s.front() == '0') {
        return NONE;
    }

    for (int i = 0; i < s.length(); i++) {
        if (!IN_RANGE('0', s[i], '9')) {
            return NONE;
        }

        ret = ret*10 + (int)(s[i]-'0');
    }

    return ret;
}

bool is_cute(int n1, int n2) {
    return ((n1 != NONE) && (n1 == n2));
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    string s;
    vector<string> n;

    cin>>s;
    s.push_back('+');
    
    get_numbers(s, n);
    
    if(n.size() == NUM_OF_NUMBERS &&
        is_cute(parse_num(n.front()), parse_num(n.back())) == true) {
        cout<<"CUTE\n";
    } else {
        cout<<"No Money\n";
    }

    return 0;
}