#include <iostream>
#include <string>

using namespace std;

string get_station_name(const string& str) {
    string ret;
    size_t sub_pos;

    if ((sub_pos = str.find('(')) == string::npos) {
        ret = str;
    } else {
        ret = str.substr(0, sub_pos);
    }

    return ret;
}

string get_sub_station_name(const string& str) {
    string ret;
    size_t sub_pos;

    if ((sub_pos = str.find('(')) == string::npos) {
        ret = "-";
    } else {
        for (size_t i = sub_pos + 1; str[i] != ')'; i++) {
            ret.push_back(str[i]);
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string str;
    getline(cin, str);

    cout << get_station_name(str) << '\n'
            << get_sub_station_name(str) << '\n';
    return 0;
}