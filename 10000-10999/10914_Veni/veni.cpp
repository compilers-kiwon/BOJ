#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

#define NUM_OF_LETTERS  (26)

const string letters = "abcdefghijklmnopqrstuvwxyz";

#define get_idx(c)  ((int)letters.find((c)))
#define decode_two_chars(c1,c2,n) \
    (letters[(get_idx((c1))+get_idx((c2))+NUM_OF_LETTERS-(n))%NUM_OF_LETTERS])

#define is_odd_length(s)    ((s).length()%2==1)

int get_words(const string& str,
                vector<string>& result)
{
    string  cur;

    for (int i=0;i<str.length();i++) {
        if (str[i] == ' ') {
            if (is_odd_length(cur)) cur.pop_back();
            result.push_back(cur);cur.clear();
        } else {
            cur.push_back(str[i]);
        }
    }

    return  0;
}

int decode(string& result,int offset,
                    vector<string>& words)
{
    for (int i=0;i<words.size();i++) {
        string& cur = words[i];

        for (int j=0;j<cur.length();j+=2) {
            char    c1 = cur[j];
            char    c2 = cur[j+1];

            result.push_back(decode_two_chars(c1,c2,offset));
        }

        result.push_back(' ');
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int             n;
    string          str,decoded;
    vector<string>  words;

    getline(cin,str);
    n = stoi(str);

    getline(cin,str);
    str.push_back(' ');

    get_words(str,words);
    decode(decoded,n,words);

    cout<<decoded<<'\n';
    return  0;
}