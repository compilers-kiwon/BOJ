#include    <iostream>
#include    <string>

using namespace std;

const static int MAX_SIZE = 1000000+1;

static string required[MAX_SIZE];

static inline void analyze_word(const string& str,int pos)
{
    string& s = required[pos];
    bool    checked[0x100] = {false,};

    for (int i=0;i<str.length();i++) {
        if (checked[str[i]] == false) {
            checked[str[i]] = true;
            s.push_back(str[i]);
        }
    }
}

static inline void input(int& num_of_words,bool used[])
{
    cin>>num_of_words;

    for (int i=1;i<=num_of_words;i++) {
        string  w;
        cin>>w;

        used[w[0]] = true;
        analyze_word(w,i);
    }
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N;
    bool    table[0x100] = {false,};

    input(N,table);

    for (int i=1;i<=N;i++) {
        string& s = required[i];
        bool    found = true;

        for (int j=0;j<s.length();j++) {
            if (table[s[j]] == false) {
                found = false;
                break;
            }
        }

        if (found == true) {
            cout<<"Y\n";
            return  0;
        }
    }

    cout<<"N\n";
    return  0;
}