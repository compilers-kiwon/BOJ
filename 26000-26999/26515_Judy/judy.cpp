#include <iostream>
#include <string>
#include <vector>

using namespace std;

void parse_numbers(const string& str,
                    vector<int>& numbers) {
    string cur;

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == ' ') {
            numbers.push_back(min(stoi(cur), 0xFF));
            cur.clear();
        } else {
            cur.push_back(str[i]);
        }
    }
}

string get_ascii_letters(const vector<int>& numbers) {
    string ret;

    for (int i = 0; i < numbers.size(); ++i) {
        char c = '-';

        if (isalpha(numbers[i])) {
            c = tolower(numbers[i]);
        }

        ret.push_back(c);
    }

    return ret;
}

string use_pig_latin(const string str) {
    string ret = str.substr(1);
    
    ret.push_back(str.front());
    ret += "ay";

    return ret;
}

int main(void) {
    int n;

    cin >> n; getchar();

    for (int i = 1; i <= n; ++i) {
        string s;
        vector<int> num;

        getline(cin, s);
        s.push_back(' ');

        parse_numbers(s, num);
        cout << use_pig_latin(get_ascii_letters(num)) << '\n';
    }

    return 0;
}