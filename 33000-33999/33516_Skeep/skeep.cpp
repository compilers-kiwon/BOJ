#include <iostream>
#include <string>

using namespace std;

int N, cnt;
string str;

const size_t MY_STR_LEN = 5;
const string MY_STR1 = "skeep";
const string MY_STR2 = "s____";
const char CONVERTED = '_';

bool compare_str(const string& str) {
    for (size_t i = 0; i < MY_STR_LEN; i++) {
        if (str[i] != MY_STR1[i] && str[i] != MY_STR2[i]) {
            return false;
        }
    }

    return true;
}

void find_str(string& cur, char c) {
    cur.push_back(c);

    if (cur.length() < MY_STR_LEN) {
        return;
    }

    size_t pos = cur.length() - MY_STR_LEN;
    string sub = cur.substr(pos);

    if (compare_str(sub)) {
        cnt++;
        cur.erase(pos);
        find_str(cur, CONVERTED);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string tmp;

    cin>>N>>str;

    for (size_t i = 0; i < str.length(); i++) {
        find_str(tmp, str[i]);
    }

    cout<<cnt<<'\n';
    return 0;
}