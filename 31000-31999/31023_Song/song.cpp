#include    <iostream>
#include    <string>
#include    <vector>
#include    <set>

using namespace std;

const static int THRESHOLD = 75;
const static string HIT_SONG = "It's a hit!";
const static string NOT_HIT_SONG = "Delete immediately!";

static inline bool reach_threshold(int cnt,int total,int threshold) {
    return  (100*cnt >= threshold*total);
}

string to_lower_str(const string& s)
{
    string ret;

    for (int i=0;i<s.length();i++) {
        ret.push_back(tolower(s[i]));
    }

    return  ret;
}

void get_pleasant_words(set<string>& w)
{
    int P;

    cin>>P;

    for (int i=1;i<=P;i++) {
        string s;
        cin>>s;
        w.insert(to_lower_str(s));
    }
}

void get_words_in_lyrics(vector<string>& w)
{
    int L;

    cin>>L;getchar();

    for (int i=1;i<=L;i++) {
        string cur,line;

        getline(cin,line);
        line.push_back(' ');

        for (int i=0;i<line.length();i++) {
            char c = line[i];

            if (isalpha(c) != 0) {
                cur.push_back(c);
            } else {
                if (cur.empty()) continue;
                w.push_back(to_lower_str(cur));
                cur.clear();
            }
        }
    }
}

int compare_words(const vector<string>& lyrics,const set<string>& words)
{
    int ret = 0;

    for (int i=0;i<lyrics.size();i++) {
        ret += (words.find(lyrics[i])!=words.end()?1:0);
    }

    return  ret;
}

bool analyze_lyrics(const set<string>& w)
{
    int cnt;
    vector<string> words;

    get_words_in_lyrics(words);
    cnt = compare_words(words,w);

    return  reach_threshold(cnt,words.size(),THRESHOLD);
}

int main(void)
{
    int N;

    cin>>N;

    for (int i=1;i<=N;i++) {
        set<string> pleasant;
        vector<string> lyrics;

        get_pleasant_words(pleasant);
        cout<<(analyze_lyrics(pleasant)?HIT_SONG:NOT_HIT_SONG)<<'\n';
    }

    return  0;
}