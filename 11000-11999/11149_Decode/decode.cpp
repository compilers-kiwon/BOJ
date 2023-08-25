#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

#define MOD(n)  ((n)%27)

const string decoded = "abcdefghijklmnopqrstuvwxyz ";

int get_value(const string& word)
{
    int ret = 0;

    for (int i=0;i<word.length();i++) {
        ret += decoded.find(word[i]);
    }

    return  MOD(ret);
}

int get_word_values(const string& str,
                        vector<int>& result)
{
    string  w;

    for (int i=0;i<str.length();i++) {
        char    c = str[i];

        if (c != ' ') w.push_back(c);
        else {result.push_back(get_value(w));w.clear();}
    }

    return  0;
}

int print(const vector<int>& word_values)
{
    for (int i=0;i<word_values.size();i++) {
        cout<<decoded[word_values[i]];
    }

    cout<<'\n';
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     T;
    string  in;

    getline(cin,in);
    T = stoi(in);

    for (int i=1;i<=T;i++) {
        vector<int> values;

        getline(cin,in);
        in.push_back(' ');

        get_word_values(in,values);
        print(values);
    }

    return  0;
}