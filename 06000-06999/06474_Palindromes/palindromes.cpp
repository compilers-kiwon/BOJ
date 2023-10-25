#include    <iostream>
#include    <string>
#include    <algorithm>

using namespace std;

const static string result_str[] = {
    "is not a palindrome.",
    "is a palindrome.",
    "is a mirrored string.",
    "is a mirrored palindrome."
};

static char reverse_chr[0x100];

int init(void)
{
    reverse_chr['A'] = 'A';
    reverse_chr['E'] = '3';
    reverse_chr['H'] = 'H';
    reverse_chr['I'] = 'I';
    reverse_chr['J'] = 'L';
    reverse_chr['L'] = 'J';
    reverse_chr['M'] = 'M';
    reverse_chr['O'] = 'O';
    reverse_chr['S'] = '2';
    reverse_chr['T'] = 'T';
    reverse_chr['U'] = 'U';
    reverse_chr['V'] = 'V';
    reverse_chr['W'] = 'W';
    reverse_chr['X'] = 'X';
    reverse_chr['Y'] = 'Y';
    reverse_chr['Z'] = '5';
    reverse_chr['1'] = '1';
    reverse_chr['2'] = 'S';
    reverse_chr['3'] = 'E';
    reverse_chr['5'] = 'Z';
    reverse_chr['8'] = '8';

    return  0;
}

int is_palindrome(const string& str)
{
    for (int h=0,t=str.length()-1;h<t;h++,t--) {
        if (str[h] != str[t]) return 0;
    }

    return  1;
}

int is_mirrored(const string& str)
{
    string  m;

    for (int i=0;i<str.length();i++) {
        if (reverse_chr[str[i]] == 0) return 0;
        m.push_back(reverse_chr[str[i]]);
    }

    reverse(m.begin(),m.end());
    return  (str==m?1:0);
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (init();;) {
        string  str;
        int     result;

        cin>>str;
        if (str.empty()) break;

        result = (is_palindrome(str)<<0)+(is_mirrored(str)<<1);
        cout<<str<<" -- "<<result_str[result]<<"\n\n";
    }

    return  0;
}