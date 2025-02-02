#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

static map<char, char> translation_table = {
    {'a', 'a'}, {'b', 'b'}, {'k', 'c'}, {'d', 'd'}, {'e', 'e'},
    {'g', 'f'}, {'h', 'g'}, {'i', 'h'}, {'l', 'i'}, {'m', 'j'},
    {'n', 'k'}, {'o', 'm'}, {'p', 'n'}, {'r', 'o'}, {'s', 'p'},
    {'t', 'q'}, {'u', 'r'}, {'w', 's'}, {'y', 't'}
};

typedef pair<string, string> Word;

void translate(Word& w) {
    string& src = w.second;
    string& dst = w.first;

    for (int i = 0; i < src.length() - 1; i++) {
        const char c1 = src[i+0];
        const char c2 = src[i+1];

        if (c1 == 'n' && c2 == 'g') {
            dst.push_back('l');
            i++;
            continue;
        }

        dst.push_back(translation_table[c1]);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    vector<Word> dic;

    cin>>N;

    for (int i = 1; i <= N; i++) {
        Word w;

        cin>>w.second;
        w.second.push_back(' ');

        translate(w);
        
        w.second.pop_back();
        dic.push_back(w);
    }

    sort(dic.begin(), dic.end());

    for (int i = 0; i < dic.size(); i++) {
        cout<<dic[i].second<<'\n';
    }

    return 0;
}