#include    <iostream>
#include    <string>

using namespace std;

const static string PREFIX = "io";
const int MIN_LENGTH = 3;
const int NUMBER_POS = 2;

static inline bool isnumber(const string& str) {
    for (int i=0;i<str.length();i++) {
        if (!isdigit(str[i])) return false;
    }

    return  true;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  s;

    cin>>s;

    if (s.length()<MIN_LENGTH ||
        s.substr(0,PREFIX.length())!=PREFIX ||
        isnumber(s.substr(NUMBER_POS))!=true) {
        cout<<"Incorrect\n";
    } else {
        cout<<"Correct\n";
    }

    return  0;
}