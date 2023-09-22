#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

int get_words(const string& sentence,
                    vector<string>& words)
{
    string  cur;

    for (int i=0;i<sentence.length();i++) {
        if (sentence[i] == ' ') {
            words.push_back(cur);
            cur.clear();
        } else {
            cur.push_back(sentence[i]);
        }
    }

    return  0;
}

int get_num_of_angry(const vector<string>& words)
{
    int ret = 0;

    for (int i=0;i<words.size();i++) {
        if (words[i]=="u" || words[i]=="ur") {
            ret++;
        }

        if ((words[i]=="would" || words[i]=="should") 
                && words[i+1]=="of") {
            ret++;
        }

        if (words[i].find("lol") != string::npos) {
            ret++;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  s;

    getline(cin,s);

    for (int i=1;i<=stoi(s);i++) {
        int num_of_angry;
        string str;
        vector<string>  words;

        getline(cin,str);
        str.push_back(' ');

        get_words(str,words);
        words.push_back("");

        num_of_angry = get_num_of_angry(words);
        cout<<num_of_angry*10<<'\n';
    }

    return  0;
}