#include    <iostream>
#include    <string>
#include    <set>
#include    <algorithm>

using namespace std;

static set<string>  subs;

#define reverse_head_and_play_game(s,from,h_len,t_len)   \
    {reverse(&(s)[(from)],&(s)[(from)+(h_len)]);\
     play((s),(from)+(h_len),(t_len));\
     reverse(&(s)[(from)],&(s)[(from)+(h_len)]);}

#define reverse_tail_and_play_game(s,from,h_len,t_len)   \
    {reverse(&(s)[(from)+(h_len)],&(s)[(from)+(h_len)+(t_len)]);\
     play((s),(from),(h_len));\
     reverse(&(s)[(from)+(h_len)],&(s)[(from)+(h_len)+(t_len)]);}

#define TRUE    1
#define FALSE   0

bool compare_num_of_chrs(int cnt1[],int cnt2[])
{
    for (char c='a';c<='z';c++) {
        if (cnt1[c] != cnt2[c]) return false;
    }
    return  true;
}

int play(string& str,int from,int len)
{
    if (len == 1) {
        subs.insert(str);
        return  0;
    }

    int     head_len,tail_len;

    head_len = len/2;
    tail_len = len-head_len;

    reverse_head_and_play_game(str,from,head_len,tail_len);
    reverse_tail_and_play_game(str,from,head_len,tail_len);

    if (len%2 == 0) return 0;

    head_len = len/2+1;
    tail_len = len-head_len;

    reverse_head_and_play_game(str,from,head_len,tail_len);
    reverse_tail_and_play_game(str,from,head_len,tail_len);

    return  0;
}

int count_chrs(const string& str,int cnt[])
{
    for (int i=0;i<str.length();i++) cnt[str[i]]++;
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,cnt[0x100],len;
    string  str;

    cin>>N;

    len = 0;
    fill(&cnt['a'],&cnt['z'+1],0);

    for (int i=1;i<=N;i++) {
        char    c;
        int     M;

        cin>>c>>M;
        cnt[c] = M;
        len += M;
    }

    cin>>str;

    for (int i=0;i+len<=str.length();i++) {
        int     cur[0x100] = {0,};
        string  s = str.substr(i,len);

        count_chrs(s,cur);
        if (compare_num_of_chrs(cnt,cur)) play(s,0,len);
    }

    cout<<subs.size()<<'\n';
    return  0;
}