#include    <iostream>
#include    <string>
#include    <map>
#include    <algorithm>

using namespace std;

const static int MAX_SIZE = 0x100;

static bool single_char_words[MAX_SIZE];
static map<string,int>  words[MAX_SIZE][MAX_SIZE];

static inline void get_int(int& n) {
    string  buf;
    getline(cin,buf);
    n = stoi(buf);
}

static inline void get_str(string& s) {
    getline(cin,s);
}

static inline void remove_head(string& s) {
    s.erase(0,1);
}

static inline void remove_tail(string& s) {
    s.pop_back();
}

static inline void get_idx(string& s,char& h,char& t) {
    h=s.front();t=s.back();
    remove_tail(s);remove_head(s);
    if (s.length()>1) sort(s.begin(),s.end());
}

void get_words(void)
{
    int N;
    
    get_int(N);

    for (int i=1;i<=N;i++) {
        string  w;
        char    h,t;

        get_str(w);

        if (w.length() == 1) {
            single_char_words[w.front()] = true;
            continue;
        } 

        get_idx(w,h,t);
        words[h][t][w]++;
    }
}

int get_num_of_similar_words(string& w)
{
    if (w.length() == 1) {
        return  (single_char_words[w.front()]?1:0);
    }

    char    h,t;
    get_idx(w,h,t);
    return  words[h][t][w];
}

int interpret_sentence(const string& s)
{
    int ret = 1;
    int num_of_interpretable = 0;
    string  w;

    for (int i=0;i<s.length();i++) {
        if (s[i] != ' ') {
            w.push_back(s[i]);
            continue;
        }

        int n = get_num_of_similar_words(w);

        if (n == 0) n=1;
        else num_of_interpretable++;

        ret *= n;
        w.clear();
    }

    return  (num_of_interpretable!=0)?ret:0;
}

void remove_spaces(string& str)
{
    for (;!str.empty()&&str.back()==' ';remove_tail(str));
    for (;!str.empty()&&str.front()==' ';remove_head(str));
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int M;

    get_words();
    get_int(M);

    for (int i=1;i<=M;i++) {
        string  str;

        get_str(str);
        remove_spaces(str);

        str.push_back(' ');
        cout<<interpret_sentence(str)<<'\n';
    }

    return  0;
}